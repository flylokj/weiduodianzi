#include "machinestat.h"
#include <QTimer>
#include <QList>
#include <QtAlgorithms>
#include "lineuint.h"
#include "Communication/LogicThread.h"
#include "iomodule.h"
#include "buglecompensation.h"


#define _USE_MATH_DEFINES
#include <math.h>

//上位机PC梯度控制超时时间5s，改2s
#define  GRADIENTPCTIMEOUT 2

//上位机时间同步单位0.01min = 0.6s;
#define SYNC_TIME_UNIT		0.6

//压力数据池大小;
#define PRESS_POLL_SIZE		10

#define SERIAL_MAX		9999999999
#define SERIAL_NUM_KEY	19900208
#define SERIAL_NUM_VAL	345192069

//非法初始化值;
#define FLOW_INVALID	99999999

#define SERIAL_MAX		9999999999
#define SERIAL_NUM_KEY	19900208
#define SERIAL_NUM_VAL	345192069
#define ACTIVE_CODE_TRY	9000000000
#define ACTIVE_CODE_MAX 999999999
#define ACTIVE_MASK		0x12345678


#include "baseMainPage.h"
extern BaseMainPage *g_pMainWindow;

//报警;
bool bWarn=false;
double overFlow;
double overPress;
bool bOverPress = false;//压力报警标志


/////////////////////////////////////////////////////////
//
//功能：十进制转BCD码
//
//输入：int Dec                      待转换的十进制数据
//      int length                   BCD码数据长度
//
//输出：unsigned char *Bcd           转换后的BCD码
//
//返回：0  success
//
//思路：原理同BCD码转十进制
//
//////////////////////////////////////////////////////////
int DectoBCD(int Dec,int length)
{
	int ret = 0;
	for(int i = 0; i < length/2; i++)
	{
		int temp = Dec % 100;
		temp = ((temp/10)<<4) | ((temp%10)&0xff);
		temp = temp << i*8;
		ret |= temp;
		Dec/=100;
	}
	return ret;
}


MachineStat::MachineStat(QObject *parent)
	: QObject(parent)
	, m_dCurrentflowValInPc(-1)
	, m_dFlowPercent(0)
	, m_nCurrentPressRawCode(0)
	, m_sCurrentPressVal("0")
	, m_bPcGradientCtrl(false)
	, m_nPcGradientCtrlFlag(0)
	, m_bBugleFlag(false)
	, m_nFlowCtrlWord(FLOW_INVALID)
	, m_nCurrentPercent(100000)
{
	pDb = DataBase::getInstance();
	initIO();
	initTimeoutList();
	initTimer();
	initCommunication();
	initMachineStat();
	serialNumberGenerate();
	initIPAddr();

	//test
	//checkPressOverloaded(1000);
}

MachineStat::~MachineStat()
{
	releaseTimeoutList();
}

MachineStat * MachineStat::getInstance()
{
	static MachineStat *pStat = new MachineStat();
	return pStat;
}

#define ISNOT_MACHINE_STAT(stat)	(stat<STOP||stat>PCCTRL)	
void MachineStat::setMachineStat(MachineStatment stat, bool recover)
{
	if(ISNOT_MACHINE_STAT(stat))
		return;

	if(!recover)//如果不覆盖之前状态;
	{
		if(stat == m_machineStat.machineStat)			//检查状态是否发生变化;
			return;

		storeOldStat(stat);//备份先前状态;
		emit(machineStatChanged(stat));
	}
	
	if(stat == STOP)//停止电机转动;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}

		stopMachine();
	}
	else if(stat == PAUSE)//暂停;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}

		pauseMachine();
	}
	else if(stat == RUNNING)//运行;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}
		
		startMachine();
	}
	else if(stat == PUMP)//泵液;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}

		pumpMachine();
	}
	else if(stat == PURGE)//清洗;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}

		purgeMachine();
	}
	else if(stat == PCCTRL)//上位机流速;
	{
		if(bOverPress)
		{
			bOverPress = false;
			sysError(OVERPRESS_ERR, false);//取消报警;
		}

		pcCtrlMachine();
	}
}

void MachineStat::timeoutFunc()
{
	//机器处于运行、泵液、清洗状态;
	for (QList<LPTimeOutStruct>::iterator it = m_timeoutList.begin(); it!=m_timeoutList.end(); it++)
	{
		LPTimeOutStruct pTimeout = *it;
		if(pTimeout->cnt++ >= pTimeout->timeout)
		{
			pTimeout->cnt = 0;
			(this->*pTimeout->timeoutFunc)();
		}

	}
}

