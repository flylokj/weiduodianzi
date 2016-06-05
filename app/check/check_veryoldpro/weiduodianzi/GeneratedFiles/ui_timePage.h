/********************************************************************************
** Form generated from reading UI file 'timePage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEPAGE_H
#define UI_TIMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_TimePageClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    EditCtrl *yearEdit;
    QLabel *label_8;
    EditCtrl *monthEdit;
    QLabel *label_17;
    EditCtrl *dayEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    EditCtrl *hourEdit;
    QLabel *label_9;
    EditCtrl *minEdit;
    QLabel *label_18;
    EditCtrl *secEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *instLabel;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *usedTimeLbl;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *lpUsedLbl0;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLabel *lpUsedLbl;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    BtnCtrl *historyBtn;
    QLabel *lpUsedsLbl;
    QLabel *label_13;

    void setupUi(QWidget *TimePageClass)
    {
        if (TimePageClass->objectName().isEmpty())
            TimePageClass->setObjectName(QString::fromUtf8("TimePageClass"));
        TimePageClass->resize(320, 195);
        verticalLayout = new QVBoxLayout(TimePageClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(TimePageClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        yearEdit = new EditCtrl(TimePageClass);
        yearEdit->setObjectName(QString::fromUtf8("yearEdit"));

        horizontalLayout_2->addWidget(yearEdit);

        label_8 = new QLabel(TimePageClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        monthEdit = new EditCtrl(TimePageClass);
        monthEdit->setObjectName(QString::fromUtf8("monthEdit"));

        horizontalLayout_2->addWidget(monthEdit);

        label_17 = new QLabel(TimePageClass);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_2->addWidget(label_17);

        dayEdit = new EditCtrl(TimePageClass);
        dayEdit->setObjectName(QString::fromUtf8("dayEdit"));

        horizontalLayout_2->addWidget(dayEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(TimePageClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_6);

        hourEdit = new EditCtrl(TimePageClass);
        hourEdit->setObjectName(QString::fromUtf8("hourEdit"));

        horizontalLayout_4->addWidget(hourEdit);

        label_9 = new QLabel(TimePageClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        minEdit = new EditCtrl(TimePageClass);
        minEdit->setObjectName(QString::fromUtf8("minEdit"));

        horizontalLayout_4->addWidget(minEdit);

        label_18 = new QLabel(TimePageClass);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_4->addWidget(label_18);

        secEdit = new EditCtrl(TimePageClass);
        secEdit->setObjectName(QString::fromUtf8("secEdit"));

        horizontalLayout_4->addWidget(secEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(TimePageClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        instLabel = new QLabel(TimePageClass);
        instLabel->setObjectName(QString::fromUtf8("instLabel"));

        horizontalLayout->addWidget(instLabel);

        label = new QLabel(TimePageClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(TimePageClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        usedTimeLbl = new QLabel(TimePageClass);
        usedTimeLbl->setObjectName(QString::fromUtf8("usedTimeLbl"));

        horizontalLayout_3->addWidget(usedTimeLbl);

        label_7 = new QLabel(TimePageClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 5);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(TimePageClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        lpUsedLbl0 = new QLabel(TimePageClass);
        lpUsedLbl0->setObjectName(QString::fromUtf8("lpUsedLbl0"));

        horizontalLayout_7->addWidget(lpUsedLbl0);

        label_14 = new QLabel(TimePageClass);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_7->addWidget(label_14);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 5);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(TimePageClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        lpUsedLbl = new QLabel(TimePageClass);
        lpUsedLbl->setObjectName(QString::fromUtf8("lpUsedLbl"));

        horizontalLayout_5->addWidget(lpUsedLbl);

        label_12 = new QLabel(TimePageClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        historyBtn = new BtnCtrl(TimePageClass);
        historyBtn->setObjectName(QString::fromUtf8("historyBtn"));

        horizontalLayout_6->addWidget(historyBtn);

        lpUsedsLbl = new QLabel(TimePageClass);
        lpUsedsLbl->setObjectName(QString::fromUtf8("lpUsedsLbl"));

        horizontalLayout_6->addWidget(lpUsedsLbl);

        label_13 = new QLabel(TimePageClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);

        horizontalLayout_6->setStretch(1, 5);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(TimePageClass);

        QMetaObject::connectSlotsByName(TimePageClass);
    } // setupUi

    void retranslateUi(QWidget *TimePageClass)
    {
        TimePageClass->setWindowTitle(QApplication::translate("TimePageClass", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TimePageClass", "Cur Date", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TimePageClass", "-", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("TimePageClass", "-", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TimePageClass", "Cur Time", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TimePageClass", "-", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("TimePageClass", "-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TimePageClass", "Inst.Date:", 0, QApplication::UnicodeUTF8));
        instLabel->setText(QApplication::translate("TimePageClass", "2015-10-10", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_4->setText(QApplication::translate("TimePageClass", "Use.Time:", 0, QApplication::UnicodeUTF8));
        usedTimeLbl->setText(QApplication::translate("TimePageClass", "1000h", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label_11->setText(QApplication::translate("TimePageClass", "Xe.Time:", 0, QApplication::UnicodeUTF8));
        lpUsedLbl0->setText(QApplication::translate("TimePageClass", "500h", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label_10->setText(QApplication::translate("TimePageClass", "Tun.Time:", 0, QApplication::UnicodeUTF8));
        lpUsedLbl->setText(QApplication::translate("TimePageClass", "500h", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        historyBtn->setText(QApplication::translate("TimePageClass", "Lamp History", 0, QApplication::UnicodeUTF8));
        lpUsedsLbl->setText(QString());
        label_13->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TimePageClass: public Ui_TimePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEPAGE_H
