#include "AdminPage.h"
#include <QKeyEvent>
#include "ui_AdminPage.h"
#include <QDebug>
#include <QMessageBox>
#include "baseMainPage.h"
#include "machinestat.h"

AdminPage::AdminPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("AdminPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Admin");
	initDisplay();
	setStyleSheet(BTNGLOBALSTYLE);
}


AdminPage::~AdminPage(void)
{
}


void AdminPage::initFocusList()
{
	xList.append(ui.activeBtn);
	xList.append(ui.utcBtn);
	xList.append(ui.btcBtn);
	xList.append(ui.rstBtn);//恢复出厂设置，测试用;
	xList.append(ui.instYearEdit);
	xList.append(ui.instMonthEdit);
	xList.append(ui.instDayEdit);
	xList.append(ui.licenseEdit);
	xList.append(ui.serialEdit);
	//xList.append(ui.dayEdit);
	xList.append(ui.proCombo);

	yList.append(ui.activeBtn);
	yList.append(ui.utcBtn);
	yList.append(ui.btcBtn);
	yList.append(ui.rstBtn);//恢复出厂设置，测试用;
	yList.append(ui.instYearEdit);
	yList.append(ui.instMonthEdit);
	yList.append(ui.instDayEdit);
	yList.append(ui.licenseEdit);
	yList.append(ui.serialEdit);
	//yList.append(ui.dayEdit);
	yList.append(ui.proCombo);

	
}



CBasePage* AdminPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new AdminPage(parent, index, previndex, add);
}



void AdminPage::on_activeBtn_clicked()
{
	MsgBox msgBox(this, tr("Tips"), tr("Comfirm to Cancel Active!!!"));
	if(msgBox.exec() == QMessageBox::Ok)
	{
		MachineStat::getInstance()->activeMachine(0, 0);				//取消激活;
		MachineStat::getInstance()->clearTime(MachineStat::SYSTIME);	//试用期清零重新计算;
	}
}

void AdminPage::on_utcBtn_clicked()
{
	MsgBox msgBox(this, tr("Tips"), tr("Comfirm to Clear!!!"));
	if(msgBox.exec() == QMessageBox::Ok)
		MachineStat::getInstance()->clearTime(MachineStat::SYSTIME);
}

void AdminPage::on_btcBtn_clicked()
{
	MsgBox msgBox(this, tr("Tips"), tr("Comfirm to Clear!!!"));
	if(msgBox.exec() == QMessageBox::Ok)
		MachineStat::getInstance()->clearTime(MachineStat::PUMPTIME);
}

void AdminPage::initDisplay()
{
	ui.instYearEdit->setValRange("instYear", 1990, 2050, 0);
	ui.instMonthEdit->setValRange("instMonth", 1, 12, 0);
	ui.instDayEdit->setValRange("instDay", 0, 31, 0);
	ui.licenseEdit->setValRange("license",0, 9999999999, 0, 10);
	ui.serialEdit->setValRange("serial",0, 9999999999, 0, 10);
	ui.dayEdit->setValRange("tryDay", 1, 1000, 0);
	ui.proCombo->setVar("pcProtocol");
	ui.activeBtn->setFocus();

	connect(ui.proCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changePcPro(int)));
	connect(ui.dayEdit, SIGNAL(dataChanging(QString)), this, SLOT(tryDayChanged(QString)) );
	ui.dayEdit->setEnabled(false);//屏蔽试用日期的编辑

	ui.licenseEdit->setTextMode();
	ui.serialEdit->setTextMode();
	ui.licenseEdit->setReadOnly(true);
	ui.instYearEdit->setReadOnly(true);
}

void AdminPage::on_rstBtn_clicked()
{
	MsgBox msgBox(this, tr("Tips"), tr("Comfirm to Restore!!!"));
	if(msgBox.exec() == QMessageBox::Ok)
		DataBase::getInstance()->restoreCompensationTable();
}

void AdminPage::tryDayChanged(QString val)
{
	MachineStat::getInstance()->clearTime(MachineStat::SYSTIME);
}

void AdminPage::changePcPro(int idx)
{
	MachineStat::getInstance()->setPcProtocol(idx);
}
