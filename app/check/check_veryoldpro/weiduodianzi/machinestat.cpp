#include "machinestat.h"
#include <QTimer>
#include <QList>
#include <QtAlgorithms>
#include "lineuint.h"
#include "Communication/LogicThread.h"
#include "iomodule.h"
#include "baseMainPage.h"
#include "auadjust.h"

#ifdef linux
#include<sys/time.h>
#include <signal.h>
#include <pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
#endif

extern BaseMainPage *g_pMainWindow;

#define _USE_MATH_DEFINES
#include <math.h>
#include <QTime>

#define TIMEOUT		100
#define TIMEOUT100MS (100/TIMEOUT)
#define TIMEOUT1S	(1000/TIMEOUT)
#define TIMEOUT2S	(2000/TIMEOUT)
#define TIMEOUT3S	(3000/TIMEOUT)
#define TIMEOUT60S	(60000/TIMEOUT)

#define UPLOAD_AU_INTERVAL_MS			40

//auֵ���ݳش�С;
#define AU_LIST_MAX				10
#define AU_LIST_MAX_DOUBLE		1

#define SERIAL_MAX		9999999999
#define SERIAL_NUM_KEY	19900208
#define SERIAL_NUM_VAL	345192069
#define ACTIVE_CODE_TRY	9000000000
#define ACTIVE_CODE_MAX 999999999
#define ACTIVE_MASK		0x12345678

//������������;
//ǰ�󲹳��仯С��1nmʱ����Ҫ�Ĳ���;
#define MINI_COMPEN_VAL	0.03        //����ɨ�貹������
#define MINI_COMPEN_VAL1 0.05       //��λ��ɨ�貹������

