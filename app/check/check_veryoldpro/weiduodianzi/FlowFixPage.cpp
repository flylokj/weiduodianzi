#include "FlowFixPage.h"
#include <QPainter>
#include "mytablemodel.h"
#include "editordelegate.h"
#include "msgbox.h"
#include "database.h"
#include "machinestat.h"

FlowFixPage::FlowFixPage(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("FlowFixPage"), index, previndex, add, parent )
	, tFlag(false)
	, whichMode(0)
{
	ui.setupUi(this);
	m_strTitle = tr("FlowFix");
	initDisplay();
}



FlowFixPage::~FlowFixPage(void)
{
	DataBase::getInstance()->readWaveCompensationTableIntoList();
	if(tFlag)
	{
		restoreWaveMode();
	}
}

void FlowFixPage::initFocusList()
{
	xList.append(ui.tableView);
	xList.append(ui.saveBtn);
	xList.append(ui.backBtn);
	xList.append(ui.wlenEdit);

	yList.append(ui.tableView);
	yList.append(ui.saveBtn);
	yList.append(ui.backBtn);
	yList.append(ui.wlenEdit);
}

void FlowFixPage::initDisplay()
{
	MyTableModel *gradient_model = new MyTableModel(this, 2);
	gradient_model->readDataFromTable(TABLE_WAVE);
	ui.tableView->setModel(gradient_model);
	ui.tableView->setColumnWidth(0,130);    
	ui.tableView->setColumnWidth(1,130);    
	ui.tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed);

	//为每一列设置代理;
 	ui.tableView->setItemDelegateForColumn(0, new EditorDelegate("000.0000"));//流速;
 	ui.tableView->setItemDelegateForColumn(1, new EditorDelegate("000.0000"));//校准;
	ui.tableView->initIndex();
  
 	connect(ui.tableView, SIGNAL(getOutFocus(int)), this, SLOT(getOutTableFocus(int)));
	setStyleSheet( BTNGLOBALSTYLE);

	ui.wlenEdit->setValRange(QString("wavelentemp"),190,800, 0);
	connect(ui.wlenEdit, SIGNAL(dataChanging(QString)), this, SLOT(waveLenChanged(QString)));
	
}

void FlowFixPage::getOutTableFocus( int dir )
{
	if(dir == 0)//上
		ui.saveBtn->setFocus();
	else if(dir == 1)//下;
		ui.saveBtn->setFocus();
	else if(dir == 2)//左
		ui.wlenEdit->setFocus();
	else if(dir == 3)//右
		ui.saveBtn->setFocus();

	updateFlowList();
}

void FlowFixPage::on_saveBtn_clicked()
{
	MyTableModel *mod = static_cast<MyTableModel *>(ui.tableView->model());
	DataBase::getInstance()->updateWaveCompensationTable(mod->tableData);
	MsgBox msgBox(this,tr("Tips"), tr("save success!"), QMessageBox::Ok);
	msgBox.exec();
}

void FlowFixPage::on_backBtn_clicked()
{
	g_pMainWindow->backToPage();
}


void FlowFixPage::updateFlowList()
{
	MyTableModel *mod = static_cast<MyTableModel *>(ui.tableView->model());
	QList<QStringList> data = mod->tableData;
	if( data.count() >= 1 )
		data.removeAt(0);
	DataBase::getInstance()->readWaveCompensationTableIntoList(data);
}

CBasePage* FlowFixPage::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new FlowFixPage(parent, index, previndex, add);
}

void FlowFixPage::waveLenChanged(QString)
{
	if(!tFlag)
	{
		tFlag = true;
		saveWaveMode();
	}
	double wave = ui.wlenEdit->text().toDouble();
	MachineStat::getInstance()->resetWaveAndAngle();
	MachineStat::getInstance()->setWaveCtrlWord(ui.wlenEdit->text(), 0);
//每次修改都重新归原点 2016.02.17,注释掉也可以工作，只是每次不归原点;
	//MachineStat::getInstance()->initMotor();
}

void FlowFixPage::saveWaveMode()
{
	whichMode = DataBase::getInstance()->queryData("chanel").toInt();
	DataBase::getInstance()->updateDate("chanel", 0);//切换到单波长;
	MachineStat::getInstance()->resetWaveAndAngle();
	MachineStat::getInstance()->setWaveCtrlWordAndHome();
}

void FlowFixPage::restoreWaveMode()
{
	DataBase::getInstance()->updateDate("chanel", QString::number(whichMode));//切换到单波长;
	MachineStat::getInstance()->resetWaveAndAngle();
	MachineStat::getInstance()->setWaveCtrlWordAndHome();
}