void MachineStat::initIO()
{
	IoModule *pIo = IoModule::getInstance();
	connect(pIo, SIGNAL(bulge()), this, SLOT(dealBulge()));
	connect(pIo, SIGNAL(testPress(quint32)), this, SLOT(updatePresVal(quint32)) );
}


void MachineStat::initTimer()
{
	QTimer *pTimer = new QTimer(this);
	connect(pTimer, SIGNAL(timeout()), this, SLOT(timeoutFunc()));
	pTimer->start(1000);
}

void MachineStat::initMachineStat()
{
	m_machineStat.machineStat = STOP;											//开始、停止、清洗;
	m_machineStat.oldMachineStat = INISTAT;									//旧的机器状态;
	m_machineStat.startupTime = 0;											//开机时间
	//m_machineStat.sysUsedTime = pDb->queryData("usedTime").toInt();			//系统累计时间;
	m_machineStat.pumpStartupTime = pDb->queryData("pumpUsedTime").toInt();	//泵累计启用时间;
	m_machineStat.bugleCnt = pDb->queryData("bugleCnt").toInt();			//栓塞使用次数（凸轮光电开关）
	m_machineStat.bTryDone = false;

	m_machineStat.m_bUpdateFlowFromPc = false;

	m_machineStat.m_dCurrentFlow = 0;

	//读取试用的当天日期;
	m_machineStat.m_firstTryDateTime = pDb->queryData("firstTryDateTime").toUInt();//记录开始试用的当天日期时间;
	if(m_machineStat.m_firstTryDateTime == 0)
	{
		clearUsedTime();
	}

	pumpTypeChanged();

	//凸轮补偿;
	//connect(BugleCompensation::getInstance(), SIGNAL(outputUpdate(quint32)), this, SLOT(updateFlowCtrl(quint32)) );
}

void MachineStat::clearTime(MachineTime time)
{
	if(time == SYSTIME)
		clearUsedTime();
		//clearStartupTime();
	else if(time == PUMPTIME)
		clearBugleCnt();
	else if(time == STARTUPTIME)
		clearStartupUsedTime();
}


void MachineStat::storeOldStat(MachineStatment stat)
{
	m_machineStat.oldMachineStat = m_machineStat.machineStat;//记录旧的机器状态;
	m_machineStat.machineStat = stat;
}


void MachineStat::stopMachine()
{
	disableUpdateFlow();
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_WAVEADD_MOTOR,0);
	setStartupTime(0);
	BugleCompensation::getInstance()->stopOutput();

	m_nFlowCtrlWord = FLOW_INVALID;//赋值一个非法的流速控制字;

	//恢复PUMP或PURGE的流速显示;
	updateFlowDisplay(DataBase::getInstance()->queryData("pumpPurgeFlowVal"));
}

void MachineStat::pauseMachine()
{
	disableUpdateFlow();
	BugleCompensation::getInstance()->pauseOutput();
}

void MachineStat::startMachine()
{
	enableUpdateFlow();
	int which = pDb->queryData("gradientTable").toInt();
	if(which != 12)
		pDb->readGradientTableIntoList(which);			//读取梯度表格到内存;
	clearStartupTime();

	if( m_machineStat.oldMachineStat == PAUSE )
		BugleCompensation::getInstance()->waitOutputStable();

	sysError(OVERPRESS_ERR, false);//取消报警;
}

void MachineStat::pumpMachine()
{
	enableUpdateFlow();
	//DataBase::getInstance()->readGradientTableIntoList(10);
	double flow = DataBase::getInstance()->queryData("pumpPurgeFlowVal").toDouble();
	updateFlow(flow, PUMP_PURGE_MODE);
	clearStartupTime();

	if( m_machineStat.oldMachineStat == PAUSE )
		BugleCompensation::getInstance()->waitOutputStable();
	
}

void MachineStat::clearStartupTime()
{
	if(m_machineStat.oldMachineStat != PAUSE)//如果之前不是停止状态，清零;
		setStartupTime(0);
}

void MachineStat::purgeMachine()
{
	enableUpdateFlow();
	//DataBase::getInstance()->readGradientTableIntoList(11);
	double flow = DataBase::getInstance()->queryData("pumpPurgeFlowVal").toDouble();
	updateFlow(flow, PUMP_PURGE_MODE);
	clearStartupTime();

	if( m_machineStat.oldMachineStat == PAUSE )
		BugleCompensation::getInstance()->waitOutputStable();
}

