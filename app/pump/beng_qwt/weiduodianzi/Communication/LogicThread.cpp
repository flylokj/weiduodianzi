#include "LogicThread.h"
#include "Communication/Protocol.h"
#include <QString>
#include "baseMainPage.h"
#include "timehelper.h"

#ifdef linux
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <asm-generic/ioctl.h>
#include <fcntl.h>


static int fd = -1;
static unsigned long temp_read = 0;
#endif


#ifdef WIN32
#define MAINCOMPORT		"COM2"//��λ��ͨѶ�ӿ�
#define MCUCOMPORT		"COM4"//��Ƭ��ͨѶ�ӿ�
#elif linux
#define MAINCOMPORT		"/dev/ttySAC2"//��λ��ͨѶ�ӿ�
#define MCUCOMPORT		"/dev/ttySAC1"//��Ƭ��ͨѶ�ӿ�
#endif


Worker *g_pWorker;


#ifdef WIN32
Win_QextSerialPort *myCom = 0;
#ifdef COMMUNICATION_WITH_MCU
Win_QextSerialPort *mcuCom = 0;//��װ�MCUͨѶ;
#endif
#elif linux
Posix_QextSerialPort *myCom = 0;
#ifdef COMMUNICATION_WITH_MCU
Posix_QextSerialPort *mcuCom = 0;//��װ�MCUͨѶ;
#endif
#endif





uint16 writeFunc( quint8* data, uint16 sz )
{
	//qDebug()<<QThread::currentThreadId()<<"send func";

	if(myCom)
		myCom->write((const char*)data, sz);

	return 0;
}

void processFunc( mbyte type, uint32 cmd, uint32 arg, quint32 add)
{
	g_pWorker->processCmd4Pc( type, cmd, arg, add);
}


void processFunc4Clarity(  mbyte hID, mbyte hAI, mbyte hPFC, uint32 nVal )
{
	g_pWorker->processCmd4Clarity( hID, hAI, hPFC, nVal);
}


//*****************MCUͨѶ********************************/
uint16 writeFunc4Mcu( quint8* data, uint16 sz )
{
#ifdef COMMUNICATION_WITH_MCU
	if(mcuCom)
		mcuCom->write((const char*)data, sz);
#endif
	return 0;
}

void processFunc4Mcu( mbyte type, uint32 cmd, uint32 arg, quint32 add )
{
	g_pWorker->processCmd4Mcu( type, cmd, arg, add);
}

void checkFunc4Mcu(uint32 cmd)
{
	g_pWorker->check4Mcu(cmd);
}



/*************************************************Worker*********************************************************/

Worker::Worker(QObject *parent /*= 0*/)
{
	setupCommunication();
	m_pTimer = new QTimer(this);
	QObject::connect(m_pTimer, SIGNAL(timeout()), this, SLOT(timeoutFunc()) );//��ʱ��ȡ����;
	startTimer();
	//connect(mcuCom, SIGNAL(readyRead()), this, SLOT(timeoutFunc()));
	moveToThread(&m_workerThread);
	g_pWorker = this;
	m_nResendTimeout = 0;
	m_workerThread.start();
}



Worker::~Worker()
{
	
}



void Worker::timeoutFunc()
{

	static bool errorFlag = false;
	if(sendList4Mcu.count() > 0)
	{
		if(++m_nResendTimeout >20)
		{
			m_nResendTimeout = 0;
			errorFlag = true;
			QList<quint32>list = sendList4Mcu.at(0);
			API_McuCmdSend(list.at(0), list.at(1),list.at(2));
			emit(communicationError(1));
		}
	}
	else
	{
		m_nResendTimeout = 0;
		if(errorFlag)
		{
			errorFlag = false;
			emit(communicationError(0));
		}
	}



	//���Ͷ�ȡѹ��ֵ����;
	static int nReadPressPeriod = 0;
	if(nReadPressPeriod++ > 7 )
	{
		nReadPressPeriod = 0;
		API_McuCmdSend(PROTOCL_CMD, MCU_READ_AU_VAL,0);
	}
	


	QByteArray data;
	QByteArray data2;

	if(myCom)
		data  = myCom->readAll();

#ifdef COMMUNICATION_WITH_MCU
	if(mcuCom)
		data2 = mcuCom->readAll();
#endif



#if 0
	{
		qDebug()<<"recv:"<<data.size();
		QString temp;
		for(int i = 0; i < data.size(); i++)
			temp+=QString(" %1").arg( (quint8)data.at(i) );
		qDebug()<<temp;
	}
#endif
#if 0
	{
		if(data2.size())
		{
			qDebug()<<"mcu port recv:"<<data2.size();
			QString temp;
			for(int i = 0; i < data2.size(); i++)
			{
				quint8 d = (quint8)(data2.at(i));
				//temp+=QString(" %1").arg(d);
				temp += QString::number(data2.at(i),16).right(2)+"-";
			}
			qDebug()<<temp;
		}
		
	}
#endif

#if 1
	//����Э��;
	if(data.size() > 0)
	{
		if(m_nPcProtocol == 0)
			API_Protocol((mbyte *)data.data(), data.size());			//������Э��;
		else
			API_ClarityProtocol((mbyte *)data.data(), data.size());	//������Э��;
	}
#endif

#if 1
	if(data2.size() > 0)
		API_McuProtocol((mbyte *)data2.data(), data2.size());//MCUЭ�����;
#endif

}



void Worker::processCmd4Pc( mbyte type, uint32 cmd, uint32 arg, uint32 add)
{
	//TimeHelper::getComSem()->acquire();
	emit(process4Pc(type, cmd, arg, add));
	//TimeHelper::getComSem()->release();
}




