#include "CheckingPage.h"
#include <QMessageBox>
#include <QKeyEvent>
#include "msgbox.h"
#include "iomodule.h"
#include "machinestat.h"
#include "baseMainPage.h"



CheckingPage::CheckingPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("CheckingPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("CheckingPage");
	setStyleSheet( BTNGLOBALSTYLE);
}



CheckingPage::~CheckingPage(void)
{
	
}

void CheckingPage::initFocusList()
{
	connect( IoModule::getInstance(), SIGNAL(initLampSuccess(bool)), this, SLOT(lampSuccess(bool)) );
	connect( MachineStat::getInstance(), SIGNAL(motorInitSuccessSignal()), this, SLOT(motorInitSuccess()) );
	

	ui.lampCheck->setStyleSheet(CHECKGLOBALSTYLE);
	ui.motorCheck->setStyleSheet(CHECKGLOBALSTYLE);
}

CBasePage* CheckingPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new CheckingPage(parent, index, previndex, add);
}

void CheckingPage::lampSuccess(bool success)
{
	ui.lampCheck->setChecked(success);
}

void CheckingPage::motorInitSuccess()
{
	ui.motorCheck->setChecked(true);
	g_pMainWindow->checkingSuccess();
}



