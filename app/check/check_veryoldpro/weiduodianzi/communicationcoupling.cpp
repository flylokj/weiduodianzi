#include "communicationcoupling.h"
#include "machinestat.h"
#include <QStringList>

CommunicationCoupling::CommunicationCoupling(MachineStat *parent)
	: QObject(parent)
	, m_pMachine(parent)
{
	initCommunication();
}



CommunicationCoupling::~CommunicationCoupling()
{

}




void CommunicationCoupling::initCommunication()
{
	qDebug()<<QThread::currentThread();
	m_pWorker = new Worker(this);
	connect(this, SIGNAL(cmdSend(quint8, quint32, quint32)), m_pWorker, SLOT(CmdSend(quint8, quint32, quint32)));
	connect(this, SIGNAL(mcuCmdSend(quint8, quint32, quint32)), m_pWorker, SLOT(CmdSend4Mcu(quint8, quint32, quint32)));
	connect(this, SIGNAL( cmdSendClarity(quint32, quint32, quint32) ), m_pWorker, SLOT( CmdSendClarity(quint32, quint32, quint32)) );
	connect(this, SIGNAL(ackClarity(quint8)), m_pWorker, SLOT(sendAckClarity(quint8)) );
	connect(m_pWorker, SIGNAL(process4Mcu( quint8, quint32, quint32, quint32)), this, SLOT(processCmd4Mcu(quint8, quint32, quint32, quint32)) );
	connect(m_pWorker, SIGNAL(process4Pc( quint8, quint32, quint32, quint32)), this, SLOT(processCmd4Pc(quint8, quint32, quint32, quint32)) );
	connect(m_pWorker, SIGNAL(process4PcClarity( quint8, quint32, quint32, quint32)), this, SLOT(processCmd4PcClarity(quint8, quint32, quint32, quint32)) );
	connect(m_pWorker, SIGNAL(communicationError(int)), this, SLOT(communicationError(int)) );

	setPcProtocol(DataBase::getInstance()->queryData("pcProtocol").toInt());

	
}




void CommunicationCoupling::sendMcuCmd(quint8 cmd, quint32 arg, quint32 add)
{
	emit(mcuCmdSend(cmd, arg, add));
}



void CommunicationCoupling::sendCmd(quint8 cmd, quint32 arg, quint32 add)
{
	emit(cmdSend(cmd, arg, add));
}


void CommunicationCoupling::sendCmdClarity(quint32 hAI, quint32 hPFC, quint32 hVal)
{
	emit( cmdSendClarity(hAI, hPFC, hVal) );
}

void CommunicationCoupling::processCmd4Pc(quint8 type, quint32 cmd, quint32 arg, quint32 add)
{
	QString strDisp("");
	//命令处理;
	switch( cmd )
	{
	case PFC_SET_FLOW://设置波长1;
		{
			m_pMachine->changeWaveLength(arg, MachineStat::EWLEN1);
		}
		break;
	case PFC_SET_FLOW2://设置波长2;
		{
			m_pMachine->changeWaveLength(arg, MachineStat::EWLEN2);
		}
		break;
	case PFC_RESET_AU://AU清零;
		{
			m_pMachine->setPercentOfRandS();
		}
		break;
	case PFC_TURNON_LIGHT://开关灯;
		{
			if(arg == 1)
				m_pMachine->setLampStat(MachineStat::ON);
			else
				m_pMachine->setLampStat(MachineStat::OFF);
		}
		break;
	case PFC_SET_TIMECONST://设置时间常数;
		{
			QStringList list;
			list<<"1"<<"2"<<"5"<<"10"<<"20"<<"50";
			QString data = QString::number(arg);
			int index = list.indexOf(data);
			if(index != -1)
				DataBase::getInstance()->updateDate("timeconst", QString::number(index));
		}
		break;
	case PFC_SET_RANGCONST:
		{
			int index = arg;
			DataBase::getInstance()->updateDate("range", QString::number(index));
		}
		break;
	case PFC_MOTOR_INIT://MCU初始化;
		{
			//qDebug()<<"4";
			m_pMachine->resetWaveAndAngle();
			m_pMachine->setWaveCtrlWordAndHome();
		}
		break;
	case PFC_READ_LICENSE:
		{
			qDebug()<<"5";
		}
		break;
	case PFC_READ_LGTIME://读氘灯运行时间;
		{
			m_pMachine->uploadTimeToPc(MachineStat::XEUSEDTIME, arg);
		}
		break;
	case PFC_READ_LGLICENSE:
		{
			qDebug()<<"7";
		}
		break;
	case PFC_READ_SYSTIME://同步PC时间;
		{
			m_pMachine->uploadTimeToPc(MachineStat::SYSTIME, arg);
		}
		break;
	case PFC_READ_AU:
		{
			qDebug()<<"9";
		}
		break;
	case PFC_WAVEADD_MOTOR:
		{
			m_pMachine->setStepTo(arg, 0);
		}
		break;
	case PFC_WAVEDEL_MOTOR:
		{
			m_pMachine->setStepTo(arg, 0x10);
		}
		break;
	case PFC_RESET_TIME:// 清空时间;
		{
			m_pMachine->clearTime(MachineStat::STARTUPTIME);
		}
		break;
	default:
		strDisp = QString("cmd not found;");
		break;
	}


}