void Worker::processCmd4Clarity(mbyte hID, mbyte hAI, mbyte hPFC, uint32 nVal)
{
#if 1

	QString strDisp("");

	//�����;
	switch( hPFC )
	{
		//������Ҫ�ظ�����;
	case PFCC_READ_PRODUCT_ID:
		{
			strDisp = QString("read ID");
		}
		break;
	case PFCC_READ_LICENSE_H:
		{
			strDisp = QString("read licnese h");
		}
		break;
	case PFCC_READ_LICENSE_L:
		{
			strDisp = QString("read licnese l");
		}
		break;
	case PFCC_READ_PUMPSTATUS:
		{
			strDisp = QString("read pump stat");
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
		//������Ҫ�ظ�ACK����NACK
	case PFCC_SET_FLOW:
		{
			strDisp = QString("set flow");
		}
		break;
	case PFCC_SET_FLOWPERCENT:
		{
			strDisp = QString("set flow percent");
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
		}
		break;
	case PFCC_MIN_PRESS:
		{
			strDisp = QString("min press;");
		}
		break;
	case PFCC_PUMPSTART:
		{
			strDisp = QString("pump start;");
		}
		break;
	case PFCC_PUMPSTOP:
		{
			strDisp = QString("pump stop;");
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
	//��������;
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
		strDisp = QString("�����޷�ʶ��...;");
		//SendNAK();
		break;
	}
	qDebug()<<strDisp;

#endif
}



void Worker::processCmd4Mcu(mbyte type, uint32 cmd, uint32 arg,uint32 add)
{
	emit(process4Mcu( type, cmd, arg, add));
}


void Worker::CmdSend(quint8 type, quint32 cmd, quint32 arg)
{
	if(type == PROTOCL_LOCAL_USE_CHANGE_PUMPTYPE)
	{
		//�ı����,�Ӷ��ı���λ�����������ֽڳ��ȵ�ʶ��;
		API_SetPumpType(cmd);
	}
	else
		API_CmdSend(type, cmd, arg);
}





//���뷢�Ͷ���;
void Worker::CmdSend4Mcu(quint8 type, quint32 cmd, quint32 arg)
{
	QList<quint32>list;
	list.append(type);
	list.append(cmd);
	list.append(arg);
	sendList4Mcu.append(list);
}

void Worker::check4Mcu( uint32 cmd )
{
	//qDebug()<<QThread::currentThread();
	//qDebug()<<sendList4Mcu.count();
	if(sendList4Mcu.count() > 0)
	{
		if((cmd&0x0f) == sendList4Mcu.at(0).at(1))
			sendList4Mcu.removeAt(0);
	}
}

//ͨѶ׼��;
void Worker::setupCommunication()
{
	setupSerialCommunication();
	//ע��ͨѶ����;
	ProtocolConf proConf;
	proConf.write = writeFunc;								//ʵ�ִ˺���!!!!!!!!!!!!!!!!!!!!!;
	proConf.process = processFunc;							//ʵ�ִ˺���!!!!!!!!!!!!!!!!!���������;
	proConf.processClarity = processFunc4Clarity;			//������Э��������ݴ���;
	SetProtocolConf( &proConf, PROTOCOL_CONF_WRITEFUN|PROTOCOL_CONF_PROCESSFUN|PROTOCOL_CONF_PROCESSFUNCLARITY);

#ifdef COMMUNICATION_WITH_MCU
	//ע��MCUͨѶ����;
	Protocol4McuConf mcuProConf;
	mcuProConf.write = writeFunc4Mcu;
	mcuProConf.process = processFunc4Mcu;
	mcuProConf.checkCompare = checkFunc4Mcu;
	SetMcuProtocolConf(&mcuProConf, PROTOCOL_CONF_PROCESSFUN|PROTOCOL_CONF_WRITEFUN|PROTOCOL_CONF_CHECKFUN);
#endif

}



void Worker::setupSerialCommunication()
{
#ifdef COMMUNICATION_SERIAL
	//����һ���ṹ�壬������Ŵ��ڸ�������;
	struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};
	//���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��;
#ifdef WIN32
	myCom = new Win_QextSerialPort(MAINCOMPORT);
#ifdef COMMUNICATION_WITH_MCU
	mcuCom = new Win_QextSerialPort(MCUCOMPORT);
#endif
#elif linux
	myCom = new Posix_QextSerialPort(MAINCOMPORT,myComSetting,QextSerialBase::Polling);//LINUX�´����޷�ʹ���¼�����;
#ifdef COMMUNICATION_WITH_MCU
	mcuCom = new Posix_QextSerialPort(MCUCOMPORT,myComSetting,QextSerialBase::Polling);
#endif
#endif
	//�Կɶ�д��ʽ�򿪴���;
	myCom ->open(QIODevice::ReadWrite);	
	myCom->setTimeout(10);
	myCom->setBaudRate(BAUD9600);
	myCom->setDataBits(DATA_8);
	myCom->setStopBits(STOP_1);
	myCom->setParity(PAR_NONE);
	myCom->setFlowControl(FLOW_OFF);

#ifdef COMMUNICATION_WITH_MCU
	mcuCom->open(QIODevice::ReadWrite);
	mcuCom->setTimeout(10);
	mcuCom->setBaudRate(BAUD9600);
	mcuCom->setDataBits(DATA_8);
	mcuCom->setStopBits(STOP_1);
	mcuCom->setParity(PAR_NONE);
	mcuCom->setFlowControl(FLOW_OFF);
#endif

#endif


}

void Worker::startTimer()
{
	m_pTimer->start(TIMEOUT_PERIOD);
}

