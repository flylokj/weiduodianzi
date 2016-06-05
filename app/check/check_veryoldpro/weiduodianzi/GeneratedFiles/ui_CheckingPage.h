/********************************************************************************
** Form generated from reading UI file 'CheckingPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINGPAGE_H
#define UI_CHECKINGPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckingPageClass
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *lampCheck;
    QCheckBox *motorCheck;

    void setupUi(QWidget *CheckingPageClass)
    {
        if (CheckingPageClass->objectName().isEmpty())
            CheckingPageClass->setObjectName(QString::fromUtf8("CheckingPageClass"));
        CheckingPageClass->resize(367, 205);
        verticalLayout = new QVBoxLayout(CheckingPageClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, -1, -1, -1);
        lampCheck = new QCheckBox(CheckingPageClass);
        lampCheck->setObjectName(QString::fromUtf8("lampCheck"));

        verticalLayout->addWidget(lampCheck);

        motorCheck = new QCheckBox(CheckingPageClass);
        motorCheck->setObjectName(QString::fromUtf8("motorCheck"));

        verticalLayout->addWidget(motorCheck);


        retranslateUi(CheckingPageClass);

        QMetaObject::connectSlotsByName(CheckingPageClass);
    } // setupUi

    void retranslateUi(QWidget *CheckingPageClass)
    {
        CheckingPageClass->setWindowTitle(QApplication::translate("CheckingPageClass", "Form", 0, QApplication::UnicodeUTF8));
        lampCheck->setText(QApplication::translate("CheckingPageClass", "Lamp initializing...", 0, QApplication::UnicodeUTF8));
        motorCheck->setText(QApplication::translate("CheckingPageClass", "Motor initializing...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckingPageClass: public Ui_CheckingPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINGPAGE_H