void MachineStat::pcCtrlMachine()
{
	//屏蔽上位机时间同步
	//判断是普通流速控制还是上位机梯度控制;
#if 0
	m_nPcGradientCtrlFlag = 0;
	if(m_dCurrentflowValInPc == 0)
	{
		m_bPcGradientCtrl = true;//PC控制;
	}
	else//普通流速控制;
		syncFlowFromPc();
#endif
	syncFlowFromPc();

	pDb->updateDate("gradientTable", "10");
	clearStartupTime();
}

#define CONTROL_WORD_FACTOR 6*(pow((double)2,32))/125000000/10


float MachineStat::GetWordFactor()
{
	int selectindex = DataBase::getInstance()->queryData("pumptype").toInt(); 
	float pumpMaxFlowArray[]={6,3.3,0.245,0.11,0.05,0.025,0.008333};
	if(selectindex>6)
	{
		selectindex=0;
	}
	return pumpMaxFlowArray[selectindex]*(pow((double)2,32))/125000000/10;

}

void MachineStat::updateFlow(double flow, MachineStat::FlowCtrlMode eFlowMod)
{
	//流速范围检测，超出最大值停机报警;
	switch(eFlowMod)
	{
		case GRADIENT_MODE:
			updateFlowInGradientMode(flow);
		break;
		case PUMP_PURGE_MODE:
			updateFlowInPumpPurgeMode(flow);
		break;
		case PC_MODE:
			updateFlowInPcMode(flow);
		break;
		case DEBUG_MODE:
			updateFlowInDebugMode(flow);
		break;
		default:
			return;
	}

	m_machineStat.m_dCurrentFlow = flow;
}


double MachineStat::compensationForFlowSecondary( double flow )
{
	quint32 elapse = 0;
	if(m_bBugleFlag)
	{
		elapse = bugleTime.elapsed();
		m_bBugleFlag = false;
	}

	double temp = (elapse/1000.0)*flow/1.666;
	temp = temp*2.0*M_PI;
	temp = sin(temp);
	temp = 0.1*temp + 1;
	temp *=flow;
	return temp;
}


quint32 MachineStat::compensationForFlow(double flow)
{ 
	QList<LineUint> &flowCompensationList = pDb->getFlowCompensationList();
	for (int i = 0; i<flowCompensationList.count(); i++)
	{
		const LineUint &line = flowCompensationList.at(i);
		if(line.inRange(flow))
		{
			double percent = line.getValueByXAndK(flow);//根据公式返回对应的流量值;
			percent = flow/percent;
			//percent = compensationForFlowSecondary(percent);
			return (percent/0.0001);
		}
	}
	return (flow/0.0001);
}


int MachineStat::checkProbation()
{
	quint32 probationDay = pDb->queryData("tryDay").toInt();			//试用天数;
	//qDebug()<<pDb->queryData("usedTime").toULong();
	//quint32 usedDay = pDb->queryData("usedTime").toULong()/60/60/24;	//已经试用时间;
	quint32 usedDay = getUsedTime()/60/60/24;

	qint32 temp = probationDay - usedDay;
	//temp = 3;
	if(temp <= 0)
	{
		m_machineStat.bTryDone = true;
		temp = 0;
	}
	else
		m_machineStat.bTryDone = false;

	return temp;
}

void MachineStat::saveUsedTime()
{
	//机器累计使用时间记录;
	/*quint32 usedTime = m_machineStat.sysUsedTime;
	QString temp = QString::number(usedTime);
	pDb->updateDate("usedTime", temp);*/

	quint32 usedTime = m_machineStat.pumpStartupTime;
	QString temp = QString::number(usedTime);
	pDb->updateDate("pumpUsedTime",temp);
}


void MachineStat::syncTime(quint32 time)
{
	setStartupTime( time*SYNC_TIME_UNIT );

	//判断是否处于PC控制模式;
	if( !m_bPcGradientCtrl )
	{
		m_bPcGradientCtrl = true;
		setMachineStat(PCCTRL);
	}

	m_nPcGradientCtrlFlag = 0;
	syncFlowFromPc();
}

