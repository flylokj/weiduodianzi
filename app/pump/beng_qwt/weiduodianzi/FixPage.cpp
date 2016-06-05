#include "FixPage.h"
#include <QKeyEvent>
#include "baseMainPage.h"

FixPage::FixPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("FixPage"), index, previndex, add, parent )
{
	ui.setupUi(this);
	m_strTitle = tr("Fix");
	setStyleSheet( BTNGLOBALSTYLE);
}


FixPage::~FixPage(void)
{
}



void FixPage::initFocusList()
{
	xList.append(ui.pressCalBtn);
	xList.append(ui.flowCalBtn);

	yList.append(ui.pressCalBtn);
	yList.append(ui.flowCalBtn);

	ui.pressCalBtn->setFocus();

}


CBasePage* FixPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new FixPage(parent, index, previndex, add);
}

void FixPage::on_pressCalBtn_clicked()
{
	g_pMainWindow->changePage(WAVEFIXPAGE_INDEX);
}

void FixPage::on_flowCalBtn_clicked()
{
	g_pMainWindow->changePage(FLOWFIXPAGE_INDEX);
}
