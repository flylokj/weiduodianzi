#include "tableeditor.h"
#include <QDebug>
#include <math.h>
#include <QKeyEvent>

TableEditor::TableEditor(QWidget *parent, QString inputMask)
	: QLineEdit(parent)
{
	m_inputMask = inputMask;
	QString temp = m_inputMask;
	temp.remove('.');
	len = temp.length();
	int index = m_inputMask.indexOf('.');
	if(index == -1)
		bei = 1;
	else
	{
		bei = pow((double)10, len-index);
	}
}

TableEditor::~TableEditor()
{

}


void TableEditor::keyPressEvent( QKeyEvent *event )
{
	if(event->key()>=Qt::Key_0 && event->key()<=Qt::Key_9)
	{
		if(data.length() == len)
			data.clear();
		data.append(event->text());
		QString temp = data.join("");
		double ret = temp.toDouble();
		ret = ret/bei;
		qDebug()<<ret;
		setText(QString::number(ret));

	}
	else if(event->key() == Qt::Key_Backspace)
	{
		qDebug()<<"backsp";
	}
	else
		return QLineEdit::keyPressEvent(event);
}