#if 0
quint32 MachineStat::updateFlowByGradientList(quint32 time)
{
	time = time % pDb->getGradientEndTime();				//时间转换;
	QList<LineUint> &gradientList = pDb->getGradientList();//流量表格;
	for (int i = 0; i<gradientList.count(); i++)
	{
		const LineUint &line = gradientList.at(i);
		if(line.inStep(time))								//判断是否达到梯度转换的时间;
		{
			double flow = line.getStepValueByX(time);		//返回对应时间点的流量值;
			flow = compensationForFlow(flow);				//流量补偿;
			//double ret = flow*CONTROL_WORD_FACTOR;			//转换成mcu控制字;
			double ret = flow*GetWordFactor();
			m_pCommunicationCoupling->sendMcuCmd(1, MCU_WAVEADD_MOTOR, (uint32)ret);
			emit(updateFlowDisplay(line.getFlowStr()));//流量显示变更;

			return flow;
		}
	}
	return 0;
}
#endif



quint32 MachineStat::updateFlowByGradientList(quint32 time)
{
	time = time % pDb->getGradientEndTime();				//时间转换;
	QList<LineUint> &gradientList = pDb->getGradientList();//流量表格;
	for (int i = 0; i<gradientList.count(); i++)
	{
		const LineUint &line = gradientList.at(i);
		if(line.inStep(time))											//判断是否达到梯度转换的时间;
		{
			double flow = line.getStepValueByX(time);					//返回对应时间点的流量值;
			updateFlowPercent(line.getPercentVal(), GRADIENT_MODE);		//更新流速百分比;
			updateFlow(flow, GRADIENT_MODE);							//更新流速;
			return flow;
		}
	}
	return 0;
}


double MachineStat::compensationForPress(uint32 arg)
{
	double v0 = pDb->queryData("pressRawV0").toDouble();
	double val = ((double)arg-v0)*0.01;
	QList<LineUint> &pressCompensationList = pDb->getPressCompensationList();
	for (int i = 0; i < pressCompensationList.count(); i++)
	{
		if( pressCompensationList.at(i).inRange(val) )
		{
			double fix = pressCompensationList.at(i).getValueByXAndK(val);
			val = val * fix;
			break;
		}
	}
	return val;
}


void MachineStat::checkPressOverloaded(double val)
{
	double maxVal = pDb->queryData("maxpress").toDouble();
	double minVal = pDb->queryData("minpress").toDouble();
	quint8 warning = 0;
	if(getTime(STARTUPTIME) > 60)
	{
		if(val > maxVal)
			warning = 2;
		else if(val < minVal)
			warning = 1;
	}
	else//小于一分钟不作最小压力检测;
	{
		if(val > maxVal)
			warning = 2;
	}

	
	if(warning != 0)
	{
		setMachineStat(STOP, false);//停机;
		overPress = val;
		bOverPress = true;//置位压力报警标志
		sysError(OVERPRESS_ERR, true);//报警;
	}
	else
	{
		//sysError(OVERPRESS_ERR, false);//取消报警;
	}

	m_sCurrentPressVal = QString::number(val, 'f', 2);
	emit(updatePressDisplay(m_sCurrentPressVal, warning));
}

void MachineStat::updatePresVal(quint32 arg)
{
	BugleCompensation::getInstance()->adjustOutputByInput(arg);
	m_nCurrentPressRawCode = arg;
	double val = compensationForPress(arg);
	if(val < 0)
		val = 0;

	val = getAverageOfPress(val);//数据池滤波;
	checkPressOverloaded(val);
}


void MachineStat::clearPress()
{
	pDb->updateDate("pressRawV0", QString::number(m_nCurrentPressRawCode));
}



void MachineStat::uploadPresVal()
{
	double val = m_sCurrentPressVal.toDouble();
	val = val * 100;
	m_pCommunicationCoupling->sendCmd(1, PFC_READ_PRESS, val);
}


void MachineStat::initIPAddr()
{
	QString strCig = QString("ifconfig eth0 %1.%2.%3.%4").arg(DataBase::getInstance()->queryData("ip1")).arg(DataBase::getInstance()->queryData("ip2")).arg(DataBase::getInstance()->queryData("ip3")).arg(DataBase::getInstance()->queryData("ip4"));
#ifdef linux
	system(strCig.toLatin1().data());
#endif
}

void MachineStat::initDb()
{
	// = DataBase::getInstance();

}

