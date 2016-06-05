#include "runparam.h"
#include <QDebug>
#include "Common.h"
#include "database.h"
#include "machinestat.h"

RunParamPage::RunParamPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("GradientPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("RunParam");
}

RunParamPage::~RunParamPage()
{

}


void RunParamPage::initFocusList()
{
	xList.append(ui.wLen1Edit);
	xList.append(ui.wLen2Edit);
	xList.append(ui.chlCombo);
	xList.append(ui.lhtCombo);
	xList.append(ui.rangeCombo);
	xList.append(ui.timeCombo);
	xList.append(ui.lpBtn);
	//xList.append(ui.lampEdit);
	xList.append(ui.sDispCombo);
	xList.append(ui.rDispCombo);

	yList.append(ui.lpBtn);
	yList.append(ui.wLen1Edit);
	yList.append(ui.chlCombo);
	yList.append(ui.rangeCombo);
	//yList.append(ui.lampEdit);
	yList.append(ui.wLen2Edit);
	yList.append(ui.lhtCombo);
	yList.append(ui.timeCombo);
	yList.append(ui.sDispCombo);
	yList.append(ui.rDispCombo);

	ui.wLen1Edit->setValRange(QString("wavelen1"),190,800, 0);
	ui.wLen2Edit->setValRange(QString("wavelen2"),190,800, 0);
	ui.lampEdit->setValRange(QString("lampcha"),0,1000,0);
	ui.wLen1Edit->disableAutoSave();
	ui.wLen2Edit->disableAutoSave();

	ui.chlCombo->setVar(QString("chanel"));
	ui.lhtCombo->setVar(QString("xe_tun"));
	ui.rangeCombo->setVar(QString("range"));
	ui.timeCombo->setVar(QString("timeconst"));
	ui.sDispCombo->setVar(QString("sampleDisp"));
	ui.rDispCombo->setVar(QString("refDisp"));

	connect(ui.wLen1Edit, SIGNAL(dataChanging(QString)), this, SLOT(waveLen1Changed(QString)));
	connect(ui.wLen2Edit, SIGNAL(dataChanging(QString)), this, SLOT(waveLen2Changed(QString)));
	connect(ui.chlCombo, SIGNAL(currentIndexChanged(int )), this, SLOT(chanelChnaged(int)));
	connect(ui.lhtCombo, SIGNAL(currentIndexChanged(int)), MachineStat::getInstance(), SLOT(changeLampSrc(int)));

	setStyleSheet(BTNGLOBALSTYLE);
}

void RunParamPage::on_lpBtn_clicked()
{
	int cnt = DataBase::getInstance()->queryData("lampcha").toInt();
	cnt++;
	DataBase::getInstance()->updateDate("lampcha", QString::number(cnt));
	int nLampWhich = DataBase::getInstance()->queryData("xe_tun").toInt();

	//记录灯的使用记录(灯的类型、灯的结束使用日期、灯的时间)
	QString strLamp;
	QString strTime;
	QString strEndDate = QDate::currentDate().toString(Qt::ISODate);
	if( nLampWhich == 0 )
	{
		strLamp = "Deu.Lamp";
		strTime = QString("%1h").arg(MachineStat::getInstance()->getTime(MachineStat::XEUSEDTIME)/3600);
		MachineStat::getInstance()->clearTime(MachineStat::XEUSEDTIME);
	}
	else
	{
		strLamp = "Tung.Lamp";
		strTime = QString("%1h").arg(MachineStat::getInstance()->getTime(MachineStat::TUNUSEDTIME)/3600);
		MachineStat::getInstance()->clearTime(MachineStat::TUNUSEDTIME);
	}

	//插入到数据库中
	DataBase::getInstance()->insertLampHistoryRecord(strLamp, strTime, strEndDate);
}

CBasePage* RunParamPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new RunParamPage(parent, index, previndex, add);
}

void RunParamPage::waveLen1Changed(QString str)
{
	if( MachineStat::EStat_Busy == MachineStat::getInstance()->changeWaveLength(ui.wLen1Edit->text().toDouble(), MachineStat::EWLEN1 ) )
		ui.wLen1Edit->restoreData();
}

void RunParamPage::chanelChnaged( int ch)
{
	MachineStat::getInstance()->chanelChanged(ch);
}

void RunParamPage::waveLen2Changed(QString str)
{
	quint8 chanel = DataBase::getInstance()->queryData("chanel").toInt();
	if(chanel == 0)//单波长;
	{
		ui.wLen2Edit->saveData(ui.wLen2Edit->text());
	}
	else
	{
		if( MachineStat::EStat_Busy == MachineStat::getInstance()->changeWaveLength(ui.wLen2Edit->text().toDouble(), MachineStat::EWLEN2 ) )
		{	
			ui.wLen2Edit->restoreData();
		}
	}
}



