#ifndef COMMUNICATIONCOUPLING_H
#define COMMUNICATIONCOUPLING_H

#include <QObject>
#include "Communication/Device.h"
#include "Communication/LogicThread.h"

class MachineStat;

class CommunicationCoupling : public QObject
{
	Q_OBJECT

public:
	CommunicationCoupling(MachineStat *parent);
	~CommunicationCoupling();

	void sendMcuCmd(quint8, quint32, quint32);				//����MCU����;
	void sendCmd(quint8, quint32, quint32);					//������λ������;
	void sendCmdClarity(quint32 hAI, quint32 hPFC, quint32 hVal);		//������λ������(Clarity);
	void setPcProtocol(int idx);							//������λ����ͨѶЭ��;


private:
	Worker *m_pWorker;										//��̨�߼�����;
	MachineStat *m_pMachine;								//����״̬;
	void sendClarityACK();									//���ͻ�Ӧ�ź�;
	void sendClarityNAK();									//���ʹ����ź�;

	void initCommunication();								//ͨѶ��ʼ��;


private slots:
	void processCmd4Mcu(quint8 type, quint32 cmd, quint32 arg,quint32 add);
	void processCmd4Pc( quint8 type, quint32 cmd, quint32 arg,quint32 add);
	void processCmd4PcClarity( quint8 hID, quint32 hAI, quint32 hPFC,quint32 hVal);
	void communicationError(int reSend);
	
signals:
	void mcuCmdSend(quint8, quint32, quint32);
	void cmdSend(quint8, quint32, quint32);
	void cmdSendClarity(quint32, quint32, quint32);
	void ackClarity(quint8 ack);

};

#endif // COMMUNICATIONCOUPLING_H