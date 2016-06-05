#include "runpage.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "baseMainPage.h"

RunPage::RunPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("GradientPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = "RunPage";
	initDisplay();
}

RunPage::~RunPage()
{

}


void RunPage::initFocusList()
{
	xList.append(ui.lampCombo);
	xList.append(ui.wLen1Edit);

	if(DataBase::getInstance()->queryData("chanel").toInt() == 1)
		xList.append(ui.wLen2Edit);

	yList.append(ui.lampCombo);
	yList.append(ui.wLen1Edit);

	if(DataBase::getInstance()->queryData("chanel").toInt() == 1)
		yList.append(ui.wLen2Edit);
}



void RunPage::initDisplay()
{
	ui.wLen1Edit->setValRange(QString("wavelen1"),190,800, 0);
	ui.wLen2Edit->setValRange(QString("wavelen2"),190,800, 0);
	ui.wLen1Edit->disableAutoSave();
	ui.wLen2Edit->disableAutoSave();
	ui.sampleLbl->setText(QString::number( MachineStat::getInstance()->getSamleVal() ));
	ui.basicLbl->setText( QString::number( MachineStat::getInstance()->getRefVal() ) );
	ui.auLbl->setText(DataBase::getInstance()->queryData("au1"));
	ui.auLbl2->setText(DataBase::getInstance()->queryData("au2"));

	//qDebug()<<DataBase::getInstance()->queryData("au1");

	//隐藏单位;
	ui.label_9->hide();
	ui.label_10->hide();

	if(DataBase::getInstance()->queryData("chanel").toInt() == 0)
	{
		ui.wLen2Edit->hide();
		ui.wLen2Title->hide();
		ui.wLen2Unit->hide();

		ui.label_7->hide();
		ui.auLbl2->hide();
		//ui.label_10->hide();
	}

	if( DataBase::getInstance()->queryData("sampleDisp").toInt() == 0 )
	{
		ui.label->hide();
		ui.sampleLbl->hide();
	}

	if( DataBase::getInstance()->queryData("refDisp").toInt() == 0 )
	{
		ui.label_13->hide();
		ui.basicLbl->hide();
	}
	
	ui.lampCombo->setCurrentIndex(MachineStat::getInstance()->getLampStat());

	updateAuValue(0,0,0,0);
	updateAuValue(0,0,0,1);

	connect(ui.lampCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(lampComboChanged(int)));
	connect(MachineStat::getInstance(), SIGNAL(changeLightStat(MachineStat::LampStatment)), this, SLOT(changeLampStat(MachineStat::LampStatment)));
	connect(MachineStat::getInstance(), SIGNAL(updateAuValue(quint32, quint32, double, quint8)), this, SLOT(updateAuValue(quint32, quint32, double, quint8)));
	connect(MachineStat::getInstance(), SIGNAL(wLenChanged(QString, quint8)), this, SLOT(updateWlenDisp( QString,quint8)));
	connect(ui.wLen1Edit, SIGNAL(dataChanging(QString)), this, SLOT(waveLen1Changed(QString)));
	connect(ui.wLen2Edit, SIGNAL(dataChanging(QString)), this, SLOT(waveLen2Changed(QString)));
	updateStartupTime();

	QTimer *pTimer = new QTimer(this);
	connect(pTimer, SIGNAL(timeout()), this, SLOT(updateStartupTime()));
	pTimer->start(1000);

	//测试用;
	connect(MachineStat::getInstance(), SIGNAL(testSignal(double)), this, SLOT(updateTestSignal(double)));
}

void RunPage::updateAuValue(quint32 s, quint32 r, double au, quint8 which)
{
	ui.sampleLbl->setText(QString::number(s).rightJustified(7,'0'));
	ui.basicLbl->setText(QString::number(r).rightJustified(7,'0'));
	if(which == 0)
		ui.auLbl->setText(QString::number(au, 'f', 4));
	else
		ui.auLbl2->setText(QString::number(au, 'f', 4));
}

void RunPage::changeLampStat( MachineStat::LampStatment stat )
{
	int index = stat;
	if(index <0 || index >1)
		return;

	ui.lampCombo->setCurrentIndex(index);
}

CBasePage* RunPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new RunPage(parent, index, previndex, add);
}

void RunPage::lampComboChanged(int index)
{
	if(index == 0)
		MachineStat::getInstance()->setLampStat(MachineStat::ON);
	else
		MachineStat::getInstance()->setLampStat(MachineStat::OFF);
}


void RunPage::updateWlenDisp( QString str, quint8 which )
{
	/*if(which == 0)
	ui.wlLbl1->setText(str);
	else
	ui.wlLbl2->setText(str);*/
}

void RunPage::waveLen1Changed(QString str)
{
	if( MachineStat::EStat_Busy == MachineStat::getInstance()->changeWaveLength(ui.wLen1Edit->text().toDouble(), MachineStat::EWLEN1 ) )
		ui.wLen1Edit->restoreData();

}

void RunPage::waveLen2Changed(QString str)
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

void RunPage::updateStartupTime()
{
	ui.lblTime->setText( MachineStat::getInstance()->getStartupTime() );
}

void RunPage::updateTestSignal( double wlen )
{
	//ui.label_4->setText(QString::number(wlen));
}

//void RunPage::on_pushButton_clicked()
//{
//	QTimer *pTimer = new QTimer(this);
//	connect(pTimer, SIGNAL(timeout()), this, SLOT(fuck()) );
//	pTimer->start(1000);
//}

//void RunPage::fuck()
//{
//	MachineStat::getInstance()->initMotor();
//}