/////////////////////////////////////////////////////////
//
//���ܣ�ʮ����תBCD��
//
//���룺int Dec                      ��ת����ʮ��������
//      int length                   BCD�����ݳ���
//
//�����unsigned char *Bcd           ת�����BCD��
//
//���أ�0  success
//
//˼·��ԭ��ͬBCD��תʮ����
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
	,m_bHomeInitSuccess(false)
	,m_nTimerId(0)
{
	pDb = DataBase::getInstance();	//���ݿ��ʼ��;
	initIO();						//IOģ���ʼ��;
	initTimer();					//��ʱ�������ʼ��;
	initMachineStat();				//����״̬��ʶ�ͱ�����ʼ��;
	initCommunication();			//ͨѶģ���ʼ��;

	//����ͬ���ͳ�ʼ��;
	updateTimeInte();				//���µ�Դ��ʱ����ֵ�mcu;
	initAulist();					//�岨1au
	initAulist(1);					//�岨2au

	initStartupTime();				//������ʱ;

	serialNumberGenerate();			//�������к�;



	//resetWaveAndAngle();
	//setWaveCtrlWordAndHome();//��ԭ��;
	
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


void MachineStat::timeoutFunc()
{
	for (QList<LPTimeOutStruct>::iterator it = m_timeoutList.begin(); it!=m_timeoutList.end(); it++)
	{
		LPTimeOutStruct pTimeout = *it;
		if(++pTimeout->cnt >= pTimeout->timeout)
		{
			pTimeout->cnt = 0;
			(this->*pTimeout->timeoutFunc)();
		}
	}

	if(!m_bHomeInitSuccess)
	{
		static int initTime = 0;
		initTime++;
		if(initTime >= (60*1000/TIMEOUT))
		{
			stopMotorInit();
			initStartup();
			initTime = 0;
		}
		/*else if(initTime%10 == 0)
		qDebug()<<initTime;*/
	}
}


void MachineStat::initIO()
{
	IoModule *pIO = IoModule::getInstance();
	connect(pIO, SIGNAL(initLampSuccess(bool)), this, SLOT(lightIniSuccess(bool)));
	initLamp();
	connect(IoModule::getInstance(), SIGNAL(bulge()), this, SLOT(dealBulge()));
}


void MachineStat::initTimer()
{
	initTimeoutList();//��ʱ�������ʼ��;				

	QTimer *pTimer = new QTimer(this);
	connect(pTimer, SIGNAL(timeout()), this, SLOT(timeoutFunc()));
	pTimer->start(TIMEOUT);

	setUploadAuFreq(1);

#if 0
//ʹ��linux�µĶ�ʱ��;
#ifdef linux
	if(DataBase::getInstance()->queryData("pcProtocol").toInt() == 0)
		setupUploadTask();
#endif
#endif
}

void MachineStat::initMachineStat()
{
	m_machineStat.machineStat = STARTUP;									//��ʼ��;
	m_machineStat.oldMachineStat = STARTUP;									//�ɵĻ���״̬;
	m_machineStat.machineMode = CMDMODE;									//����ģʽ��ɨ��ģʽ������ģʽ;
	m_machineStat.scanmodePrevStep = 0;										//ɨ��ģʽ�µ�ǰһ��;
	m_machineStat.m_nStartupTime = 0;											//����ʱ��
	//m_machineStat.m_nSysUsedTime = pDb->queryData("usedTime").toInt();			//ϵͳ�ۼ�ʱ��;
	m_machineStat.m_nXeStartupTime = pDb->queryData("xeUsedTime").toInt();		//뮵��ۼ�ʹ��ʱ��;
	m_machineStat.m_nTunStartupTime = pDb->queryData("tunUsedTime").toInt();	//�ٵ��ۼ�ʹ��ʱ��;
	m_machineStat.lampStat = OFF;											//��Դ״̬;
	m_machineStat.m_nSampleVal = 0;											//����ֵ;
	m_machineStat.m_nRefVal = 0;											//�α�ֵ;
	m_machineStat.m_nSampleVal2 = 0;											//����ֵ;
	m_machineStat.m_nRefVal2 = 0;											//�α�ֵ;
	m_machineStat.m_dAu1 = 0;												//����1ϰ�߶�;
	m_machineStat.m_dAu2 = 0;												//����2�����;
	m_machineStat.m_nCurrentWave = 0;										//��ǰ�����ǲ���1/2;
	m_machineStat.m_dCurrentWlen = 0;										//��ǰ����ֵ;
	m_machineStat.m_dCurrentAngle = 0;										//��ǰ�Ƕ�;
	m_machineStat.m_dPercentOfRandS = pDb->queryData("percentRofS").toDouble();									//K = R/S;
	m_machineStat.m_dPercentOfRandS2 = pDb->queryData("percentRofS2").toDouble();								//K = R/S;
	m_machineStat.m_nUploadWhich = 0;//Ĭ���ϴ�AU;
	m_machineStat.bTryDone = false;											//�������;

	m_machineStat.m_dPrevWlen = 0;
	m_machineStat.m_dScanOffset = 0;

	m_machineStat.m_nUploadInterval = 0;

	//��ȡ���õĵ�������;
	m_machineStat.m_firstTryDateTime = pDb->queryData("firstTryDateTime").toUInt();//��¼��ʼ���õĵ�������ʱ��;
	if(m_machineStat.m_firstTryDateTime == 0)
	{
		clearUsedTime();
	}

	//�ƺ��޸Ĳ�����ʱ��;
	m_pLatterTimer = new QTimer(this);
	m_pLatterTimer->setSingleShot(true);
	connect(m_pLatterTimer, SIGNAL(timeout()), this, SLOT(changeWlenLater()) ); 

	/*double a = waveToAngle(255);
	double b = waveToAngle(256);
	double c = waveToAngle(300);
	double d = waveToAngle(301);
	qDebug()<<"b="<<(b-=a);
	qDebug()<<"d="<<(d-=c);*/
}

void MachineStat::clearTime(MachineTime time)
{
	if(time == SYSTIME)
		clearUsedTime();
	else if(time == STARTUPTIME)
		clearStartupTime();
	else if(time == XEUSEDTIME)
		clearXeUsedTime();
	else if(time == TUNUSEDTIME)
		clearTunUsedTime();
}





void MachineStat::clearStartupTime()
{
	//setStartupTime(0);
	initStartupTime();
}




int MachineStat::checkProbation()
{
	quint32 probationDay = pDb->queryData("tryDay").toInt();			//��������;
	quint32 usedDay = getUsedTime()/60/60/24;
	//qDebug()<<getUsedTime();
	//qDebug()<<"..."<<probationDay;
	qint32 temp = probationDay - usedDay;
	//qDebug()<<"try Day:"<<probationDay;
	//qDebug()<<"used Day:"<<usedDay;
	temp = 100;//������;
	if(temp <= 0)
	{
		m_machineStat.bTryDone = true;
		temp = 0;
	}
	else
		m_machineStat.bTryDone = false;

	//return 0;
	return temp;
}

void MachineStat::saveUsedTime()
{
	//ʹ��ʱ���¼;�����ۼ�
	/*quint32 usedTime = m_machineStat.m_nSysUsedTime;
	QString temp = QString::number(usedTime);
	pDb->updateDate("usedTime", temp);*/

	quint32 usedTime = m_machineStat.m_nXeStartupTime;
	QString temp = QString::number(usedTime);
	pDb->updateDate("xeUsedTime",temp);

	usedTime = m_machineStat.m_nTunStartupTime;
	temp = QString::number(usedTime);
	pDb->updateDate("tunUsedTime",temp);
}



quint32 MachineStat::getTime(MachineTime time)
{
	if(time == SYSTIME)
		return getUsedTime();
		//return m_machineStat.m_nSysUsedTime;
	else if(time == STARTUPTIME)
		return m_machineStat.m_nStartupTime;
	else if(time == XEUSEDTIME)
		return m_machineStat.m_nXeStartupTime;
	else if(time == TUNUSEDTIME)
		return m_machineStat.m_nTunStartupTime;
	else
		return 0;
}

void MachineStat::initTimeoutList()
{
	m_timeoutList.clear();
	registerTimeoutFunc(TIMEOUT2S, &MachineStat::saveUsedTime);			//�������ʹ��ʱ��;//3s
	registerTimeoutFunc(TIMEOUT2S, &MachineStat::checkTryOut);			//����Ƿ����ó�ʱ;//3s
	registerTimeoutFunc(TIMEOUT60S, &MachineStat::saveDataBase);		//�������ݿ�;//60s
	registerTimeoutFunc(TIMEOUT1S, &MachineStat::updateStartupTime);	//����ʹ��ʱ��;//1s

	//registerTimeoutFunc(TIMEOUT100MS, &MachineStat::uploadAuToPc);		//����Auֵ��PC;//1s


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

void MachineStat::deRegisterTimeoutFunc( pTimeoutFunc pFunc )
{
	for (int i = 0; i < m_timeoutList.count(); i++)
	{
		if(m_timeoutList.at(i)->timeoutFunc == pFunc)
			delete(m_timeoutList.takeAt(i));
	}
}



void MachineStat::timerEvent( QTimerEvent *event )
{
	/*QTime newCurrentTime = QTime::currentTime();
	qDebug()<<m_currentTime.msecsTo(newCurrentTime);
	m_currentTime = newCurrentTime;*/
	uploadAuToPc();
	m_nStartupTimeMsec++;
}

void MachineStat::checkTryOut()
{
	int active = pDb->queryData("bActive").toInt();
	if(active == 0)//���δ�����Ҫ��ʱ�������ʱ��;
	{
		if( checkProbation() == 0)
		{
			//g_pMainWindow->changePage(PWDPAGE_INDEX);
			m_machineStat.bTryDone = true;
			g_pMainWindow->changePage(PERMITPAGE_INDEX);
		}
		else//������δ��;
		{
			m_machineStat.bTryDone = false;
		}
	}
	else
		m_machineStat.bTryDone = false;
}



void MachineStat::updateStartupTime()
{
#if 1
	if(getLampStat() == ON)//��Դ���ڹ���;
	{
		if(DataBase::getInstance()->queryData("xe_tun").toInt() == 0)//뮵�;
			m_machineStat.m_nXeStartupTime++;
		else
			m_machineStat.m_nTunStartupTime++;

	}
#endif
	//m_machineStat.m_nSysUsedTime++;//ϵͳʹ��ʱ��;
	//qDebug()<<m_machineStat.m_nSysUsedTime;
}



void MachineStat::setStartupTime(quint32 time)
{
	m_machineStat.m_nStartupTime = time;
	emit(updateStartupTimeDisplay( time) );
}

void MachineStat::initCommunication()
{
	m_pCommunicationCoupling = new CommunicationCoupling(this);
}



void MachineStat::lightIniSuccess(bool success)
{
	if(success)//����ʱ��
	{
		emit(changeLightStat(ON));
		m_machineStat.lampStat = ON;
		if(m_machineStat.machineStat == STARTUP)
		{
			QTimer::singleShot(500, this, SLOT(initStartup()));//��ʱ500ms
		}
	}
	else
	{
		emit(changeLightStat(OFF));
		sysError(LAMPINI_ERR, true);//��Դ��ʼ��ʧ��;
	}
	
}

void MachineStat::setLampStat(LampStatment stat)
{
	if(stat == m_machineStat.lampStat)
		return;

	m_machineStat.lampStat = stat;
	int whichLamp = DataBase::getInstance()->queryData("xe_tun").toInt();
	if(stat == ON)//����;
	{
		IoModule::getInstance()->lightOn(1, whichLamp);
	}
	else//�ص�;
	{
		IoModule::getInstance()->lightOn(0, whichLamp);
	}
	emit(changeLightStat(stat));

}



//��������;
#define KK (0.8589598*2.0/1200.0*1000000.0)
double MachineStat::waveToAngle(double wave)
{
	double val = wave/KK;
	val = asin((double)val);
	return val;
}


#define PULSE_PER_ROUND 102400
void MachineStat::locateToWaveLen1(double wLen, quint8 which)
{
	wLen = compensationForWave(wLen);

	m_machineStat.saowLen1 = wLen;        //����ʹ�ò���

	if(qAbs(wLen-m_machineStat.m_dPrevWlen) <= 3)
	{
		if(wLen > m_machineStat.m_dPrevWlen)
			m_machineStat.saowLen1+=MINI_COMPEN_VAL1;
		else
			m_machineStat.saowLen1-=MINI_COMPEN_VAL1;
	}
	double tAngle = waveToAngle(m_machineStat.saowLen1);//Ŀ�겨��ת���ɽǶ�;
	/*qDebug()<<(tAngle/2/M_PI*360);
	qDebug()<<(m_machineStat.m_dCurrentAngle/2/M_PI*360);*/
	int dir = 0;
	if(wLen > m_machineStat.m_dCurrentWlen)
		dir = 0x00;//��ʱ��;
	else
		dir = 0x10;//˳ʱ��;
	//�ǶȲ�;
	double delta = tAngle - m_machineStat.m_dCurrentAngle;

	//�ǶȲ�ת����������;
	//delta = abs(delta);
	if(delta < 0)
		delta = m_machineStat.m_dCurrentAngle-tAngle;
	//qDebug()<<(delta/2/M_PI*360);
	quint32 nStep = (delta/(2*M_PI))*PULSE_PER_ROUND;
	
	//˳ʱ����ʱ��??????
	quint32 arg =( (dir|0x1&0xff)<<21 |(nStep&0x1fffff) );

	m_pCommunicationCoupling->sendMcuCmd(1,MCU_SETWAV_TO,arg);

	m_machineStat.m_dCurrentWlen = wLen;
	m_machineStat.m_dCurrentAngle = waveToAngle(wLen);

}


void MachineStat::setWaveCtrlWordAndHome()
{
	setWaveCtrlWord();		//�·�MCU����ֵ;
	delay_ms(100);			
	initMotor();			//�·�MCU��ʼ������;

}

void MachineStat::updateSampleVal(quint32 val)
{
	//int timeInte = DataBase::getInstance()->queryData("timeInte").toInt();
	//timeInte = pow(2.0, timeInte);
	int timeInte = 1;

	if(m_machineStat.m_nCurrentWave == 0)//����1
	{
		m_machineStat.m_nSampleVal = val*timeInte;
		//qDebug()<<"au1->sample:"<<m_machineStat.m_nSampleVal;
	}
	else
	{
		m_machineStat.m_nSampleVal2 = val*timeInte;
		//qDebug()<<"au2->sample:"<<m_machineStat.m_nSampleVal2;
	}
}

void MachineStat::updateRefVal(quint32 val)
{
	if(m_machineStat.machineMode == SCANMODE && m_machineStat.machineStat == WAITRDY)
	{
		quint32 nIntervalTime = DataBase::getInstance()->queryData("sTime").toInt();
		nIntervalTime*=1000;
		nIntervalTime/=TIMEOUT;
		//registerTimeoutFunc(TIMEOUT3S,&MachineStat::waveScanUpdate);
		registerTimeoutFunc(nIntervalTime,&MachineStat::waveScanUpdate);
		m_machineStat.machineStat = READY;
		//sysError(5, 1);
	}
	if(m_machineStat.machineStat == LOCATINGWAVE)
	{
		QTimer::singleShot(3000, this, SLOT(delayAfterUpdateWave()));
		return;
	}
	
	//int maxLen = timeConstToAuListCnt();
	/*int timeInte = DataBase::getInstance()->queryData("timeInte").toInt();
	timeInte = pow(2.0, timeInte);*/
	int timeInte = 1;
	
	double cofficient = DataBase::getInstance()->queryData("coefficient").toDouble();
	double au = 0;
	
	if(m_machineStat.m_nCurrentWave == 0)//����1;
	{
		m_machineStat.m_nRefVal = val*timeInte;
		//qDebug()<<"au1->ref:"<<m_machineStat.m_nRefVal;
		if(m_machineStat.m_nRefVal == 0 || m_machineStat.m_nSampleVal == 0)
		{
			au = 0;
		}
		else
		{
			//AUֵ���㹫ʽ;
			au = cofficient*log10(m_machineStat.m_dPercentOfRandS *(double)m_machineStat.m_nRefVal/(double)m_machineStat.m_nSampleVal);
			//ƽ������;
			au = getAverageOfAu(au);
		}

		DataBase::getInstance()->updateDate("ausample1", QString::number(m_machineStat.m_nSampleVal));
		DataBase::getInstance()->updateDate("auref1", QString::number(m_machineStat.m_nRefVal));
		DataBase::getInstance()->updateDate("au1", QString::number(au, 'f', 4));
		m_machineStat.m_dAu1 = au;
		//qDebug()<<"au1:"<<m_machineStat.m_dAu1;
		emit(updateAuValue(m_machineStat.m_nSampleVal, m_machineStat.m_nRefVal, au, m_machineStat.m_nCurrentWave));
	}
	else
	{
		m_machineStat.m_nRefVal2 = val*timeInte;
		//qDebug()<<"au2->ref:"<<m_machineStat.m_nRefVal2;
		if(m_machineStat.m_nRefVal2 == 0 || m_machineStat.m_nSampleVal2 == 0)
		{
			au = 0;
		}
		else
		{
			//AUֵ���㹫ʽ;
			au = cofficient*log10(m_machineStat.m_dPercentOfRandS2 *(double)m_machineStat.m_nRefVal2/(double)m_machineStat.m_nSampleVal2);
			//ƽ������;
			au = getAverageOfAu(au, 1);
		}

		DataBase::getInstance()->updateDate("ausample2", QString::number(m_machineStat.m_nSampleVal2));
		DataBase::getInstance()->updateDate("auref2", QString::number(m_machineStat.m_nRefVal2));
		DataBase::getInstance()->updateDate("au2", QString::number(au, 'f', 4));
		m_machineStat.m_dAu2 = au;
		//qDebug()<<"au2:"<<m_machineStat.m_dAu2;
		emit(updateAuValue(m_machineStat.m_nSampleVal2, m_machineStat.m_nRefVal2, au, m_machineStat.m_nCurrentWave));
	}

	
}


double MachineStat::getAverageOfAu(double au, quint8 waveType)
{
	//auֵƽ������;
	double auAverage = 0;
	int maxLen = AU_LIST_MAX;//���������ݳ�;
	if(DataBase::getInstance()->queryData("chanel").toInt() == 1)//˫�������ݳس���;
		maxLen = AU_LIST_MAX_DOUBLE;
	
	if(waveType == 0)//��1
	{
		QList<double>& list = auList;
		if( list.count() > maxLen && maxLen != 0 )
		{
			list.removeFirst();
			list<<au;
			for (int i = 0; i < maxLen; i++)
			{
				auAverage += list.at(i);
			}
			auAverage /= (double)maxLen;
		}
		else
		{
			list<<au;
			//auAverage = au;
			for (int i = 0; i < list.count(); i++)
			{
				auAverage += list.at(i);
			}
			auAverage /= (double)list.count();
		}
	}
	else//��2;
	{
		QList<double>& list = auList2;
		if( list.count() > maxLen && maxLen != 0 )
		{
			list.removeFirst();
			list<<au;
			for (int i = 0; i < maxLen; i++)
			{
				auAverage += list.at(i);
			}
			auAverage /= (double)maxLen;
		}
		else
		{
			list<<au;
			//auAverage = au;
			for (int i = 0; i < list.count(); i++)
			{
				auAverage += list.at(i);
			}
			auAverage /= (double)list.count();
		}
	}

	if(pDb->queryData("chanel").toInt() != 0)//˫����;
		AuAdjust::getInstance()->updateAuVal(waveType, auAverage);
	else if(waveType == 0)//����������Ϊ����1;
		AuAdjust::getInstance()->updateAuValSingle(auAverage);

	return auAverage;
}





void MachineStat::setCurrentWave(quint32 which)
{
		m_machineStat.m_nCurrentWave = which;//��ǰ�����ǲ���1/2;
		//m_machineStat.m_nCurrentWave = 1;//��ǰ�����ǲ���2;
}

void MachineStat::setWaveCtrlWord()
{
	setWaveCtrlWord(DataBase::getInstance()->queryData("wavelen1"), DataBase::getInstance()->queryData("wavelen2"));
}

void MachineStat::setWaveCtrlWord( QString wlen1, QString wlen2 )
{
	delay_ms(100);
	locateToWaveLen1(wlen1.toDouble(), 0);
	delay_ms(100);
	locateToWaveLen2(wlen2.toDouble());
	//�л�����λ����״̬;
	m_machineStat.machineStat = LOCATINGWAVE;
	initAulist();
	initAulist(1);
}

void MachineStat::locateToWaveLen2(double wLen)
{
	wLen = compensationForWave(wLen);
	double tAngle = waveToAngle(wLen);//Ŀ�겨��ת���ɽǶ�;
	//qDebug()<<(tAngle/2/M_PI*360);
	int dir = 0;
	if(wLen > m_machineStat.m_dCurrentWlen)
		dir = 0;//��ʱ��;
	else
		dir = 0x10;//˳ʱ��;
	//�ǶȲ�;
	double delta = tAngle - m_machineStat.m_dCurrentAngle;

	//�ǶȲ�ת����������;
	//delta = abs(delta);
	if(delta < 0)
		delta = m_machineStat.m_dCurrentAngle-tAngle;
	quint32 nStep = (delta/(2*M_PI))*PULSE_PER_ROUND;
	//˳ʱ����ʱ��??????
	quint8 chanel = DataBase::getInstance()->queryData("chanel").toInt();
	if(chanel == 0)
		nStep = 0;
	quint32 arg =( (dir|0x2&0xff)<<21 |(nStep&0x1fffff) );

	
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_SETWAV_TO,arg);

	//m_machineStat.m_dCurrentWlen = wLen;
	//m_machineStat.m_dCurrentAngle = tAngle;
}

void MachineStat::resetWaveAndAngle()
{
	m_machineStat.m_dCurrentWlen = 0;//656.1;
	m_machineStat.m_dCurrentAngle = 0;//(27.2774/360.0)*2*M_PI;
}


#if 0
double MachineStat::compensationForWave(double wave)
{
#if 0
	return wave;
#endif
	QList<LineUint> &waveCompensationList = pDb->getWaveCompensationList();
	int cnt = waveCompensationList.count();
	if( cnt > 0 )
	{
		for (int i = 0; i<cnt; i++)
		{
			const LineUint &line = waveCompensationList.at(i);
			if(line.inRange(wave))
			{
				wave = line.getValueByXAndK(wave);//���ݹ�ʽ���ض�Ӧ������ֵ;
				return wave;
				/*wave = wave*percent;
				return (wave);*/
			}
		}
	}
	
	return wave;
}
#endif


double MachineStat::compensationForWave(double wave)
{
#if 0
	return wave;
#endif
	QList<LineUint> &waveCompensationList = pDb->getWaveCompensationList();
	int cnt = waveCompensationList.count();
	if( cnt > 0 )
	{
		//�ж��Ƿ�С����Сֵ;
		if( waveCompensationList.first().bOutOfStep(wave, LineUint::LEFT) )
		{
			wave = waveCompensationList.first().getValueByXAndK(wave, LineUint::LEFT);
		}
		//�ж��Ƿ�������ֵ;
		else if( waveCompensationList.last().bOutOfStep(wave, LineUint::RIGHT) )
		{
			wave = waveCompensationList.last().getValueByXAndK(wave, LineUint::RIGHT);
		}
		//�ж��Ƿ���ĳ������;
		else
		{
			for (int i = 0; i<cnt; i++)
			{
				const LineUint &line = waveCompensationList.at(i);
				if(line.inRange(wave))
				{
					wave = line.getValueByXAndK(wave);//���ݹ�ʽ���ض�Ӧ������ֵ;
					return wave;
				}
			}
		}
	}
	
	return wave;
}

void MachineStat::setPercentOfRandS(quint32 waveType)
{
	//waveType = m_machineStat.m_nCurrentWave;

	//if(waveType == 0)//����1
	//{
		initAulist();

		if(m_machineStat.m_nSampleVal == 0)
			return;

		if(m_machineStat.m_nRefVal == 0 )
			return;

		m_machineStat.m_dPercentOfRandS = (double)m_machineStat.m_nSampleVal/(double)m_machineStat.m_nRefVal;
		DataBase::getInstance()->updateDate("percentRofS", QString::number(m_machineStat.m_dPercentOfRandS));
	//}
	//else//����2;
	//{
		initAulist(1);

		if(m_machineStat.m_nSampleVal2 == 0)
			return;

		if(m_machineStat.m_nRefVal2 == 0 )
			return;

		m_machineStat.m_dPercentOfRandS2 = (double)m_machineStat.m_nSampleVal2/(double)m_machineStat.m_nRefVal2;
		DataBase::getInstance()->updateDate("percentRofS2", QString::number(m_machineStat.m_dPercentOfRandS2));
	//}
}

void MachineStat::clearXeUsedTime()
{
	m_machineStat.m_nXeStartupTime = 0;
	saveUsedTime();
}

void MachineStat::clearTunUsedTime()
{
	m_machineStat.m_nTunStartupTime = 0;
	saveUsedTime();
}

void MachineStat::uploadAuToPc()
{
#ifndef WIN32
	if(m_machineStat.machineStat!= READY)
		return;
#endif

	quint32 pcProtocol = DataBase::getInstance()->queryData("pcProtocol").toInt();
	/*double au = 0.132081;
	double au = -0.080012;
	m_pCommunicationCoupling->sendCmdClarity(0, PFCC_SEND_AU, changeAuValtoClarity(au));
	return;*/

	switch(m_machineStat.m_nUploadWhich)
	{
		//�ϴ�Au
		case 0:
		{
			double au = QString::number(m_machineStat.m_dAu1,'f', 8).toDouble();
			double au2 = QString::number(m_machineStat.m_dAu2,'f', 8).toDouble();
			int chanel = DataBase::getInstance()->queryData("chanel").toInt();
			if(chanel != 0)//˫����ʱ��;
			{
#if 1
				if( !AuAdjust::getInstance()->getdoubleAuVal(&au, &au2) )
				{
					//qDebug()<<"error.......................double wlen get au upload";
					return;
				}
#endif
			}
			else//������ʱ��;
			{
#if 1
				if( !AuAdjust::getInstance()->getAuValSingle(&au) )
				{
					qDebug()<<"error.......................single wlen get au upload";
					return;
				}
#endif
			}
			
			
			double constVal = DataBase::getInstance()->getConstVal();
			
			au = au*2/constVal;
			
			quint32 nUploadAu1 = ((au+2)/4.0*0xffffff);
			
			//qDebug()<<"au1:"<<QString::number(x1, 16);
			nUploadAu1 &= 0xffffff;
			
			au2 = au2*2/constVal;
			
			quint32 nUploadAu2 = ((au2+2)/4.0*0xffffff);
			
			//qDebug()<<"au2:"<<QString::number(x2, 16);
			nUploadAu2&=0xffffff;
			
			if(chanel == 0)//������;
			{
				if(pcProtocol == 0)
					m_pCommunicationCoupling->sendCmd(CMD_ASCII_SINGLEWAV, nUploadAu1, 0);
				else
				{
					m_pCommunicationCoupling->sendCmdClarity(0, PFCC_SEND_AU, changeAuValtoClarity(au));
				}
			}
			else//˫����;
			{
				if(pcProtocol == 0)
					m_pCommunicationCoupling->sendCmd(CMD_ASCII_DOUBLEWAV, nUploadAu1, nUploadAu2);
				else
				{
					m_pCommunicationCoupling->sendCmdClarity(0, PFCC_SEND_AU, changeAuValtoClarity(au2));
				}
			}
		}
		break;
		//�ϴ�Sֵ;
		case 1:
		{
			quint32 sVal = 0;
			if(m_machineStat.m_nCurrentWave == 0)//��1
				sVal = m_machineStat.m_nSampleVal;
			else//��2;
				sVal = m_machineStat.m_nSampleVal2;
			m_pCommunicationCoupling->sendCmd(CMD_ASCII_SVAL , sVal, 0);
		}
		break;
		//�ϴ�Rֵ;
		case 2:
		{
			quint32 rVal = 0;
			if(m_machineStat.m_nCurrentWave == 0)//��1
				rVal = m_machineStat.m_nRefVal;
			else
				rVal = m_machineStat.m_nRefVal2;
			m_pCommunicationCoupling->sendCmd(CMD_ASCII_RVAL, rVal, 0);
		}
		break;
		default:
			break;
	}
	
	
}

quint32 MachineStat::changeAuValtoClarity( double au )
{
	quint32 ret = 0;
	if( au < 0 )
	{
		ret=((-au)*1000000);
		ret= 0xffffff-ret;
	}
	else
	{
		ret = 1000000*au;
	}
	return ret;
}

void MachineStat::updateSerialId( quint32 id )
{
	m_machineStat.m_nSerialId = id;
}



void MachineStat::initMotor()
{
	/*m_pCommunicationCoupling->sendMcuCmd(1,MCU_MOTOR_INI,0);
	return;*/

	if(m_machineStat.machineStat != READY && m_machineStat.machineStat != LOCATINGWAVE)
		return;

	delay_ms(100);
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_MOTOR_INI,0);
	IoModule::getInstance()->magnitOn(true);
	m_machineStat.machineStat = INITIALIZING;
}