quint32 MachineStat::getTime(MachineTime time)
{
	if(time == SYSTIME)
		return getUsedTime();
		//return m_machineStat.sysUsedTime;
	else if(time == STARTUPTIME)
		return m_machineStat.startupTime;
	else if(time == PUMPTIME)
		return m_machineStat.pumpStartupTime;
	else
		return 0;
}

void MachineStat::initTimeoutList()
{
	m_timeoutList.clear();
	registerTimeoutFunc(0, &MachineStat::syncFlowToMachine);
	registerTimeoutFunc(0, &MachineStat::checkFlowCtrlByPc);
	registerTimeoutFunc(2, &MachineStat::saveUsedTime);
	registerTimeoutFunc(2, &MachineStat::checkTryOut);
	registerTimeoutFunc(60, &MachineStat::saveDataBase);
	registerTimeoutFunc(0, &MachineStat::updateStartupTime);
}

void MachineStat::releaseTimeoutList()
{
	qDeleteAll(m_timeoutList.begin(), m_timeoutList.end() );
	m_timeoutList.clear();
}

void MachineStat::registerTimeoutFunc(const quint32 time, pTimeoutFunc pFunc)
{
	LPTimeOutStruct pTimeout= new TimeOutStruct;
	pTimeout->timeout = time;
	pTimeout->timeoutFunc = pFunc;
	pTimeout->cnt = 0;
	m_timeoutList.append(pTimeout);
}

void MachineStat::syncFlowToMachine()
{
	if(m_machineStat.machineStat == RUNNING)
	{
		//if(m_machineStat.machineStat!=PCCTRL)
		//{
			updateFlowByGradientList(m_machineStat.startupTime);		//按梯度更新流速;
		//}

	}
}

void MachineStat::checkTryOut()
{
	int active = pDb->queryData("bActive").toInt();
	if(active == 0)//如果未激活，需要定时检测试用时间;
	{
		if( checkProbation() == 0)
		{
			//g_pMainWindow->changePage(PWDPAGE_INDEX);
			m_machineStat.bTryDone = true;
			g_pMainWindow->changePage(PERMITPAGE_INDEX);
		}
		else//试用期未到;
		{
			m_machineStat.bTryDone = false;
		}
	}
	else
		m_machineStat.bTryDone = false;
}


void MachineStat::checkFlowCtrlByPc()
{
	//屏蔽上位机时间同步;
	return;

	if(m_machineStat.machineStat!= PCCTRL)
		return;

	if(!m_bPcGradientCtrl)
		return;

	//Clarity 协议不需要以下步骤;
	if(DataBase::getInstance()->queryData("pcProtocol").toInt() == 1)
		return;

	m_nPcGradientCtrlFlag++;
	if(m_nPcGradientCtrlFlag >= GRADIENTPCTIMEOUT)
	{
		m_bPcGradientCtrl = false;
		m_nPcGradientCtrlFlag = 0;
		setMachineStat(PAUSE);
	}

}

void MachineStat::updateStartupTime()
{
	if(m_machineStat.machineStat >= RUNNING)
	{
		//屏蔽上位机时间同步;
		/*if(!m_bPcGradientCtrl)
			setStartupTime(++m_machineStat.startupTime);*/
		setStartupTime(++m_machineStat.startupTime);
		m_machineStat.pumpStartupTime++;

	}

	//m_machineStat.sysUsedTime++;//系统使用时间;
}

quint64 MachineStat::generateActiveCode( quint64 sertialNum, quint8 which )
{
	quint64 ret=0;
	quint64 date=m_machineStat.m_nSerialId;
	/*QDate today = QDate::currentDate();
	date=today.year()*10000;
	date+=today.month()*100;
	date+=today.day();*/
	if(which == 0)//永久激活;
	{
		ret = (sertialNum+date)%ACTIVE_CODE_MAX;
		ret ^=ACTIVE_MASK;
		ret %=ACTIVE_CODE_MAX;
	}
	else
	{
		ret = (sertialNum+date)%ACTIVE_CODE_MAX;
		ret ^=ACTIVE_MASK;
		ret %=ACTIVE_CODE_MAX;
		ret /=1000;
		ret *=1000;
		ret +=ACTIVE_CODE_TRY;
	}
	return ret;
}

void MachineStat::setStartupTime(quint32 time)
{
	static quint32 ttime = 0;
	if(ttime == time)
		return;
	else
		ttime = time;

	m_machineStat.startupTime = time;
	emit( updateStartupTimeDisplay( time) );
}

