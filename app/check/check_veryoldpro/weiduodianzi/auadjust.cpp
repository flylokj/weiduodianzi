#include "auadjust.h"
#include <QTime>
#include <QDebug>

AuAdjust::AuAdjust(QObject *parent)
	: QObject(parent)
	, m_bUpdateDoubleAuList(false)
	, m_bUpdateSingleAuList(false)
{
	/*for (int i = 0; i < 100; i++)
	{
	m_singleAulist.append(0);
	}*/
}

AuAdjust::~AuAdjust()
{

}

AuAdjust* AuAdjust::getInstance()
{
	static AuAdjust *pAuAdjust = NULL;
	if(!pAuAdjust)
		pAuAdjust = new AuAdjust;
	return pAuAdjust;
}

void AuAdjust::updateAuVal( int which, double auVal )
{
	//�ж�which�Ƿ���Ч������ʶ;
	if(which > 1)//0����1��1����2;
		return;

	//�鿴��ǰ�б��Ƿ���Ч����
	if(!checkValidity(which))
		return;

	//qDebug()<<"add au"<<which<<":"<<auVal;
	//����ʱ����;
	insertIntoTimeLine(which, auVal);
}

void AuAdjust::generateAuVal()
{
	//��������Ч��;
	if(!m_doubleAuList.isEmpty())
	{
		//qDebug()<<"empty...";
		return;
	}
	if(!m_bUpdateDoubleAuList)
	{
		//qDebug()<<"m_bUpdateDoubleAuList";
		return;
	}
	if(m_timeLine.count() < 4)
	{
		//qDebug()<<".........<4";
		return;
	}
	
	//qDebug()<<".....................generate";

	//��λ���±�־λ;
	m_bUpdateDoubleAuList = false;

	//�������ɴ������;
	AuNode node1 = m_timeLine.at(0);
	AuNode node2 = m_timeLine.at(1);
	AuNode node3 = m_timeLine.at(2);
	AuNode node4 = m_timeLine.at(3);

	if(node1.which != node3.which)
		return;

	if(node2.which != node4.which)
		return;

	double k1 = (node3.dAuVal - node1.dAuVal)/(node3.msec - node1.msec);
	double k2 = (node4.dAuVal - node2.dAuVal)/(node4.msec - node2.msec);

	int begin = node2.msec;
	int end = node3.msec;

	int which = node1.which;
	for (int i = begin; i < end; i+=50 )
	{
		DoubleAu doubleAu;
		double au1 = k1*(i-node1.msec) + node1.dAuVal;
		double au2 = k2*(i-begin) + node2.dAuVal;

		if( which != 0 )
			qSwap(au1, au2);

		doubleAu.dAu1 = au1;
		doubleAu.dAu2 = au2;
		m_doubleAuList.append(doubleAu);
		if(m_doubleAuList.count() > 30 )
			m_doubleAuList.removeFirst();
	}
}

bool AuAdjust::getdoubleAuVal( double *pAu1, double *pAu2 )
{
	//�鿴timeline�������µ�����;
	generateAuVal();

	//���auֵ�����Ƿ�������;
	if(m_doubleAuList.isEmpty())
		return false;

	//�Ӷ���ɾ���Ѿ���ȡ��auֵ;
	DoubleAu doubleAu = m_doubleAuList.takeFirst();

	//��д����;
	*pAu1 = doubleAu.dAu1;
	*pAu2 = doubleAu.dAu2;

	return true;
}

void AuAdjust::updateAuValSingle( double auVal )
{
	//����ʱ����;
	insertIntoTimeLineSingle(auVal);
}