void MachineStat::setWaveScanMode( bool on, double sWave /*= 0*/, double eWave /*= 0*/, quint32 time /*= 0*/ )
{
	static int chanel = DataBase::getInstance()->queryData("chanel").toInt();
	if(!on)//ȡ����ɨ��ģʽ����ظ�֮ǰ״̬;
	{
		//������ָ�����ģʽ;
		m_machineStat.machineMode = CMDMODE;		//����ģʽ;
		m_machineStat.scanmodePrevStep = 0;
		m_machineStat.machineStat = READY;			//����״̬;

		//����֮ǰ״̬;
		DataBase::getInstance()->updateDate("chanel", QString::number(chanel));//�ָ�֮ǰ�Ĳ���ͨ��;
		resetWaveAndAngle();
		setWaveCtrlWordAndHome();					//���ò����ֲ���ԭ��;		

		deRegisterTimeoutFunc(&MachineStat::waveScanUpdate);
	}
	else//����ɨ��ģʽ;
	{
		//������һģʽ;
		chanel = DataBase::getInstance()->queryData("chanel").toInt();

		//�л���������;
		DataBase::getInstance()->updateDate("chanel", "0");
		resetWaveAndAngle();
		setWlenStep(0,0, 1);//��ղ���1������;
		delay_ms(100);
		setWlenStep(0,0, 2);//��ղ���2������;

		//����ɨ��ģʽ;
		m_machineStat.machineMode = SCANMODE;
		m_machineStat.sWlen = sWave;//��ʼɨ�貨��;
		m_machineStat.eWlen = eWave;//����ɨ�貨��;

		m_machineStat.m_dPrevWlen = 0;
		m_machineStat.m_dScanOffset = 0;

		//���Ŀǰ�����ڳ�ʼ����ô��??????????m_machineStat.machineState = INITIALIZING?????????

		//��ʼ��;
		initMotor();

#if 0//��λ�����Դ�ӡɨ������Ҫ�õ���δ���
		quint32 nIntervalTime = DataBase::getInstance()->queryData("sTime").toInt();
		nIntervalTime*=1000;
		nIntervalTime/=TIMEOUT;
		registerTimeoutFunc(nIntervalTime,&MachineStat::waveScanUpdate);
#endif
	}
}

