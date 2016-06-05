/********************************************************************************
** Form generated from reading UI file 'LampHistoryPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAMPHISTORYPAGE_H
#define UI_LAMPHISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "tablectrl.h"

QT_BEGIN_NAMESPACE

class Ui_LampHistoryPageClass
{
public:
    QGridLayout *gridLayout;
    TableCtrl *tableView;
    BtnCtrl *firstBtn;
    BtnCtrl *prevBtn;
    BtnCtrl *nextBtn;
    BtnCtrl *lastBtn;

    void setupUi(QWidget *LampHistoryPageClass)
    {
        if (LampHistoryPageClass->objectName().isEmpty())
            LampHistoryPageClass->setObjectName(QString::fromUtf8("LampHistoryPageClass"));
        LampHistoryPageClass->resize(336, 215);
        gridLayout = new QGridLayout(LampHistoryPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(3, 0, 3, -1);
        tableView = new TableCtrl(LampHistoryPageClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 4);

        firstBtn = new BtnCtrl(LampHistoryPageClass);
        firstBtn->setObjectName(QString::fromUtf8("firstBtn"));

        gridLayout->addWidget(firstBtn, 1, 0, 1, 1);

        prevBtn = new BtnCtrl(LampHistoryPageClass);
        prevBtn->setObjectName(QString::fromUtf8("prevBtn"));

        gridLayout->addWidget(prevBtn, 1, 1, 1, 1);

        nextBtn = new BtnCtrl(LampHistoryPageClass);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));

        gridLayout->addWidget(nextBtn, 1, 2, 1, 1);

        lastBtn = new BtnCtrl(LampHistoryPageClass);
        lastBtn->setObjectName(QString::fromUtf8("lastBtn"));

        gridLayout->addWidget(lastBtn, 1, 3, 1, 1);


        retranslateUi(LampHistoryPageClass);

        QMetaObject::connectSlotsByName(LampHistoryPageClass);
    } // setupUi

    void retranslateUi(QWidget *LampHistoryPageClass)
    {
        LampHistoryPageClass->setWindowTitle(QApplication::translate("LampHistoryPageClass", "Form", 0, QApplication::UnicodeUTF8));
        firstBtn->setText(QApplication::translate("LampHistoryPageClass", "<<", 0, QApplication::UnicodeUTF8));
        prevBtn->setText(QApplication::translate("LampHistoryPageClass", "<", 0, QApplication::UnicodeUTF8));
        nextBtn->setText(QApplication::translate("LampHistoryPageClass", ">", 0, QApplication::UnicodeUTF8));
        lastBtn->setText(QApplication::translate("LampHistoryPageClass", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LampHistoryPageClass: public Ui_LampHistoryPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAMPHISTORYPAGE_H
