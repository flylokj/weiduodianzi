#include "communicationcoupling.h"
#include "machinestat.h"
#include "timehelper.h"

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




void CommunicationCoupling::sendClarityACK()
{
	emit( ackClarity(1) );
}

void CommunicationCoupling::sendClarityNAK()
{
	emit( ackClarity(0) );
}

void CommunicationCoupling::sendMcuCmd(quint8 cmd, quint32 arg, quint32 add)
{
	emit(mcuCmdSend(cmd, arg, add));
}



void CommunicationCoupling::sendCmd(quint8 cmd, quint32 arg, quint32 add)
{
	emit(cmdSend(cmd, arg, add));
}



void CommunicationCoupling::sendCmdClarity( quint32 hAI, quint32 hPFC, quint32 hVal )
{
	emit( cmdSendClarity(hAI, hPFC, hVal) );
}

void CommunicationCoupling::processCmd4Pc(quint8 type, quint32 cmd, quint32 arg, quint32 add)
{
	//TimeHelper::getComSem()->acquire();
	QString strDisp("");
	//命令处理;
	switch( cmd )
	{
		//以下需要回复数据;
	case PFC_SET_FLOW1:
		{
			int pumpType = m_pMachine->getPumpType();
			arg = arg & 0x3fff;
			double val=0;
			switch(pumpType)
			{
			case 0:
			case 1:
				val = (double)arg/1000.0;
			break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				val = (double)arg/10.0;
				break;
			default:
				return;
			}

			strDisp = QString("set flow1");
			m_pMachine->updateFlowPercent(add, MachineStat::PC_MODE);
			m_pMachine->updateFlow(val, MachineStat::PC_MODE);
			
		}
		break;
	case PFC_SET_MAXPRESS:
		{
			strDisp = QString("set maxpress");
			QString data = QString::number((double)arg/100.0);
			DataBase::getInstance()->updateDate("maxpress", data);
		}
		break;
	case PFC_SET_MINPRESS:
		{
			strDisp = QString("set minpress");
			QString data = QString::number((double)arg/100.0);
			DataBase::getInstance()->updateDate("minpress", data);
		}
		break;
	case PFC_TIME_SYNC:
		{
			break;//屏蔽掉上位机时间同步;
			strDisp = QString("time sync");
			m_pMachine->syncTime(arg);
		}
		break;
	case PFC_START:
		{
			strDisp = QString("start");
			m_pMachine->setMachineStat(MachineStat::PCCTRL);
		}
		break;
	case PFC_STOP:
		{
			strDisp = QString("stop");
			m_pMachine->setMachineStat(MachineStat::STOP);
		}
		break;
	case PFC_READ_PRESS:
		{
			strDisp = QString("read press");
			m_pMachine->uploadPresVal();
		}
		break;
	default:
		strDisp = QString("cmd not found;");
		break;
	}
	//TimeHelper::getComSem()->release();
}


void CommunicationCoupling::processCmd4PcClarity( quint8 hID, quint32 hAI, quint32 hPFC,quint32 hVal )
{
#if 1
	//0x01是读取产品ID，因此不需要匹配ID;
	if(hPFC != PFCC_READ_PRODUCT_ID && hID != ID)
		return;


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
	case PFCC_READ_PUMPSTATUS:
		{
			strDisp = QString("read pump stat");
			quint32 val = m_pMachine->pcGetMachineStat();
			sendCmdClarity(0,PFCC_READ_PUMPSTATUS,val);
		}
		break;
	case PFCC_READ_PUMPFIX:
		{
			strDisp = QString("read pump fix");
		}
		break;
	case PFCC_READ_PUMPTIME:
		{
			strDisp = QString("read pump time");
		}
		break;
		//以下需要回复ACK或者NACK
	case PFCC_SET_FLOW:
		{
			strDisp = QString("set flow");
			double flow = hVal/1000.0;
			m_pMachine->updateFlow(flow, MachineStat::PC_MODE);
			sendClarityACK();
		}
		break;
	case PFCC_SET_FLOWPERCENT:
		{
			strDisp = QString("set flow percent");
			double percent = hVal/10.0;
			m_pMachine->updateFlowPercent(percent);
		}
		break;

	case PFCC_SYNCTIME:
		{
			strDisp = QString("time sync;");
		}
		break;
	case PFCC_MAX_PRESS:
		{
			strDisp = QString("max press;");
			QString data = QString::number((double)hVal/100.0);
			DataBase::getInstance()->updateDate("maxpress", data);
			sendClarityACK();
		}
		break;
	case PFCC_MIN_PRESS:
		{
			strDisp = QString("min press;");
			QString data = QString::number((double)hVal/100.0);
			DataBase::getInstance()->updateDate("minpress", data);
			sendClarityACK();
		}
		break;
	case PFCC_PUMPSTART:
		{
			strDisp = QString("pump start;");
			m_pMachine->setMachineStat(MachineStat::PCCTRL);
			sendClarityACK();
		}
		break;
	case PFCC_PUMPSTOP:
		{
			m_pMachine->setMachineStat(MachineStat::STOP);
			sendClarityACK();
		}
		break;
	case PFCC_PRESSCLEAR:
		{
			strDisp = QString("press clear;");
		}
		break;
	case PFCC_READ_PRESS:
		{
			strDisp = QString("read press;");
		}
		break;
	case PFCC_SET_MODE:
		{

			strDisp = QString("set mode;");
		}
		break;
	case PFCC_SET_FLOWFIX:
		{

			strDisp = QString("set flow fix;");
		}
		break;
		//主动发送;
	case PFCC_SEND_PRESS:
		{
			strDisp = QString("send press;");
		}
		break;
	case PFCC_INPUT_EVENT:
		{

			strDisp = QString("input event;");
		}
		break;
	case PFCC_SYS_ERR:
		{

			strDisp = QString("sys error;");
		}
		break;

	default:
		strDisp = QString("命令无法识别...;");
		//SendNAK();
		break;
	}
	qDebug()<<strDisp;

#endif
}

void CommunicationCoupling::communicationError(int error)
{
	m_pMachine->sysError(COMUNICATION_ERR, error);
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
	case MCU_MOTOR_INI:
		{
			strDisp = QString("mcu motor ini;");
		}
		break;
	case MCU_WAVEADD_MOTOR:
		{

		}
		break;
	case MCU_WAVEDEC_MOTOR:
		{

		}
		break;
	case MCU_READ_PARAM:
		{
			strDisp = QString("mcu read param;");
		}
		break;
	case MCU_READ_VERSION:
		{
			strDisp = QString("mcu read version;");
		}
		break;
	case MCU_READ_AU_VAL:
		{
			strDisp = QString("mcu read au val;");
			m_pMachine->updatePresVal(arg);
		}
		break;
	default:
		strDisp = QString("mcu command not found;");
		break;
	}
}

void CommunicationCoupling::setPcProtocol(int idx)
{
	m_pWorker->setPcProtocol(idx);
}

void CommunicationCoupling::setPumpTypeForPcFlowCtrl( int nPump )
{
	sendCmd(PROTOCL_LOCAL_USE_CHANGE_PUMPTYPE, nPump, 0);
}