void MachineStat::waveScanUpdate()
{
#if 0//��ӡɨ����;
	static QTime eLapseTime = QTime::currentTime();
	qDebug()<<"scan..............................."<<eLapseTime.elapsed();
	eLapseTime.restart();
#endif	

	if(m_machineStat.eWlen >= m_machineStat.sWlen)
	{
		stepToWave(m_machineStat.sWlen);
		emit(wLenChanged(QString::number(m_machineStat.sWlen), 0));
		m_machineStat.sWlen++;
	}
	else//scan done...
	{
		QTimer::singleShot(100, this, SIGNAL(wLenScanDone()));//������ɽ���ã�����waveScanUpdate��������ǰ��ʱʵ�屻ע����;
	}
}

void MachineStat::stepToWave( double wLen )
{
	int dir = 0x00;//0x00��ʱ��;0x10˳ʱ��;
	qDebug()<<"step to wave---------------:"<<wLen;

	//���ݲ�����������������;
	double wLenCompen = compensationForWave(wLen);

	//С��Χ����;
	wLenCompen += m_machineStat.m_dScanOffset;
	if(qAbs(wLenCompen-m_machineStat.m_dPrevWlen) <= 3)
	{
		if(wLenCompen > m_machineStat.m_dPrevWlen)
		{
			wLenCompen+=MINI_COMPEN_VAL;
			m_machineStat.m_dScanOffset += MINI_COMPEN_VAL;
		}
		else
		{
			wLenCompen-=MINI_COMPEN_VAL;
			m_machineStat.m_dScanOffset -= MINI_COMPEN_VAL;
		}
	}
	m_machineStat.m_dPrevWlen = wLenCompen;

	double tAngle = waveToAngle(wLenCompen);						//Ŀ�겨��ת���ɽǶ�;
		
	double delta = qAbs( tAngle - m_machineStat.m_dCurrentAngle );	//��0����ǶȲm_machineStat.m_dCurrentAngle=0;
	
	quint32 nStep = (delta/(2*M_PI))*PULSE_PER_ROUND;				//�ǶȲ�ת����;
	int deltaStep = nStep-m_machineStat.scanmodePrevStep;			//��ɨ���ǰ������;
	if(deltaStep < 0)
		dir = 0x10;//��ʱ��;
	deltaStep = qAbs(deltaStep);									//ȡ������ľ���ֵ;

	quint32 arg =( (dir|0x6&0xff)<<21 |(deltaStep&0x1fffff) );		//���͸�MCU;
	m_machineStat.scanmodePrevStep = nStep;
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_STEP_TO,arg);
	
}


