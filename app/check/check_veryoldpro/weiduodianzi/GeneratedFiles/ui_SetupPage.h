/********************************************************************************
** Form generated from reading UI file 'SetupPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPPAGE_H
#define UI_SETUPPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "btnctrl.h"

QT_BEGIN_NAMESPACE

class Ui_SetupPageClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    BtnCtrl *globalBtn;
    BtnCtrl *calBtn;
    BtnCtrl *permitBtn;
    QHBoxLayout *horizontalLayout_2;
    BtnCtrl *timeBtn;
    BtnCtrl *scanBtn;
    BtnCtrl *msgBtn;

    void setupUi(QWidget *SetupPageClass)
    {
        if (SetupPageClass->objectName().isEmpty())
            SetupPageClass->setObjectName(QString::fromUtf8("SetupPageClass"));
        SetupPageClass->resize(320, 195);
        gridLayout = new QGridLayout(SetupPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, 0, -1);
        globalBtn = new BtnCtrl(SetupPageClass);
        globalBtn->setObjectName(QString::fromUtf8("globalBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(globalBtn->sizePolicy().hasHeightForWidth());
        globalBtn->setSizePolicy(sizePolicy);
        globalBtn->setMaximumSize(QSize(70, 70));
        globalBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/global.png);"));

        horizontalLayout->addWidget(globalBtn);

        calBtn = new BtnCtrl(SetupPageClass);
        calBtn->setObjectName(QString::fromUtf8("calBtn"));
        sizePolicy.setHeightForWidth(calBtn->sizePolicy().hasHeightForWidth());
        calBtn->setSizePolicy(sizePolicy);
        calBtn->setMaximumSize(QSize(70, 70));
        calBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/clock.png);"));

        horizontalLayout->addWidget(calBtn);

        permitBtn = new BtnCtrl(SetupPageClass);
        permitBtn->setObjectName(QString::fromUtf8("permitBtn"));
        sizePolicy.setHeightForWidth(permitBtn->sizePolicy().hasHeightForWidth());
        permitBtn->setSizePolicy(sizePolicy);
        permitBtn->setMaximumSize(QSize(70, 70));
        permitBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/Calibration.png);"));

        horizontalLayout->addWidget(permitBtn);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, -1, 0, -1);
        timeBtn = new BtnCtrl(SetupPageClass);
        timeBtn->setObjectName(QString::fromUtf8("timeBtn"));
        sizePolicy.setHeightForWidth(timeBtn->sizePolicy().hasHeightForWidth());
        timeBtn->setSizePolicy(sizePolicy);
        timeBtn->setMaximumSize(QSize(70, 70));
        timeBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/Permission.png);"));

        horizontalLayout_2->addWidget(timeBtn);

        scanBtn = new BtnCtrl(SetupPageClass);
        scanBtn->setObjectName(QString::fromUtf8("scanBtn"));
        sizePolicy.setHeightForWidth(scanBtn->sizePolicy().hasHeightForWidth());
        scanBtn->setSizePolicy(sizePolicy);
        scanBtn->setMaximumSize(QSize(70, 70));
        scanBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/Calibration.png);"));

        horizontalLayout_2->addWidget(scanBtn);

        msgBtn = new BtnCtrl(SetupPageClass);
        msgBtn->setObjectName(QString::fromUtf8("msgBtn"));
        sizePolicy.setHeightForWidth(msgBtn->sizePolicy().hasHeightForWidth());
        msgBtn->setSizePolicy(sizePolicy);
        msgBtn->setMaximumSize(QSize(70, 70));
        msgBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/message.png);"));

        horizontalLayout_2->addWidget(msgBtn);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(SetupPageClass);

        QMetaObject::connectSlotsByName(SetupPageClass);
    } // setupUi

    void retranslateUi(QWidget *SetupPageClass)
    {
        SetupPageClass->setWindowTitle(QApplication::translate("SetupPageClass", "Form", 0, QApplication::UnicodeUTF8));
        globalBtn->setText(QString());
        calBtn->setText(QString());
        permitBtn->setText(QString());
        timeBtn->setText(QString());
        scanBtn->setText(QString());
        msgBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetupPageClass: public Ui_SetupPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPPAGE_H
