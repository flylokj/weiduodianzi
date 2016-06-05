#include "msgpage.h"
#include <QDebug>
#include "Common.h"
#include "baseMainPage.h"

MsgPage::MsgPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("Message"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Message");
	ui.msgBtn->setBkImage(":/weiduodianzi/ui/message.png");
	ui.labelVersionx->setText(VERSION);
	ui.labelLicensex->setText(DataBase::getInstance()->queryData("license"));
	ui.labelSerialx->setText(DataBase::getInstance()->queryData("serial"));
}

MsgPage::~MsgPage()
{

}

void MsgPage::initFocusList()
{
	ui.labelSerial->setFocus();
}

CBasePage* MsgPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new MsgPage(parent, index, previndex, add);
}