void MachineStat::setWlenStep( quint32 step, quint8 dir, quint8 which )
{
	quint32 arg =( (dir|which&0xff)<<21 |(step&0x1fffff) );
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_SETWAV_TO,arg);
}


void MachineStat::motorInitSuccess()
{
	if( m_machineStat.machineStat == INITIALIZING )//������ڳ�ʼ�����򷵻ؾ���״̬;
	{
		emit(motorInitSuccessSignal());
		m_bHomeInitSuccess = true;
		if(DataBase::getInstance()->queryData("xe_tun").toInt() == 0)	//뮵����ͷŵ����;
			IoModule::getInstance()->magnitOn(false);

		if(m_machineStat.machineMode == SCANMODE)
		{
			stopMotorInit();
			waveScanUpdate();									//��λ����һ����ʼ����;
			m_machineStat.machineStat = WAITRDY;
		}
		else
			m_machineStat.machineStat = READY;
	}
}


void MachineStat::stopMotorInit()
{
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_MOTOR_INI_STOP,0);
}


void MachineStat::setStepTo( quint32 step, quint8 dir )
{
	quint32 arg =( (dir|0x06&0xff)<<21 |(step&0x1fffff) );
	m_pCommunicationCoupling->sendMcuCmd(1,MCU_STEP_TO,arg);
}


