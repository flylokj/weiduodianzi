/********************************************************************************
** Form generated from reading UI file 'AdminPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "comboctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_AdminPage
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    BtnCtrl *activeBtn;
    BtnCtrl *utcBtn;
    BtnCtrl *xtcBtn;
    BtnCtrl *ttcBtn;
    BtnCtrl *lpcBtn;
    BtnCtrl *rstBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    EditCtrl *instYearEdit;
    QLabel *label_7;
    EditCtrl *instMonthEdit;
    QLabel *label_8;
    EditCtrl *instDayEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    EditCtrl *licenseEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    EditCtrl *serialEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    EditCtrl *dayEdit;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    ComboCtrl *proCombo;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AdminPage)
    {
        if (AdminPage->objectName().isEmpty())
            AdminPage->setObjectName(QString::fromUtf8("AdminPage"));
        AdminPage->resize(419, 240);
        gridLayout = new QGridLayout(AdminPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        activeBtn = new BtnCtrl(AdminPage);
        activeBtn->setObjectName(QString::fromUtf8("activeBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(activeBtn->sizePolicy().hasHeightForWidth());
        activeBtn->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(activeBtn);

        utcBtn = new BtnCtrl(AdminPage);
        utcBtn->setObjectName(QString::fromUtf8("utcBtn"));
        sizePolicy.setHeightForWidth(utcBtn->sizePolicy().hasHeightForWidth());
        utcBtn->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(utcBtn);

        xtcBtn = new BtnCtrl(AdminPage);
        xtcBtn->setObjectName(QString::fromUtf8("xtcBtn"));
        sizePolicy.setHeightForWidth(xtcBtn->sizePolicy().hasHeightForWidth());
        xtcBtn->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(xtcBtn);

        ttcBtn = new BtnCtrl(AdminPage);
        ttcBtn->setObjectName(QString::fromUtf8("ttcBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ttcBtn->sizePolicy().hasHeightForWidth());
        ttcBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(ttcBtn);

        lpcBtn = new BtnCtrl(AdminPage);
        lpcBtn->setObjectName(QString::fromUtf8("lpcBtn"));
        sizePolicy1.setHeightForWidth(lpcBtn->sizePolicy().hasHeightForWidth());
        lpcBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lpcBtn);

        rstBtn = new BtnCtrl(AdminPage);
        rstBtn->setObjectName(QString::fromUtf8("rstBtn"));
        sizePolicy1.setHeightForWidth(rstBtn->sizePolicy().hasHeightForWidth());
        rstBtn->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(rstBtn);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(AdminPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        instYearEdit = new EditCtrl(AdminPage);
        instYearEdit->setObjectName(QString::fromUtf8("instYearEdit"));
        sizePolicy1.setHeightForWidth(instYearEdit->sizePolicy().hasHeightForWidth());
        instYearEdit->setSizePolicy(sizePolicy1);
        instYearEdit->setReadOnly(false);

        horizontalLayout->addWidget(instYearEdit);

        label_7 = new QLabel(AdminPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        instMonthEdit = new EditCtrl(AdminPage);
        instMonthEdit->setObjectName(QString::fromUtf8("instMonthEdit"));
        sizePolicy1.setHeightForWidth(instMonthEdit->sizePolicy().hasHeightForWidth());
        instMonthEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(instMonthEdit);

        label_8 = new QLabel(AdminPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        instDayEdit = new EditCtrl(AdminPage);
        instDayEdit->setObjectName(QString::fromUtf8("instDayEdit"));
        sizePolicy1.setHeightForWidth(instDayEdit->sizePolicy().hasHeightForWidth());
        instDayEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(instDayEdit);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(AdminPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        licenseEdit = new EditCtrl(AdminPage);
        licenseEdit->setObjectName(QString::fromUtf8("licenseEdit"));
        sizePolicy1.setHeightForWidth(licenseEdit->sizePolicy().hasHeightForWidth());
        licenseEdit->setSizePolicy(sizePolicy1);
        licenseEdit->setReadOnly(false);

        horizontalLayout_5->addWidget(licenseEdit);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(AdminPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        serialEdit = new EditCtrl(AdminPage);
        serialEdit->setObjectName(QString::fromUtf8("serialEdit"));
        sizePolicy1.setHeightForWidth(serialEdit->sizePolicy().hasHeightForWidth());
        serialEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(serialEdit);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(AdminPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        dayEdit = new EditCtrl(AdminPage);
        dayEdit->setObjectName(QString::fromUtf8("dayEdit"));
        sizePolicy1.setHeightForWidth(dayEdit->sizePolicy().hasHeightForWidth());
        dayEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(dayEdit);

        label_9 = new QLabel(AdminPage);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(AdminPage);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        proCombo = new ComboCtrl(AdminPage);
        proCombo->setObjectName(QString::fromUtf8("proCombo"));

        horizontalLayout_4->addWidget(proCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);


        retranslateUi(AdminPage);

        QMetaObject::connectSlotsByName(AdminPage);
    } // setupUi

    void retranslateUi(QWidget *AdminPage)
    {
        AdminPage->setWindowTitle(QApplication::translate("AdminPage", "Form", 0, QApplication::UnicodeUTF8));
        activeBtn->setText(QApplication::translate("AdminPage", "DAC", 0, QApplication::UnicodeUTF8));
        utcBtn->setText(QApplication::translate("AdminPage", "UTC", 0, QApplication::UnicodeUTF8));
        xtcBtn->setText(QApplication::translate("AdminPage", "XTC", 0, QApplication::UnicodeUTF8));
        ttcBtn->setText(QApplication::translate("AdminPage", "TTC", 0, QApplication::UnicodeUTF8));
        lpcBtn->setText(QApplication::translate("AdminPage", "LPC", 0, QApplication::UnicodeUTF8));
        rstBtn->setText(QApplication::translate("AdminPage", "RST", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AdminPage", "Inst time:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AdminPage", "-", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AdminPage", "-", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AdminPage", "License:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AdminPage", "Serial:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AdminPage", "probation:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AdminPage", "day", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AdminPage", "Pc Protocol", 0, QApplication::UnicodeUTF8));
        proCombo->clear();
        proCombo->insertItems(0, QStringList()
         << QApplication::translate("AdminPage", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AdminPage", "Clarity", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class AdminPage: public Ui_AdminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
