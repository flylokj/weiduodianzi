#ifndef MSGPAGE_H
#define MSGPAGE_H

#include <BasePage.h>
#include "ui_MsgPage.h"

class MsgPage : public CBasePage
{
	Q_OBJECT

public:
	MsgPage(QWidget *parent = 0, quint8 index = 0, quint8 previndex = 0, quint32 add = 0);
	~MsgPage();
	static CBasePage* getInstance(QWidget *parent, quint8 index, quint8 previndex, quint32 add);

protected:
	virtual void initFocusList();

private:
	Ui::MsgPageClass ui;
	

};

#endif // MSGPAGE_H