void MachineStat::uploadTimeToPc( MachineTime time, quint32 add )
{
	if(time == XEUSEDTIME)
	{
		quint32 time = DataBase::getInstance()->queryData("xeUsedTime").toInt();
		
		if(add == 0)//����
		{
			time /= 60;
		}
		else if(add == 1)//Сʱ;
		{
			time /= 3600;
		}
		else
			time = 0;

		m_pCommunicationCoupling->sendCmd(1, PFC_READ_LGTIME, time);
	}
	else if(time == SYSTIME)
	{
		//quint32 time = DataBase::getInstance()->queryData("usedTime").toInt();
		quint32 time = getUsedTime();

		if(add == 0)//����
		{
			time /= 60;
		}
		else if(add == 1)//Сʱ;
		{
			time /= 3600;
		}
		else
			time = 0;

		m_pCommunicationCoupling->sendCmd(1, PFC_READ_SYSTIME, time);
	}
}


void MachineStat::delay_ms(int msec)
{
	QTime n=QTime::currentTime();
	QTime now;
	do{
		now=QTime::currentTime();
	}   while (n.msecsTo(now)<=msec);
}


void MachineStat::sysError(int number, bool insert)
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
				emit(systemError(warningId, tr("Com error!")));
				break;
			case LAMPINI_ERR:
				emit(systemError(warningId, tr("Lamp error!")));
				break;
			default:
				break;
		}
	}
}

void MachineStat::readSandRval()
{
	m_pCommunicationCoupling->sendMcuCmd(CMD_NORMAL, MCU_READ_AU_VAL_1, 0);
	delay_ms(10);
	m_pCommunicationCoupling->sendMcuCmd(CMD_NORMAL, MCU_READ_AU_VAL_2, 0);
}

int MachineStat::timeConstToAuListCnt()
{
	int auListLen[]={1,2,5,10,20,50,100};
	int timeConst = DataBase::getInstance()->queryData("timeconst").toInt();
	return auListLen[timeConst%7];
}

void MachineStat::initLamp()
{
	int whichLamp = DataBase::getInstance()->queryData("xe_tun").toInt();
	IoModule::getInstance()->initLamp(whichLamp);
}

void MachineStat::changeLampSrc( int src )
{
	DataBase::getInstance()->updateDate( "xe_tun", QString::number(src) );
	initLamp();
}

void MachineStat::setWlen( quint32 wlen, quint8 which )
{
	if(which == 0)
		DataBase::getInstance()->updateDate("wavelen1", QString::number(wlen));
	else
		DataBase::getInstance()->updateDate("wavelen2", QString::number(wlen));

	emit(wLenChanged(QString::number(wlen), which));
}