void CommunicationCoupling::processCmd4Mcu(quint8 type, quint32 cmd, quint32 arg,quint32 add)
{
	QString strDisp;
	switch( cmd )
	{
	case MCU_SET_PARAM:
		{
			strDisp = QString("mcu set param;");
		}
		break;
	case MCU_MOTOR_INI://MCU初始化成功!
		{
			strDisp = QString("mcu motor ini;");
			m_pMachine->motorInitSuccess();
		}
		break;
	case MCU_SETWAV_TO://!!!!!!!!!!!!!!!!!!
		{
		}
		break;
	case MCU_READ_PARAM:
		{
			strDisp = QString("mcu read param;");
		}
		break;
		/*case MCU_READ_VERSION:
		{
		strDisp = QString("mcu read version;");
		}
		break;*/
	case MCU_READ_AU_VAL_1:
		{
			strDisp = QString("mcu read au val;");
			m_pMachine->setCurrentWave(0);
			m_pMachine->updateSampleVal(arg);
		}
		break;
	case MCU_READ_AU_VALB_1:
		{
			strDisp = QString("mcu read au val;");
			m_pMachine->setCurrentWave(0);
			m_pMachine->updateRefVal(arg);
		}
		break;
	case MCU_READ_AU_VAL_2://!!!!!!!!!!!!!!!!!!!!!
		{
			strDisp = QString("mcu read au val;");
			m_pMachine->setCurrentWave(1);
			m_pMachine->updateSampleVal(arg);
		}
		break;
	case MCU_READ_AU_VALB_2://!!!!!!!!!!!!!!!!!!!!!!!
		{
			strDisp = QString("mcu read au val;");
			m_pMachine->setCurrentWave(1);
			m_pMachine->updateRefVal(arg);
		}
		break;
	default:
		strDisp = QString("mcu command not found;");
		break;
	}
}

void CommunicationCoupling::communicationError(int error)
{
	m_pMachine->sysError(COMUNICATION_ERR, error);
}

void CommunicationCoupling::setPcProtocol(int idx)
{
	m_pWorker->setPcProtocol(idx);
}

