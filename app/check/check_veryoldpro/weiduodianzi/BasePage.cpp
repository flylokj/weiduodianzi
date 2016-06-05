#include "BasePage.h"
#include "editctrl.h"
#include "tablectrl.h"
#include <QGridLayout>
#include "baseMainPage.h"


CBasePage::CBasePage(QWidget *parent /*= 0 */)
	:QWidget(parent)
	,m_pCurrentPage(0)
{

}

CBasePage::CBasePage(QString strTitle, quint8 nPageIndex, quint8 nPrevPageIndex, quint32 add, QWidget *parent/* = 0*/)
	: QWidget(parent),
	m_strTitle( strTitle ),
	m_nPageIndex( nPageIndex ),
	m_nPrevPageIndex(nPrevPageIndex),
	m_nAdd(add),
	m_pCurrentPage(0)
{
	
}




CBasePage::~CBasePage()
{

}

void CBasePage::initFocus()
{
	initFocusList();
	filterEventForChildren();
}

void CBasePage::filterEventForChildren()
{
	/*QObjectList list = children();
	foreach(QObject *obj, list)
	{
	QWidget *widget = qobject_cast<QWidget*>(obj);
	if(widget)
	widget->installEventFilter(this);
	}*/
}

bool CBasePage::eventFilter(QObject *obj, QEvent *event)
{
	if(event->type() == QEvent::KeyPress)
	{
		QKeyEvent *ke = static_cast<QKeyEvent *>(event);
		if(ke->key() == Qt::Key_Backspace)
		{
			QWidget *ctrl = qobject_cast<QWidget *>(obj);
			if(ctrl)
			{
				EditCtrl *edit = qobject_cast<EditCtrl *>(obj);
				TableCtrl *tblCtrl = qobject_cast<TableCtrl *>(obj);
				if(edit)
				{
					if(!edit->isEditMode())
					{
						g_pMainWindow->backToPage();
						return true;
					}
					else
						return false;
				}
				else
				{
					if(tblCtrl)
						return false;

					g_pMainWindow->backToPage();
					return true;
				}
			}
			return false;
		}
		else
			return false;
	}
	else
		return false;
}

CBasePage* CBasePage::changePage(int index, quint32 addData /*= 0*/)
{
	if(index >=0 & index <pageMethod.size())
	{
		qDebug()<<"CBasePage:..........00000000000000";
		const StructPageMethod &method = pageMethod.at(index);
		qDebug()<<"CBasePage:..........1111111111111"<<"index:"<<index;
		qDebug()<<"CBasePage:..........1111111111111"<<"instance:"<<method.getInstance;
		CBasePage *pPage = method.getInstance(this, index, method.nPrevIndex, addData);
		qDebug()<<"CBasePage:..........222222222222222";
		if(m_pCurrentPage)
			m_pCurrentPage->deleteLater();
		qDebug()<<"CBasePage:..........33333333333333333333";
		m_pCurrentPage = pPage;
		QLayout *oldLayout = this->layout();
		qDebug()<<"CBasePage:..........444444444444444";
		if(oldLayout)
		{
			delete oldLayout;
		}
		qDebug()<<"CBasePage:..........555555555555555555";
		QGridLayout *pLayout = new QGridLayout(this);
		qDebug()<<"CBasePage:..........666666666666666666666666";
		pLayout->setContentsMargins(5,5,5,5);
		pLayout->addWidget(pPage);
		qDebug()<<"CBasePage:..........777777777777777777777777777";
		m_pCurrentPage->show();
		m_pCurrentPage->initFocus();
		qDebug()<<"CBasePage:..........888888888888888888888888888";
		return m_pCurrentPage;
	}
	else
		return NULL;
}

void CBasePage::addPage(getPageInstance pageInstanceMethod, quint8 prevIndex)
{
	StructPageMethod method;
	method.getInstance = pageInstanceMethod;
	method.nPrevIndex = prevIndex;
	pageMethod.append(method);
}