void MachineStat::updateTimeInte()
{
#if 1
	int whichLamp = DataBase::getInstance()->queryData("xe_tun").toInt();//��Դ
	int timeInte = DataBase::getInstance()->queryData("timeInte").toInt();//ʱ�����;
	QList<int>timeInteList;
	timeInteList<<0x08<<0x04<<0x02<<0x01;
	if(timeInte > 3)
		return;
	quint32 arg = ((whichLamp&0xff)<<21)|((timeInteList.at(timeInte)&0xff)<<14);
	m_pCommunicationCoupling->sendMcuCmd(CMD_NORMAL, MCU_SET_PARAM, arg);
#endif
}

void MachineStat::setPcProtocol(int idx)
{
	m_pCommunicationCoupling->setPcProtocol(idx);
}

quint32 MachineStat::getMachineStat1()
{
	/*00XXXX��뮵ƹ�״̬
	01XXXX��뮵ƿ�״̬
	10XXXX���ڵƹ�״̬
	11XXXX���ڵƿ�״̬
	XXXXΪ��ǰ�����������190��700nm*/
	quint32 ret = 0;
	quint32 lampWhich = DataBase::getInstance()->queryData("xe_tun").toInt();//0뮵ơ�1�ٵ�;
	quint32 lampStat = getLampStat();//0����1��;
	if(lampWhich == 0)
	{
		ret = 0x000000;
	}
	else
	{
		ret = 0x100000;
	}
	if(lampStat == 0)//��״̬;
	{
		ret |= 0x10000;
	}
	
	quint32 wLen = DataBase::getInstance()->queryData("wavelen1").toInt();
	quint32 hWlen = DectoBCD(wLen, 4);
	ret|=hWlen;
	qDebug("%x",ret);
	return ret;
}

quint32 MachineStat::getMachineStat2()
{
	/*0XX0YY
	XXΪʱ�䳣����1��2��5��10��50���̶�1λС����
	YY�����Χ0��17*/
	quint32 ret = 0;
	char buf[7] = {0x01, 0x02, 0x05, 0x10, 0x20, 0x50, 0x0};
	int timeIdx = DataBase::getInstance()->queryData("timeconst").toInt();
	int rangeIdx = DataBase::getInstance()->queryData("range").toInt();
	ret |= buf[timeIdx]<<12;
	ret |= DectoBCD(rangeIdx, 2);
	qDebug("%6x",ret);
	return ret;
}

void MachineStat::setUploadPcValChanel( int which )
{
	if(which >=0 && which <=2)
		m_machineStat.m_nUploadWhich = which;
}

#if 1
MachineStat::EStatException MachineStat::changeWaveLength(double wlen, MachineStat::EWLEN which)
{
	//��鲨���Ƿ����ı䣬���û�У�����;
	if( !checkWaveLenChanged(wlen, which) )
		return EStat_Busy;

	EStatException eStatException = EStat_Success;

	if(m_machineStat.machineMode == SCANMODE)//ɨ��ģʽ;
		eStatException = EStat_Busy;
	else									 //�Զ�ģʽ;
	{
		if( m_machineStat.machineStat != READY )
		{
			eStatException = EStat_Busy;
		}
		else//�����������READY״̬����������Ѿ����ԭ��;
		{
			quint8 chanel = DataBase::getInstance()->queryData("chanel").toInt();
			emit(wLenChanged(QString::number(wlen), which));
			if(which == EWLEN1)
			{
				DataBase::getInstance()->updateDate("wavelen1", QString::number(wlen));
			}
			else
			{
				DataBase::getInstance()->updateDate("wavelen2", QString::number(wlen));
			}
			if(chanel == 0 && which == EWLEN1)
			{
				//MachineStat::getInstance()->resetWaveAndAngle();
				MachineStat::getInstance()->setWaveCtrlWord();
			}
			else
			{
				MachineStat::getInstance()->resetWaveAndAngle();
				MachineStat::getInstance()->setWaveCtrlWordAndHome();
			}
		}
	}

	//�ƺ��޸Ĳ���;
#if 0
	if(eStatException != EStat_Success)
	{
		m_dTempWlen = wlen;
		m_eWhich = which;
		emit(testSignal(m_dTempWlen));
		if(!m_pLatterTimer->isActive())
			m_pLatterTimer->start(800);
	}
#endif

	return eStatException;
}
#endif

//MachineStat::EStatException MachineStat::changeWaveLength(double wlen, MachineStat::EWLEN which)
//{
//	EStatException eStatException = EStat_Success;
//	
//	quint8 chanel = DataBase::getInstance()->queryData("chanel").toInt();
//	emit(wLenChanged(QString::number(wlen), which));
//	if(which == EWLEN1)
//	{
//		DataBase::getInstance()->updateDate("wavelen1", QString::number(wlen));
//	}
//	else
//	{
//		DataBase::getInstance()->updateDate("wavelen2", QString::number(wlen));
//	}
//	if(chanel == 0 && which == EWLEN1)
//	{
//		//MachineStat::getInstance()->resetWaveAndAngle();
//		MachineStat::getInstance()->setWaveCtrlWord();
//	}
//	else
//	{
//		MachineStat::getInstance()->resetWaveAndAngle();
//		MachineStat::getInstance()->setWaveCtrlWordAndHome();
//	}
//
//	return eStatException;
//}

void MachineStat::initIPAddr()
{
	QString strCig = QString("ifconfig eth0 %1.%2.%3.%4").arg(DataBase::getInstance()->queryData("ip1")).arg(DataBase::getInstance()->queryData("ip2")).arg(DataBase::getInstance()->queryData("ip3")).arg(DataBase::getInstance()->queryData("ip4"));
#ifdef linux
	system(strCig.toLatin1().data());
#endif
}

void MachineStat::initAulist(quint8 wavetype)
{
	//��ʼ��au���У�����ƽ��auֵ��ƽ��;
	if(wavetype == 0)
		auList.clear();
	else
		auList2.clear();
}

void MachineStat::initStartupTime()
{
	/*m_startupTime = QTime::currentTime();*/
	m_nStartupTimeMsec = 0;
}

QString MachineStat::getStartupTime()
{
	/*QTime time = QTime::currentTime();
	int elapse = m_startupTime.secsTo(time);
	int h = elapse/3600;
	int m = elapse/60%60;
	int s = elapse%60;
	QString strHour = QString("%1:").arg(h).rightJustified(3, '0');
	QString strMin = QString("%1:").arg(m).rightJustified(3, '0');
	QString strSec = QString("%1").arg(s).rightJustified(2, '0');
	return strHour+strMin+strSec;*/
	

	quint32 sec = m_nStartupTimeMsec/20;

	int h = sec/3600;
	int m = sec/60%60;
	int s = sec%60;
	QString strHour = QString("%1:").arg(h).rightJustified(3, '0');
	QString strMin = QString("%1:").arg(m).rightJustified(3, '0');
	QString strSec = QString("%1").arg(s).rightJustified(2, '0');
	return strHour+strMin+strSec;
}