void MachineStat::initCommunication()
{
	m_pCommunicationCoupling = new CommunicationCoupling(this);
}

void MachineStat::enableUpdateFlow()
{
	IoModule::getInstance()->logic_set_io(IO_MOTORSTOP_MASK, false);
}

void MachineStat::disableUpdateFlow()
{
	IoModule::getInstance()->logic_set_io(IO_MOTORSTOP_MASK, true);
}

void MachineStat::dealBulge()
{
	/*m_bBugleFlag = true;
	bugleTime = QTime::currentTime();
	bugleTime.restart();*/
	//告知凸轮补偿;
	BugleCompensation::getInstance()->bugleSignal();

	m_machineStat.bugleCnt++;
	DataBase::getInstance()->updateDate("bugleCnt", QString::number(m_machineStat.bugleCnt) );

	emit(updateBugleCnt(m_machineStat.bugleCnt));
}

void MachineStat::serialNumberGenerate()
{
	if(DataBase::getInstance()->queryData("serial").toULongLong() == 0 )
	{
		QDateTime currentTime = QDateTime::currentDateTime();
		qsrand(currentTime.time().msec());
		int randNum = qrand()%999999;

		quint64 serialNum = currentTime.date().year()*pow(10.0, 13) + currentTime.date().month()*pow(10.0, 11) + currentTime.date().day()*pow(10.0, 9);
		serialNum += currentTime.time().hour()*pow(10.0, 7) + currentTime.time().minute()*pow(10.0, 5) + currentTime.time().second()*pow(10.0, 3);
		serialNum += randNum;

		serialNum %=SERIAL_MAX;
		serialNum ^= SERIAL_NUM_KEY;

		DataBase::getInstance()->updateDate("serial", QString::number(serialNum));
		qDebug()<<"............"<<serialNum;
	}
}

quint32 MachineStat::getTryDayFromActiveCode( quint64 activeNum, quint32 serialId )
{
	quint32 tryday = activeNum%1000;
	serialId %=1000;
	tryday ^=serialId;
	tryday = 999-tryday;
	return tryday;
}


quint64 getActiveNum(quint64 sertialNum)
{
	quint64 serialNum = DataBase::getInstance()->queryData("serial").toULongLong();
	serialNum ^= SERIAL_NUM_KEY;
	return serialNum - SERIAL_NUM_VAL;
}


bool MachineStat::activeMachine(quint64 activeNum, bool bActive/* = true*/)
{
	bool ret = true;
	if( bActive )
	{
		quint64 serialNum = DataBase::getInstance()->queryData("serial").toULongLong();
		if( activeNum >= ACTIVE_CODE_TRY )//试用激活;
		{
			//判断是否相等;
			quint64 tActiveNum = generateActiveCode(serialNum, 1);
			quint64 temp = activeNum/1000*1000;
			if(tActiveNum == temp)
			{
				quint64 tryday = getTryDayFromActiveCode(activeNum, m_machineStat.m_nSerialId);
				//清空序列号随机码;
				m_machineStat.m_nSerialId = 0;
				
				if(tryday == 0)//取消激活;
				{
					//清空试用日期;
					pDb->updateDate("tryDay", QString::number(0));
					clearUsedTime();
				}
				else
				{
					//累加试用日期;
					tryday+=pDb->queryData("tryDay").toUInt();
					pDb->updateDate("tryDay", QString::number(tryday));
					/*qDebug()<<pDb->queryData("tryDay");*/

				}
				DataBase::getInstance()->updateDate("bActive", "0");

			}
			else
				ret = false;
		}
		else//永久激活;
		{
			//判断是否相等;
			quint64 tActiveNum = generateActiveCode(serialNum, 0);
			if(tActiveNum == activeNum)
			{
				//记录激活标志;
				DataBase::getInstance()->updateDate("bActive", "1");
				//清空序列号随机码;
				m_machineStat.m_nSerialId = 0;

				//清空试用日期;
				pDb->updateDate("tryDay", QString::number(0));
				clearUsedTime();
			}
			else
				ret = false;
		}

	}
	else
	{
		//取消激活标志;
		DataBase::getInstance()->updateDate("bActive", "0");
	}
	return ret;
}

void MachineStat::clearBugleCnt()
{
	m_machineStat.bugleCnt = 0;
	DataBase::getInstance()->updateDate("bugleCnt", QString::number(m_machineStat.bugleCnt));
}

