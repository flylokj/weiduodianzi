#include "bottomwidget.h"
#include <QDebug>
#include "baseMainPage.h"
#include <QShortcut>

#define BTNNORMALSTYLE "QPushButton{border-image:url(:/weiduodianzi/ui/normalNavigator.png);}""QPushButton{border: 2px solid green;outline: 0px;}"
#define BTNFOCUSSTYLE "QPushButton:focus{border-image:url(:/weiduodianzi/ui/focusNavigator.png);border: 2px solid green;outline: 0px;}""QPushButton{border-image:url(:/weiduodianzi/ui/activeNavigator.png);border: 2px solid green;outline: 0px;}"



BottomWidget::BottomWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initNavigator();
	connect(MachineStat::getInstance(), SIGNAL(systemError(int, QString)), this, SLOT(updateWarning(int, QString)));
	updateWarning(0, tr("No Warn"));
}



BottomWidget::~BottomWidget()
{

}


void BottomWidget::initNavigator()
{
	m_btnList.append(ui.runBtn);
	m_btnList.append(ui.paramBtn);
	m_btnList.append(ui.setBtn);
#ifdef WIN32
	m_btnList.append(ui.dbgBtn);
#else
	ui.dbgBtn->hide();
#endif
}





void BottomWidget::on_runBtn_clicked()
{
	g_pMainWindow->navigatorPageAt(0);
}



void BottomWidget::on_paramBtn_clicked()
{
	g_pMainWindow->navigatorPageAt(1);
}



void BottomWidget::on_setBtn_clicked()
{
	g_pMainWindow->navigatorPageAt(2);
}



void BottomWidget::on_dbgBtn_clicked()
{
	g_pMainWindow->navigatorPageAt(3);
}




void BottomWidget::changeNavigatorDisp(quint8 index)
{
	for(int i = 0; i < m_btnList.count(); i++)
	{
		if(i != index)
			m_btnList.at(i)->setStyleSheet(BTNNORMALSTYLE);
		else
		{
			m_btnList.at(i)->setStyleSheet(BTNFOCUSSTYLE);
			m_btnList.at(i)->setFocus();
		}
	}

}

void BottomWidget::updateLanguage()
{
	ui.runBtn->setText(tr("Run"));
	ui.paramBtn->setText(tr("Param"));
	ui.setBtn->setText(tr("Setup"));
	ui.dbgBtn->setText(tr("Debug"));
}

void BottomWidget::updateWarning( int err, QString str)
{
	QPalette pa;
	if(err == 0)
		pa.setColor(QPalette::WindowText, Qt::blue);
	else
		pa.setColor(QPalette::WindowText, Qt::red);
	ui.label->setPalette(pa);
	ui.label->setText(str);
}






