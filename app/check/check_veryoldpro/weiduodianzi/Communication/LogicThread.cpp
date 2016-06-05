#include "LogicThread.h"
#include "Communication/Protocol.h"
#include <QString>
#include "baseMainPage.h"

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
	moveToThread(&m_workerThread);
	g_pWorker = this;
	m_nResendTimeout = 0;
	m_nResendCnt = 0;
	m_workerThread.start();
}



Worker::~Worker()
{
	
}



void Worker::timeoutFunc()
{
	static bool errorFlag = false;

#if 1
	if(sendList4Mcu.count() > 0)
	{
		if(++m_nResendTimeout >3)
		{
			m_nResendTimeout = 0;
			QList<quint32>list = sendList4Mcu.at(0);
			API_McuCmdSend(list.at(0), list.at(1),list.at(2));

			m_nResendCnt++;
			if(m_nResendCnt > 5)
			{
				errorFlag = true;
				emit(communicationError(1));
			}
			
		}
	}
	else
	{
		m_nResendTimeout = 0;
		m_nResendCnt = 0;
		if(errorFlag)
		{
			errorFlag = false;
			emit(communicationError(0));
		}
	}
#endif

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

	//����Э��;
	if(data.size() > 0)
	{
		if(m_nPcProtocol == 0)
			API_Protocol((mbyte *)data.data(), data.size());				//������Э��;
		else
			API_ClarityProtocol((mbyte *)data.data(), data.size());		//�����µ�Э��;
			

	}

	if(data2.size() > 0)
		API_McuProtocol((mbyte *)data2.data(), data2.size());//MCUЭ�����;


}



void Worker::processCmd4Pc( mbyte type, uint32 cmd, uint32 arg, uint32 add)
{
	emit(process4Pc(type, cmd, arg, add));
}




void Worker::processCmd4Clarity(mbyte hID, mbyte hAI, mbyte hPFC, uint32 nVal)
{
	emit( process4PcClarity(hID, hAI, hPFC, nVal) );
}



void Worker::processCmd4Mcu(mbyte type, uint32 cmd, uint32 arg,uint32 add)
{
	emit(process4Mcu( type, cmd, arg, add));
}


void Worker::CmdSend(quint8 type, quint32 cmd, quint32 arg)
{
	if(m_nPcProtocol == 0)//��Э��;
	{
		if(type == CMD_ASCII_SINGLEWAV || type == CMD_ASCII_SVAL || type == CMD_ASCII_RVAL)
			uploadAuToPc(0,cmd, arg);
		else if(type == CMD_ASCII_DOUBLEWAV)
			uploadAuToPc(1,cmd, arg);
		else if(type == CMD_SYNC_COLLECT)//ʹ��λ������Զ�����ɼ�ͼ��
			syncPCtoCollect();
		else
			API_CmdSend(type, cmd, arg);
	}
	else
	{
		
			
	}
	
}



void Worker::CmdSendClarity(quint32 hAI, quint32 hPFC, quint32 hVal)
{
	API_CmdSendClarity(hAI, hPFC, hVal);
}



//���뷢�Ͷ���;
void Worker::CmdSend4Mcu(quint8 type, quint32 cmd, quint32 arg)
{
	QList<quint32>list;
	list.append(type);
	list.append(cmd);
	list.append(arg);
	API_McuCmdSend(list.at(0), list.at(1),list.at(2));
	qDebug()<<"------------";
	qDebug()<<list;
	sendList4Mcu.append(list);

}


void Worker::check4Mcu( uint32 cmd )
{
	//qDebug()<<QThread::currentThread();
	//qDebug()<<sendList4Mcu.count();
	
	if(sendList4Mcu.count() > 0)
	{
		/*for (int i = 0; i < sendList4Mcu.count(); i++)
		{
			qDebug()<<"!!!!!!before!!!!!!!!";
			qDebug()<<sendList4Mcu.at(i);
			qDebug()<<"!!!!!!!!!!!!!!!!";
		}*/
		
		if((cmd&0x0f) == sendList4Mcu.at(0).at(1))
			sendList4Mcu.removeAt(0);

		if(sendList4Mcu.count() == 0)
		{
			m_nResendTimeout = 0;
			m_nResendCnt = 0;
		}

		/*for (int i = 0; i < sendList4Mcu.count(); i++)
		{
		qDebug()<<"!!!!!!after!!!!!!!!";
		qDebug()<<sendList4Mcu.at(i);
		qDebug()<<"!!!!!!!!!!!!!!!!";
		}*/
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


void Worker::uploadAuToPc(quint8 chanel, quint32 au , quint32 au2)
{
	//�ֵ�˫����;
	QByteArray data;
	if(chanel == 0)//������;
	{
		data.append(0x53);
		data.append(0x4d);
		data.append(0x20);
		data.append(QString("%1").arg(au,6,16,QLatin1Char('0')).toUpper().toAscii());
		data.append(0x0d);
		data.append(0x7f);
	}
	else//˫����;
	{
		data.append(0x53);
		data.append(0x4d);
		data.append(0x20);
		data.append(QString("%1").arg(au,6,16,QLatin1Char('0')).toUpper().toAscii());
		data.append(0x0d);

		data.append(0x53);
		data.append(0x6d);
		data.append(0x20);
		data.append(QString("%1").arg(au2,6,16,QLatin1Char('0')).toUpper().toAscii());
		data.append(0x0d);
		data.append(0x7f);
	}
	
	writeFunc((quint8 *)data.data(), data.size());
}

void Worker::syncPCtoCollect()
{
	QByteArray data;
	data.append(0x53);
	data.append(0x58);
	data.append(0x0d);
	data.append(0x7f);
	writeFunc((quint8 *)data.data(), data.size());
}

void Worker::sendAckClarity(quint8 ack)
{
	ack ? SendACK() : SendNAK();
}