void CommunicationCoupling::processCmd4PcClarity(quint8 hID, quint32 hAI, quint32 hPFC,quint32 hVal)
{
	QString strDisp("");

	//命令处理;
	switch( hPFC )
	{
		//以下需要回复数据;
	case PFCC_READ_PRODUCT_ID:
		{
			strDisp = QString("read ID");
			sendCmdClarity(0,PFCC_READ_PRODUCT_ID,ID);
		}
		break;
	case PFCC_READ_LICENSE_H:
		{
			//strDisp = QString("read licnese h");
			quint64 license = DataBase::getInstance()->queryData("license").toULong();
			license/=1000000;
			license = DectoBCD(license,6);
			sendCmdClarity(0,PFCC_READ_LICENSE_H,license);
		}
		break;
	case PFCC_READ_LICENSE_L:
		{
			quint64 license = DataBase::getInstance()->queryData("license").toULong();
			license%=1000000;
			license = DectoBCD(license,6);
			sendCmdClarity(0,PFCC_READ_LICENSE_L,license);
		}
		break;
	case PFCC_READ_STATUS1:
		{

			/*00XXXX：氘灯关状态
			01XXXX：氘灯开状态
			10XXXX：乌灯关状态
			11XXXX：乌灯开状态
			XXXX为当前检测器波长，190～700nm
			*/
			quint32 val = m_pMachine->getMachineStat1();
			sendCmdClarity(0,PFCC_READ_STATUS1,val);
		}
		break;
	case PFCC_READ_STATUS2:
		{
			quint32 val = m_pMachine->getMachineStat2();
			sendCmdClarity(0,PFCC_READ_STATUS2,val);
		}
		break;
	case PFCC_READ_SFVERSION:
		{
			strDisp = QString("read software version");
			sendCmdClarity(0,PFCC_READ_SFVERSION,1);
		}
		break;
	case PFCC_READ_REF:
		{
			//strDisp = QString("read ref");
			quint32 sampleVal =m_pMachine->getSamleVal();
			sampleVal = 74746;
			sendCmdClarity(0,PFCC_READ_REF,sampleVal);
		}
		break;
	case PFCC_READ_SIG:
		{
			uint32 refVal =m_pMachine->getRefVal();
			sendCmdClarity(0,PFCC_READ_SIG,refVal);
		}
		break;
		//以下需要回复ACK或者NACK
	case PFCC_SET_WAVE:
		{
			m_pMachine->changeWaveLength(QString::number(hVal, 16).toDouble(), MachineStat::EWLEN1);
			sendClarityACK();
		}
		break;
	case PFCC_SET_TIMECST:
		{
			QStringList list;
			list<<"1"<<"2"<<"5"<<"10"<<"20"<<"50";
			QString data = QString::number(hVal,16);
			int index = list.indexOf(data);
			if(index != -1)
				DataBase::getInstance()->updateDate("timeconst", QString::number(index));
			sendClarityACK();
		}
		break;

	case PFCC_SET_OUTPUTRNG:
		{
			int index = QString::number(hVal,16).toInt();
			DataBase::getInstance()->updateDate("range", QString::number(index));
			sendClarityACK();
		}
		break;
	case PFCC_SET_SYNCTIME:
		{
			strDisp = QString("max press;");
			sendClarityACK();
		}
		break;
	case PFCC_SET_LIGHTON:
		{
			m_pMachine->setLampStat(MachineStat::ON);
			sendClarityACK();
		}
		break;
	case PFCC_SET_LIGHTOFF:
		{
			m_pMachine->setLampStat(MachineStat::OFF);
			sendClarityACK();
		}
		break;
	case PFCC_WAVE_INI:
		{
			m_pMachine->resetWaveAndAngle();
			m_pMachine->setWaveCtrlWordAndHome();
			sendClarityACK();
		}
		break;
	case PFCC_AUTO_CLEAR:
		{
			m_pMachine->setPercentOfRandS();
			sendClarityACK();
		}
		break;
	case PFCC_SET_AUFREQ:
		{
			//设置上传频率;
			m_pMachine->setUploadAuFreq(hVal);
			sendClarityACK();
		}
		break;
	case PFCC_SET_OUTPUTEV:
		{
			strDisp = QString("set mode;");
			sendClarityACK();
		}
		break;
	case PFCC_SET_LIGHT:
		{
			m_pMachine->changeLampSrc(hVal);
			sendClarityACK();
		}
		break;
	default:
		strDisp = QString("命令无法识别...;");
		break;
	}
	qDebug()<<strDisp;
}

void CommunicationCoupling::sendClarityACK()
{
	emit( ackClarity(1) );
}

void CommunicationCoupling::sendClarityNAK()
{
	emit( ackClarity(0) );
}




