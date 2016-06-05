/********************************************************************************
** Form generated from reading UI file 'RunParamPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNPARAMPAGE_H
#define UI_RUNPARAMPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "comboctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_RunParamPageClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_11;
    EditCtrl *wLen1Edit;
    QLabel *label_10;
    QLabel *label_2;
    EditCtrl *wLen2Edit;
    QLabel *label_3;
    QLabel *label_6;
    ComboCtrl *lhtCombo;
    QLabel *label_4;
    QLabel *label_5;
    ComboCtrl *timeCombo;
    QLabel *label_12;
    BtnCtrl *lpBtn;
    QLabel *label_7;
    ComboCtrl *sDispCombo;
    QLabel *label_8;
    ComboCtrl *rDispCombo;
    ComboCtrl *rangeCombo;
    ComboCtrl *chlCombo;
    EditCtrl *lampEdit;

    void setupUi(QWidget *RunParamPageClass)
    {
        if (RunParamPageClass->objectName().isEmpty())
            RunParamPageClass->setObjectName(QString::fromUtf8("RunParamPageClass"));
        RunParamPageClass->resize(320, 190);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RunParamPageClass->sizePolicy().hasHeightForWidth());
        RunParamPageClass->setSizePolicy(sizePolicy);
        RunParamPageClass->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(RunParamPageClass);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RunParamPageClass);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 2, 1);

        line = new QFrame(RunParamPageClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 6, 3);

        label_11 = new QLabel(RunParamPageClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 0, 7, 2, 1);

        wLen1Edit = new EditCtrl(RunParamPageClass);
        wLen1Edit->setObjectName(QString::fromUtf8("wLen1Edit"));
        sizePolicy.setHeightForWidth(wLen1Edit->sizePolicy().hasHeightForWidth());
        wLen1Edit->setSizePolicy(sizePolicy);
        wLen1Edit->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(wLen1Edit, 1, 1, 1, 1);

        label_10 = new QLabel(RunParamPageClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        label_2 = new QLabel(RunParamPageClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 4, 1, 2);

        wLen2Edit = new EditCtrl(RunParamPageClass);
        wLen2Edit->setObjectName(QString::fromUtf8("wLen2Edit"));
        sizePolicy.setHeightForWidth(wLen2Edit->sizePolicy().hasHeightForWidth());
        wLen2Edit->setSizePolicy(sizePolicy);
        wLen2Edit->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(wLen2Edit, 1, 6, 1, 1);

        label_3 = new QLabel(RunParamPageClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(RunParamPageClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 2, 5, 1, 1);

        lhtCombo = new ComboCtrl(RunParamPageClass);
        lhtCombo->setObjectName(QString::fromUtf8("lhtCombo"));
        sizePolicy.setHeightForWidth(lhtCombo->sizePolicy().hasHeightForWidth());
        lhtCombo->setSizePolicy(sizePolicy);
        lhtCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(lhtCombo, 2, 6, 1, 1);

        label_4 = new QLabel(RunParamPageClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(RunParamPageClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 3, 5, 1, 1);

        timeCombo = new ComboCtrl(RunParamPageClass);
        timeCombo->setObjectName(QString::fromUtf8("timeCombo"));
        sizePolicy.setHeightForWidth(timeCombo->sizePolicy().hasHeightForWidth());
        timeCombo->setSizePolicy(sizePolicy);
        timeCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(timeCombo, 3, 6, 1, 1);

        label_12 = new QLabel(RunParamPageClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 3, 7, 1, 1);

        lpBtn = new BtnCtrl(RunParamPageClass);
        lpBtn->setObjectName(QString::fromUtf8("lpBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lpBtn->sizePolicy().hasHeightForWidth());
        lpBtn->setSizePolicy(sizePolicy2);
        lpBtn->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(lpBtn, 4, 0, 1, 1);

        label_7 = new QLabel(RunParamPageClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 4, 5, 1, 1);

        sDispCombo = new ComboCtrl(RunParamPageClass);
        sDispCombo->setObjectName(QString::fromUtf8("sDispCombo"));
        sizePolicy.setHeightForWidth(sDispCombo->sizePolicy().hasHeightForWidth());
        sDispCombo->setSizePolicy(sizePolicy);
        sDispCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(sDispCombo, 4, 6, 1, 1);

        label_8 = new QLabel(RunParamPageClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_8, 5, 5, 1, 1);

        rDispCombo = new ComboCtrl(RunParamPageClass);
        rDispCombo->setObjectName(QString::fromUtf8("rDispCombo"));
        sizePolicy.setHeightForWidth(rDispCombo->sizePolicy().hasHeightForWidth());
        rDispCombo->setSizePolicy(sizePolicy);
        rDispCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(rDispCombo, 5, 6, 1, 1);

        rangeCombo = new ComboCtrl(RunParamPageClass);
        rangeCombo->setObjectName(QString::fromUtf8("rangeCombo"));
        sizePolicy.setHeightForWidth(rangeCombo->sizePolicy().hasHeightForWidth());
        rangeCombo->setSizePolicy(sizePolicy);
        rangeCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(rangeCombo, 3, 1, 1, 2);

        chlCombo = new ComboCtrl(RunParamPageClass);
        chlCombo->setObjectName(QString::fromUtf8("chlCombo"));
        sizePolicy.setHeightForWidth(chlCombo->sizePolicy().hasHeightForWidth());
        chlCombo->setSizePolicy(sizePolicy);
        chlCombo->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(chlCombo, 2, 1, 1, 2);

        lampEdit = new EditCtrl(RunParamPageClass);
        lampEdit->setObjectName(QString::fromUtf8("lampEdit"));
        sizePolicy.setHeightForWidth(lampEdit->sizePolicy().hasHeightForWidth());
        lampEdit->setSizePolicy(sizePolicy);
        lampEdit->setMaximumSize(QSize(16777215, 28));

        gridLayout->addWidget(lampEdit, 4, 1, 1, 2);


        retranslateUi(RunParamPageClass);

        QMetaObject::connectSlotsByName(RunParamPageClass);
    } // setupUi

    void retranslateUi(QWidget *RunParamPageClass)
    {
        RunParamPageClass->setWindowTitle(QApplication::translate("RunParamPageClass", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RunParamPageClass", "W.Len1", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("RunParamPageClass", "nm", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RunParamPageClass", "nm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RunParamPageClass", "W.Len2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RunParamPageClass", "Chnl", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RunParamPageClass", "Lamp", 0, QApplication::UnicodeUTF8));
        lhtCombo->clear();
        lhtCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "D.Lamp", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "H.Lamp", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("RunParamPageClass", "R.CST", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RunParamPageClass", "T.CST", 0, QApplication::UnicodeUTF8));
        timeCombo->clear();
        timeCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "0.1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "10", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("RunParamPageClass", "s", 0, QApplication::UnicodeUTF8));
        lpBtn->setText(QApplication::translate("RunParamPageClass", "Lp.Ch", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RunParamPageClass", "S.Val", 0, QApplication::UnicodeUTF8));
        sDispCombo->clear();
        sDispCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "Hide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "Show", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("RunParamPageClass", "R.Val", 0, QApplication::UnicodeUTF8));
        rDispCombo->clear();
        rDispCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "Hide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "Show", 0, QApplication::UnicodeUTF8)
        );
        rangeCombo->clear();
        rangeCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "0.0001", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.0002", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.0005", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.001", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.002", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.005", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "0.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "10", 0, QApplication::UnicodeUTF8)
        );
        chlCombo->clear();
        chlCombo->insertItems(0, QStringList()
         << QApplication::translate("RunParamPageClass", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunParamPageClass", "2", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class RunParamPageClass: public Ui_RunParamPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNPARAMPAGE_H
