#include "FixPage.h"
#include <QKeyEvent>
#include "baseMainPage.h"

FixPage::FixPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("GradientPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Fix");
	setStyleSheet("QPushButton:focus{border:2px solid rgb(155,200,33);outline:0px;}");
}


FixPage::~FixPage(void)
{
}



void FixPage::initFocusList()
{
	xList.append(ui.coefficient);
	xList.append(ui.timeInteCombo);
	xList.append(ui.wavCalBtn);

	yList.append(ui.coefficient);
	yList.append(ui.timeInteCombo);
	yList.append(ui.wavCalBtn);

	//ui.timeInteBtn->setFocus();

	ui.coefficient->setValRange(QString("coefficient"),0,100, 3);
	ui.timeInteCombo->setVar(QString("timeInte"));
	connect(ui.timeInteCombo, SIGNAL(currentIndexChanged(int )), this, SLOT(timeInteChnaged(int)));
}



CBasePage* FixPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new FixPage(parent, index, previndex, add);
}




void FixPage::on_wavCalBtn_clicked()
{
	g_pMainWindow->changePage(FLOWFIXPAGE_INDEX);
}

void FixPage::timeInteChnaged( int timeInte)
{
	MachineStat::getInstance()->updateTimeInte();
}
