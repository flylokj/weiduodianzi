#include "permitpage.h"
#include <QDebug>
#include "Common.h"
#include "baseMainPage.h"
#include "msgbox.h"
#include "machinestat.h"
#include "timehelper.h"
#include <QFile>

#ifdef WIN32
	#define SRCFILE			"H:/weiduodianzi.txt"
	#define TARGETFILE		"K:/weiduodianzi.txt"
#else
	#define SRCFILE			"/sdcard/sepuyi"
	#define TARGETFILE		"/bin/weiduodianzi"
#endif


PermitPage::PermitPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("Permit"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Permit");
	ui.permitBtn->setBkImage(":/weiduodianzi/ui/Permission.png");

	setStyleSheet(BTNGLOBALSTYLE);
}

PermitPage::~PermitPage()
{

}


void PermitPage::initFocusList()
{
	xList.append(ui.serialBtn);
	xList.append(ui.licenseEdit);
	xList.append(ui.registerBtn);
	xList.append(ui.updateBtn);
	xList.append(ui.ipEdit1);
	xList.append(ui.ipEdit2);
	xList.append(ui.ipEdit3);
	xList.append(ui.ipEdit4);

	yList.append(ui.serialBtn);
	yList.append(ui.licenseEdit);
	yList.append(ui.registerBtn);
	yList.append(ui.updateBtn);
	yList.append(ui.ipEdit1);
	yList.append(ui.ipEdit2);
	yList.append(ui.ipEdit3);
	yList.append(ui.ipEdit4);

	ui.licenseEdit->setValRange("", 0, 9999999999, 0, 10);
	ui.licenseEdit->setTextMode();
	ui.ipEdit1->setValRange("ip1", 0, 255, 0);
	ui.ipEdit2->setValRange("ip2", 0, 255, 0);
	ui.ipEdit3->setValRange("ip3", 0, 255, 0);
	ui.ipEdit4->setValRange("ip4", 0, 255, 0);

	connect(ui.ipEdit1, SIGNAL(dataChanging(QString)), this, SLOT(ipChanged()));
	connect(ui.ipEdit4, SIGNAL(dataChanging(QString)), this, SLOT(ipChanged()));
	connect(ui.ipEdit4, SIGNAL(dataChanging(QString)), this, SLOT(ipChanged()));
	connect(ui.ipEdit4, SIGNAL(dataChanging(QString)), this, SLOT(ipChanged()));
	
	showPermitition();
	
}

bool PermitPage::eventFilter(QObject *o, QEvent *e)
{
	return CBasePage::eventFilter(o,e);
}

void PermitPage::on_registerBtn_clicked()
{
	if( MachineStat::getInstance()->activeMachine(ui.licenseEdit->text().toULongLong()) )
	{
		MsgBox msgBox(this,tr("Tips"), tr("Register success!"));
		msgBox.exec();
		showPermitition();
	}
	else
	{
		MsgBox msgBox(this,tr("Tips"), tr("Register failed!"));
		msgBox.exec();
	}
}

CBasePage* PermitPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new PermitPage(parent, index, previndex, add);
}

void PermitPage::on_updateBtn_clicked()
{
	QFile file(SRCFILE);
	if(!file.exists())
	{
		MsgBox msgBox(this,tr("Tips"), tr("file not found!"));
		msgBox.exec();
		return;
	}

	QFile target(TARGETFILE);
	if(target.exists())
		qDebug()<<target.remove();
	if(QFile::copy(SRCFILE, TARGETFILE) )
	{
		MsgBox msgBox(this,tr("Tips"), tr("success!"));
		msgBox.exec();
	}
	else
	{
		MsgBox msgBox(this,tr("Tips"), tr("failed!"));
		msgBox.exec();
	}
	
}

void PermitPage::on_serialBtn_clicked()
{
	quint32 serialId = TimeHelper::getRandom();
	QString str = tr("Serial:");
	str += DataBase::getInstance()->queryData("serial");
	str += "\n";
	str += tr("Id:");
	//再加上一个随机数;
	str += QString::number(serialId);
	MachineStat::getInstance()->updateSerialId(serialId);
	MsgBox msg(this, tr("tips"), str);
	msg.exec();
}

void PermitPage::ipChanged()
{
	MachineStat::getInstance()->initIPAddr();
}

void PermitPage::showDeActive()
{
	int day = MachineStat::getInstance()->checkProbation();
	ui.labelDay->setText(QString::number(day));
}

void PermitPage::showActive()
{
	//ui.licenseEdit->hide();
	//ui.registerBtn->hide();
	//ui.label_2->hide();

	ui.labelDay->setText(tr("infinite"));
}

void PermitPage::showPermitition()
{
	int active = DataBase::getInstance()->queryData("bActive").toInt();
	if(active == 0)
		showDeActive();
	else
		showActive();
}