void AuAdjust::generateAuValSingle()
{
	//qDebug()<<"@@@@22222222222222222222";
	//��������Ч��;
	if( !m_singleAulist.isEmpty() )
	{
		//qDebug()<<"@@@@22222222222222222222----------000000000000";
		return;
	}
	if(!m_bUpdateSingleAuList)
	{
		//qDebug()<<"@@@@22222222222222222222----------11111111111";
		return;
	}
	if(m_timeLineSingle.count() < 2)
	{
		//qDebug()<<"@@@@22222222222222222222----------222222222222222"<<"  "<<m_timeLineSingle.count();
		return;
	}
	//qDebug()<<"@@@@333333333333333333333333";
	//qDebug()<<".....................generate";

	//��λ���±�־λ;
	m_bUpdateSingleAuList = false;

	//�������ɴ������;
	AuNode node1 = m_timeLineSingle.at(0);
	AuNode node2 = m_timeLineSingle.at(1);
	//qDebug()<<"@@@@44444444444444444444444444444444";
	double k1 = (node2.dAuVal - node1.dAuVal)/(node2.msec - node1.msec);

	int begin = node1.msec;
	int end = node2.msec;
	//qDebug()<<"@@@@55555555555555555555555555555";
	for (int i = begin; i < end; i+=50 )
	{
		double au = k1*(i-node1.msec) + node1.dAuVal;
		m_singleAulist.append(au);
		if( m_singleAulist.count() > 30 )
			m_singleAulist.removeFirst();
	}
	//qDebug()<<"@@@@66666666666666666666666666666666666";
}

bool AuAdjust::getAuValSingle( double *pAu1 )
{
	//qDebug()<<"@@@@1111111111111111111111";
	//�鿴timeline�������µ�����;
	generateAuValSingle();
	//���auֵ�����Ƿ�������;
	//qDebug()<<"@@@@yyyyyyyyyyyyyyyyyyyyyyyyy";
	if( m_singleAulist.isEmpty())
		return false;
	//qDebug()<<"@@@@xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	//�Ӷ���ɾ���Ѿ���ȡ��auֵ;
	//double au = m_singleAulist.takeAt(0);
	//qDebug()<<m_singleAulist;
	//qDebug()<<"@@@@###########################"<<m_singleAulist.count();
	double au = 0;
	if(m_singleAulist.count() > 0)
	{
		au = m_singleAulist.takeFirst();
	}
	//qDebug()<<"@@@@remove.................................";
	//��д����;
	*pAu1 = au;

	return true;
}

void AuAdjust::clear()
{
	m_timeLine.clear();
	m_timeLineSingle.clear();
}

bool AuAdjust::checkValidity( int which )
{
	int cnt = m_timeLine.count();
	if(cnt == 0)
	{
		return true;
	}
	else
	{
		if( m_timeLine.last().which != which )
			return true;
		else
			return false;
	}
}

void AuAdjust::insertIntoTimeLine( int which, double dAuVal )
{
	//����ڵ�;
	AuNode node;
	node.which = which;
	node.dAuVal = dAuVal;
	node.msec = QTime(0,0).msecsTo(QTime::currentTime());
	m_timeLine.append(node);

	//���±�ʶλ;
	m_bUpdateDoubleAuList = true;
	//qDebug()<<"m_bUpdateDoubleAuList = true";

	//�����еĳ��ȣ�����4����ɾ�����һ����
	if( m_timeLine.count() > 4 )
		m_timeLine.removeFirst();
}

void AuAdjust::insertIntoTimeLineSingle( double dAuVal )
{
	//����ڵ�;
	AuNode node;
	node.which = 0;
	node.dAuVal = dAuVal;
	node.msec = QTime(0,0).msecsTo(QTime::currentTime());
	m_timeLineSingle.append(node);

	//���±�ʶλ;
	m_bUpdateSingleAuList = true;

	//�����еĳ��ȣ�����2����ɾ�����һ��
	if( m_timeLineSingle.count() > 2 )
	{
		m_timeLineSingle.removeFirst();
		
		// /*for(int i = 0; i < m_timelinesingle.count(); i++)
		// {
			// qdebug()<<"time:"<<m_timelinesingle.at(i).msec<<"---"<<"val:"<<m_timelinesingle.at(i).dauval;
		// }*/
	}
	
}