//17λ���к�;
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

quint64 MachineStat::generateActiveCode( quint64 sertialNum, quint8 which )
{
	quint64 ret=0;
	quint64 date=m_machineStat.m_nSerialId;
	/*QDate today = QDate::currentDate();
	date=today.year()*10000;
	date+=today.month()*100;
	date+=today.day();*/
	if(which == 0)//���ü���;
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
		if( activeNum >= ACTIVE_CODE_TRY )//���ü���;
		{
			//�ж��Ƿ����;
			quint64 tActiveNum = generateActiveCode(serialNum, 1);
			quint64 temp = activeNum/1000*1000;
			if(tActiveNum == temp)
			{
				//��ȡ����;
				quint64 tryday = getTryDayFromActiveCode(activeNum, m_machineStat.m_nSerialId);
				//quint64 tryday = activeNum%1000;
				//������к������;
				m_machineStat.m_nSerialId = 0;
				
				if(tryday == 0)//ȡ������;
				{
					//�����������;
					pDb->updateDate("tryDay", QString::number(0));
					clearUsedTime();
				}
				else
				{
					//�ۼ���������;
					tryday+=pDb->queryData("tryDay").toUInt();
					pDb->updateDate("tryDay", QString::number(tryday));
					/*qDebug()<<pDb->queryData("tryDay");*/

				}
				DataBase::getInstance()->updateDate("bActive", "0");

			}
			else
				ret = false;
		}
		else//���ü���;
		{
			//�ж��Ƿ����;
			quint64 tActiveNum = generateActiveCode(serialNum, 0);
			if(tActiveNum == activeNum)
			{
				//��¼�����־;
				DataBase::getInstance()->updateDate("bActive", "1");
				//������к������;
				m_machineStat.m_nSerialId = 0;

				//�����������;
				pDb->updateDate("tryDay", QString::number(0));
				clearUsedTime();
			}
			else
				ret = false;
		}
			
	}
	else
	{
		//ȡ�������־;
		DataBase::getInstance()->updateDate("bActive", "0");
	}
	return ret;
}

void MachineStat::initStartup()
{
	m_machineStat.machineStat = READY;
	resetWaveAndAngle();				//��λ��������ο�ֵ;
	setWaveCtrlWordAndHome();			//���ò�������ԭ��;
}

void MachineStat::delayAfterUpdateWave()
{
	if(m_machineStat.machineStat == LOCATINGWAVE)
		m_machineStat.machineStat = READY;
}

void MachineStat::clearWave1()
{

}

void MachineStat::clearWave2()
{

}

 void MachineStat::dealBulge()
{
#ifdef linux
	if( DataBase::getInstance()->queryData("pcProtocol").toInt() == 0 )
		m_pCommunicationCoupling->sendCmd(CMD_SYNC_COLLECT,0,0);
	else
		m_pCommunicationCoupling->sendCmdClarity(0, PFCC_INPUT_EVENT, 0);
#endif
}

 void MachineStat::changeWlenLater()
 {
	 changeWaveLength(m_dTempWlen, m_eWhich);
 }

 bool MachineStat::checkWaveLenChanged(double wlen, EWLEN which)
{
	QString wlenVar = QString("wavelen1");
	if(which == EWLEN2)
		wlenVar = QString("wavelen2");

	double oldWlen = DataBase::getInstance()->queryData(wlenVar).toDouble();

	return (oldWlen != wlen);
}

void MachineStat::chanelChanged(int ch)
{
	initAulist(0);
	initAulist(1);
	resetWaveAndAngle();
	setWaveCtrlWordAndHome();

	AuAdjust::getInstance()->clear();
}

void MachineStat::clearUsedTime()
{
	m_machineStat.m_firstTryDateTime = QDateTime::currentDateTime().toTime_t();//��¼��ǰ����ʱ��;
	pDb->updateDate("firstTryDateTime", QString::number(m_machineStat.m_firstTryDateTime));
}

uint MachineStat::getUsedTime()
{
	QDateTime startTime = QDateTime::fromTime_t(m_machineStat.m_firstTryDateTime);
	QDateTime currentTime = QDateTime::currentDateTime();
	//qDebug()<<startTime;
	if(currentTime.toTime_t() > startTime.toTime_t())
		return (currentTime.toTime_t() - startTime.toTime_t() );
	else
		return 345600;
}


//��ʱ�ϴ�;
struct timeval startTime,endTime;
int flag =0;
void uploadRoutine(int signo)
{
	
#ifdef linux
	if(signo == SIGALRM)
	{ 

		struct itimerval value, ovalue;
		value.it_value.tv_sec = 0;
		value.it_value.tv_usec = (0);
		value.it_interval.tv_sec = 0;
		value.it_interval.tv_usec = (0);
		setitimer(ITIMER_REAL, &value, &ovalue); 




		float elapse;
		gettimeofday(&endTime,NULL);

		//����ʱ��;
		elapse = 1000000*(endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec);  
		elapse /= 1000;
		//printf("!!!!!!!!!elapse!!!!!!!!!!!!!!! = %f\n",elapse);  

		MachineStat::getInstance()->uploadAuToPc();
		//signal(SIGALRM, uploadRoutine);
		gettimeofday(&startTime,NULL);  

		value.it_value.tv_sec = 0;
		value.it_value.tv_usec = (UPLOAD_AU_INTERVAL_MS*1000*1);
		value.it_interval.tv_sec = 0;
		value.it_interval.tv_usec = (UPLOAD_AU_INTERVAL_MS*1000*1);
		setitimer(ITIMER_REAL, &value, &ovalue); 
		signal(SIGALRM, uploadRoutine);

		


	}



#endif
	
}


//linux��ʱ����;
void MachineStat::setupUploadTask()
{
#ifdef linux
	setUploadAuFreq(1);
#endif
}



void MachineStat::setUploadAuFreq( quint32 interval )
{
	if(m_nTimerId !=0 )
		killTimer(m_nTimerId);

	//������ʱ��;
	m_nTimerId = startTimer(UPLOAD_AU_INTERVAL_MS*interval);
#if 0
#ifdef linux
	struct itimerval value, ovalue;

	signal(SIGALRM, uploadRoutine);

	value.it_value.tv_sec = 0;

	value.it_value.tv_usec = (UPLOAD_AU_INTERVAL_MS*1000*interval);

	value.it_interval.tv_sec = 0;

	value.it_interval.tv_usec = (UPLOAD_AU_INTERVAL_MS*1000*interval);

	setitimer(ITIMER_REAL, &value, &ovalue); 
#endif
#endif
}





