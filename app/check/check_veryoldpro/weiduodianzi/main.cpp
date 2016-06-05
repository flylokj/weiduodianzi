#include "baseMainPage.h"
#include <QtGui/QApplication>
#include <QFont>
#include <QTextCodec>
#include "Common.h"
#include <QDebug>
#include <QString>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb18030"));
	QFont font;

	font.setPointSize(9);
	//font.setFamily(("ºÚÌå"));
	QFontDatabase database;
	//qDebug()<<database.families();
	a.setFont(font);
	BaseMainPage w("UV3000U");
	w.resize(SCREEN_WIDTH, SCREEN_HEIGH);
	
#ifdef linux
	QApplication::setOverrideCursor(Qt::BlankCursor);//Òþ²ØÊó±ê
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.showFullScreen ();
#else
	w.show();
#endif
	return a.exec();
}
