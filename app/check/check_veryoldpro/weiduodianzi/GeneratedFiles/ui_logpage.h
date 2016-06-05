/********************************************************************************
** Form generated from reading UI file 'logpage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGPAGE_H
#define UI_LOGPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogoPageClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *LogoPageClass)
    {
        if (LogoPageClass->objectName().isEmpty())
            LogoPageClass->setObjectName(QString::fromUtf8("LogoPageClass"));
        LogoPageClass->resize(320, 195);
        LogoPageClass->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(LogoPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LogoPageClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/logo.png);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(LogoPageClass);

        QMetaObject::connectSlotsByName(LogoPageClass);
    } // setupUi

    void retranslateUi(QWidget *LogoPageClass)
    {
        LogoPageClass->setWindowTitle(QApplication::translate("LogoPageClass", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogoPageClass: public Ui_LogoPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGPAGE_H