void MachineStat::clearUsedTime()
{
	m_machineStat.m_firstTryDateTime = QDateTime::currentDateTime().toTime_t();//记录当前日期时间;
	pDb->updateDate("firstTryDateTime", QString::number(m_machineStat.m_firstTryDateTime));
}

void MachineStat::setPcProtocol(int idx)
{
	m_pCommunicationCoupling->setPcProtocol(idx);
}

void MachineStat::updateFlowCtrl(quint32 data)
{
	m_pCommunicationCoupling->sendMcuCmd(1, MCU_WAVEADD_MOTOR, data);
}

void MachineStat::shutDownWarn()
{
	if(bWarn)
		bWarn = false;

	IoModule::getInstance()->doWarn(false);
}

void MachineStat::initPressPoll()
{
	//初始化au队列，用于平均au值，平滑;
	pressList.clear();
	for (int i = 0; i < PRESS_POLL_SIZE; i++)
	{
		pressList.append(0.0);
	}
}

double MachineStat::getAverageOfPress( double au )
{
	//au值平滑处理;
	double auAverage = 0;
	int maxLen = PRESS_POLL_SIZE;

	if( pressList.count() > maxLen && maxLen != 0 )
	{
		pressList.removeFirst();
		pressList<<au;
		for (int i = 0; i < maxLen; i++)
		{
			auAverage += pressList.at(i);
		}
		auAverage /= (double)maxLen;
	}
	else
	{
		pressList<<au;
		auAverage = au;
	}
	return auAverage;
}

bool MachineStat::checkFlowOverLoaded(double flow)
{
	double maxFlow = getMaxFlow();
	if(flow > maxFlow)
	{
		setMachineStat(STOP, true);
		return true;
	}
	else
		return false;
}

quint32 MachineStat::getMaxFlow()
{
	quint32 pumpMaxFlowArray[]={10,50,100,250,500,1000,3000};
	quint32 index = DataBase::getInstance()->queryData("pumptype").toInt();
	if(index > 6)
		return 0;
	return pumpMaxFlowArray[index];
	
}

void MachineStat::sysError( int number, bool insert )
{
	if(warningList.indexOf(number) != -1 )
	{
		if(!insert)
			warningList.removeOne(number);
	}
	else
	{
		if(insert)
			warningList.append(number);
	}
	updateWarning();
}


void MachineStat::updateWarning()
{
	if(warningList.count() == 0)
		emit(systemError(0, tr("No Warn")));
	else
	{
		int warningId = warningList.at(0);
		switch(warningId)
		{
		case COMUNICATION_ERR:
			if(!bOverPress)
				emit(systemError(warningId, tr("Com error!")));
			break;
		//case OVERFLOW_ERR:
		//	emit(systemError(warningId, tr("Flow over:")+QString::number(overFlow)));
		//	//出发蜂鸣器报警;
		//	if(!bWarn)
		//	{
		//		bWarn = true;
		//		IoModule::getInstance()->doWarn(true);
		//		QTimer::singleShot(3000, this, SLOT(shutDownWarn()));
		//	}
		//	break;
		case OVERPRESS_ERR:
			{
				emit(systemError(warningId, tr("Press over:")+QString::number(overPress)));
				//出发蜂鸣器报警;
				if(!bWarn)
				{
					bWarn = true;
					IoModule::getInstance()->doWarn(true);
					QTimer::singleShot(3000, this, SLOT(shutDownWarn()));
				}
			}
		default:
			break;
		}
	}
}

MachineStat::MachineStatment MachineStat::getMachineStat()
{
	return m_machineStat.machineStat;
}

void MachineStat::initFlowCtrl()
{
	FlowCtrl::getInstance();
}

FlowCtrl * MachineStat::getFlowCtrl()
{
	return m_pFlowCtrl;
}

void MachineStat::pumpTypeChanged()
{
	//获取泵的类型改变上位机旧协议流速控制命令长度;
	int index = DataBase::getInstance()->queryData("pumptype").toInt();
	m_pCommunicationCoupling->setPumpTypeForPcFlowCtrl(index);
	m_machineStat.m_nPumpType = index;
}

int MachineStat::getPumpType()
{
	return m_machineStat.m_nPumpType;
}

void MachineStat::updateSerialId( quint32 id )
{
	m_machineStat.m_nSerialId = id;
}

