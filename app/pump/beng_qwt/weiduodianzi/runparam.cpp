#include "runparam.h"
#include <QDebug>
#include "Common.h"
#include "baseMainPage.h"

RunParamPage::RunParamPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("RunParam"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("RunParam");
	initDisplay();
}

RunParamPage::~RunParamPage()
{

}



void RunParamPage::initFocusList()
{
	xList.append(ui.pumpMod);
	xList.append(ui.maxPress);
	xList.append(ui.minPress);
	xList.append(ui.gradient);
	xList.append(ui.gradientBtn);
	xList.append(ui.coefficient);

	yList.append(ui.pumpMod);
	yList.append(ui.maxPress);
	yList.append(ui.minPress);
	yList.append(ui.gradient);
	yList.append(ui.coefficient);
	yList.append(ui.gradientBtn);

	ui.pumpMod->setVar("pumptype");//泵类型;
	ui.coefficient->setValRange("coefficient", 0, 100, 0);
	//流量补偿...........
	ui.gradient->setVar("gradient");

	connect(ui.pumpMod, SIGNAL(currentIndexChanged(int)), this, SLOT(setMinAndMaxPress()));
	connect(ui.gradientBtn, SIGNAL(clicked()), this, SLOT(goToGradientPage()));
}


void RunParamPage::setMinAndMaxPress()
{
	int array[7]={42, 25 , 20, 20, 15, 10, 10};
	int pumpType = ui.pumpMod->currentIndex();
	if(pumpType > 6)
		return;

//设置最大压力输入范围与现实内容;
	QString temp = QString::number(array[pumpType]);
	ui.maxPress->setValRange("maxpress", 0, 100, 0);
	ui.maxPress->setText(temp);
	DataBase::getInstance()->updateDate("maxpress", temp);

//设置最小压力输入范围;
	ui.minPress->setValRange("minpress", -50, array[pumpType], 0);
	int minPress = DataBase::getInstance()->queryData("minpress").toInt();
	if(minPress > array[pumpType])
		minPress = 0;
	temp = QString::number(minPress);
	ui.minPress->setText(temp);
	DataBase::getInstance()->updateDate("minpress", temp);

	MachineStat::getInstance()->pumpTypeChanged();
}

void RunParamPage::goToGradientPage()
{
	g_pMainWindow->changePage(GRADIENTPAGE_INDEX);
}

void RunParamPage::initDisplay()
{
	ui.maxPress->setValRange("maxpress", 0, 100, 0);
	ui.minPress->setValRange("minpress", -50, 50, 0);
	setStyleSheet( BTNGLOBALSTYLE);
}

CBasePage* RunParamPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new RunParamPage(parent, index, previndex, add);
}





