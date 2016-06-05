#include "setuppage.h"
#include <QDebug>
#include "baseMainPage.h"
#include <QKeyEvent>
//
SetupPage::SetupPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("SetupPage"), index, previndex, add,parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Setup");
	ui.globalBtn->setStyleSheet("QPushButton{border-image:url(:/weiduodianzi/ui/global.png);}""QPushButton:focus{border-image:url(:/weiduodianzi/ui/globalFocus.png);outline: 0px;}");
	ui.calBtn->setStyleSheet("QPushButton{border-image:url(:/weiduodianzi/ui/Calibration.png);}""QPushButton:focus{border-image:url(:/weiduodianzi/ui/CalibrationFocus.png);outline: 0px;}");
	ui.permitBtn->setStyleSheet("QPushButton{border-image:url(:/weiduodianzi/ui/Permission.png);}""QPushButton:focus{border-image:url(:/weiduodianzi/ui/PermissionFocus.png);outline: 0px;}");
	ui.timeBtn->setStyleSheet("QPushButton{border-image:url(:/weiduodianzi/ui/clock.png);}""QPushButton:focus{border-image:url(:/weiduodianzi/ui/clockFocus.png);outline: 0px}");
	ui.msgBtn->setStyleSheet("QPushButton{border-image:url(:/weiduodianzi/ui/message.png);}""QPushButton:focus{border-image:url(:/weiduodianzi/ui/messageFocus.png);outline: 0px}");
	
}

SetupPage::~SetupPage()
{

}


void SetupPage::on_globalBtn_clicked()
{
	g_pMainWindow->changePage( LANGUAGEPAGE_INDEX );
}
void SetupPage::on_calBtn_clicked()
{
	g_pMainWindow->changePage( FIXPAGE_INDEX );
}

void SetupPage::on_permitBtn_clicked()
{
	g_pMainWindow->changePage( PERMITPAGE_INDEX );
}
void SetupPage::on_timeBtn_clicked()
{
	g_pMainWindow->changePage( TIMEPAGE_INDEX );
}
void SetupPage::on_msgBtn_clicked()
{
	g_pMainWindow->changePage( MSGPAGE_INDEX );
}


void SetupPage::initFocusList()
{
	xList.append(ui.globalBtn);
	xList.append(ui.calBtn);
	xList.append(ui.permitBtn);
	xList.append(ui.timeBtn);
	xList.append(ui.msgBtn);

	yList.append(ui.globalBtn);
	yList.append(ui.timeBtn);
	yList.append(ui.calBtn);
	yList.append(ui.permitBtn);
	yList.append(ui.msgBtn);

	/*ui.globalBtn->installEventFilter(this);
	ui.calBtn->installEventFilter(this);
	ui.permitBtn->installEventFilter(this);
	ui.timeBtn->installEventFilter(this);
	ui.msgBtn->installEventFilter(this);*/
}

#if 0
bool SetupPage::eventFilter(QObject *o, QEvent *e)
{
	if(e->type() == QEvent::KeyPress)
	{
		QKeyEvent *ke = static_cast<QKeyEvent *>(e);
		if(ke->key() == Qt::Key_Return)
		{
			if(o == ui.globalBtn)
			{
				gotoGlobalPage();
				return true;
				//return CBasePage::eventFilter(o, e);
			}
			else if(o == ui.calBtn)
			{
				gotoFixPage();
				return true;
			}
			else if(o == ui.permitBtn)
			{
				gotoPermissionPage();
				return true;
			}
			else if(o == ui.timeBtn)
			{
				gotoTimePage();
				return true;
			}
			else if(o == ui.msgBtn)
			{
				gotoMessagePage();
				return true;
			}
		}
		else 
			return CBasePage::eventFilter(o, e);

	}
	else 
		return false;
}
#endif

CBasePage* SetupPage::getInstance(QWidget *parent, quint8 index, quint8 prevIndex, quint32 add)
{
	return new SetupPage(parent, index, prevIndex, add);
}