void MachineStat::isUpdateFlowFromPC()
{
	if(!m_machineStat.m_bUpdateFlowFromPc)
		return;

	m_machineStat.m_bUpdateFlowFromPc = false;

	updateFlowPercentInPcMode(m_nCurrentPercent, true);
	emit(updateFlowDisplay(QString::number(m_dCurrentflowValInPc)));			//更新流速显示;
}

quint32 MachineStat::pcGetMachineStat()
{
	quint32 ret = 0;

	//获取运行状态;
	MachineStatment st = getMachineStat();
	if( st != STOP )
		ret |= 1<<20;

	//获取当前流速;
	//m_machineStat.m_dCurrentFlow = 5.000;//测试用，模拟当前流速5ml，测试clarity协议用;
	quint32 flow = m_machineStat.m_dCurrentFlow*1000;
	quint32 hFlow = DectoBCD(flow, 5);
	ret |=hFlow;

	return ret;
}

void MachineStat::updateFlowPercent( quint32 percent, FlowCtrlMode eFlowMod )
{
	switch (eFlowMod)
	{
		case PC_MODE:
			updateFlowPercentInPcMode(percent);
			break;
		case GRADIENT_MODE:
			updateFlowPercentLocal(percent);
			break;
		default:
			break;
	}
}

void MachineStat::updateFlowPercent( double percent )
{
	emit(updatePercentDisplay(QString::number(percent)));
}

void MachineStat::updateFlowPercentLocal( quint32 percent )
{
	static quint32 tpercent = 100000;

	if(tpercent == percent)
		return;
	else
		tpercent = percent;

	QString temp = QString("%1").arg(percent);
	m_dFlowPercent = (double)(percent)/100.0;

	emit(updatePercentDisplay(temp));
}

void MachineStat::updateFlowPercentInPcMode( quint32 percent , bool manual)
{
	

	if(m_nCurrentPercent == percent && manual == false)
		return;
	else
		m_nCurrentPercent = percent;

	QString temp;
	if(percent == 0)
	{
		temp = "100%";
	}
	else
	{
		temp = QString("%1").arg(percent -1);
	}
	emit(updatePercentDisplay(temp));
}

void MachineStat::updateFlowInPcMode( double flow )
{
	if( m_dCurrentflowValInPc == flow)
	{
		if( m_machineStat.machineStat == PCCTRL ) 
			return;
	}

	m_dCurrentflowValInPc = flow;
	m_machineStat.m_bUpdateFlowFromPc = true;

	emit(updateFlowDisplay(QString::number(flow)));			//更新流速显示;
	syncFlowFromPc();
}

void MachineStat::updateFlowInGradientMode( double flow )
{
	//流速x百分比;
	flow = flow * m_dFlowPercent;

	//更新显示;
	emit(updateFlowDisplay(QString::number(flow)));			//更新流速显示;

	syncFlowToMcu(flow);

}

void MachineStat::updateFlowInPumpPurgeMode( double flow )
{
	syncFlowToMcu(flow);
}

void MachineStat::updateFlowInDebugMode( double flow )
{
	syncFlowToMcu(flow);
}

void MachineStat::syncFlowFromPc()
{
	syncFlowToMcu(m_dCurrentflowValInPc);
}

void MachineStat::syncFlowToMcu( double flow )
{
	//过流检测;
	if( checkFlowOverLoaded(flow) )
	{
		overFlow = flow;
		sysError(OVERFLOW_ERR, 1);
		return;
	}
	else
		sysError(OVERFLOW_ERR, 0);

	/***************************流速补偿*********************************/
	flow = compensationForFlow(flow);


	/********************转换成mcu控制字,写入MCU*************************/
	//quint32 ret = flow*CONTROL_WORD_FACTOR;
	quint32 ret = flow*GetWordFactor();
	
	if(m_nFlowCtrlWord != ret )
	{
		m_nFlowCtrlWord = ret;
		//更新控制字到MCU;
		m_pCommunicationCoupling->sendMcuCmd(1, MCU_WAVEADD_MOTOR, ret);
		//凸轮补偿同步;
		//BugleCompensation::getInstance()->updateOutput(ret, flow);
	}
	
	//使能流速更新;
	MachineStat::getInstance()->enableUpdateFlow();
}

uint MachineStat::getUsedTime()
{
	QDateTime startTime = QDateTime::fromTime_t(m_machineStat.m_firstTryDateTime);
	QDateTime currentTime = QDateTime::currentDateTime();

	return (currentTime.toTime_t() - startTime.toTime_t() );
}



