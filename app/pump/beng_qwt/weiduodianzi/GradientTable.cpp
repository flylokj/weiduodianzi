#include "GradientTable.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QStandardItemModel>
#include "mytablemodel.h"
#include "editordelegate.h"
#include "msgbox.h"


GradientTable::GradientTable(QWidget *parent /*= 0*/, quint8 index, quint8 previndex, quint32 add)
	: CBasePage(tr("GradientTable"), index, previndex, add, parent )
	, m_nWhich(add)
{
	ui.setupUi(this);
	m_strTitle = tr("GradientTable");
	initDisplay();
	setStyleSheet( BTNGLOBALSTYLE);
}


GradientTable::~GradientTable(void)
{
	
}

void GradientTable::initFocusList()
{
	xList.append(ui.tableView);
	xList.append(ui.saveBtn);
	xList.append(ui.backBtn);

	yList.append(ui.tableView);
	yList.append(ui.saveBtn);
	yList.append(ui.backBtn);
}

bool GradientTable::eventFilter( QObject *obj, QEvent *event )
{
	return false;
}

void GradientTable::initDisplay()
{
	MyTableModel *gradient_model = new MyTableModel(this, 4, m_nWhich);
	gradient_model->readDataFromTable(m_nWhich);
 	ui.tableView->setModel(gradient_model);
	ui.tableView->setColumnWidth(0,80);    
	ui.tableView->setColumnWidth(1,80);    
	ui.tableView->setColumnWidth(2,80);    
	ui.tableView->setColumnWidth(3,80);
	ui.tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed);

	//Ϊÿһ�����ô���;
	ui.tableView->setItemDelegateForColumn(0, new EditorDelegate("000.0"));//ʱ��;
	ui.tableView->setItemDelegateForColumn(1, new EditorDelegate("000.0000"));//����;
	ui.tableView->setItemDelegateForColumn(2, new EditorDelegate("000.0"));//A;
	ui.tableView->setItemDelegateForColumn(3, new EditorDelegate("000.0"));//B;
 	connect(ui.tableView, SIGNAL(getOutFocus(int)), this, SLOT(getOutTableFocus(int)));


}

void GradientTable::getOutTableFocus(int dir)
{
	if(dir == 0)//��
		ui.backBtn->setFocus();
	else if(dir == 1)//��;
		ui.saveBtn->setFocus();
	else if(dir == 2)//��
		ui.backBtn->setFocus();
	else if(dir == 3)//��
		ui.saveBtn->setFocus();
}


void GradientTable::on_saveBtn_clicked()
{
	MyTableModel *mod = static_cast<MyTableModel *>(ui.tableView->model());
	DataBase::getInstance()->updateGradientTable(m_nWhich, mod->tableData);
	MsgBox msgBox(this,tr("Tips"), tr("save success!"), QMessageBox::Ok);
	msgBox.exec();
}


void GradientTable::on_backBtn_clicked()
{
	g_pMainWindow->backToPage();
}

CBasePage* GradientTable::getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add)
{
	return new GradientTable(parent, index, previndex, add);
}


