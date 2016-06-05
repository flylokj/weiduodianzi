/********************************************************************************
** Form generated from reading UI file 'RunPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNPAGE_H
#define UI_RUNPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "comboctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_RunPageClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *auLbl2;
    QLabel *label_10;
    ComboCtrl *lampCombo;
    QFrame *line;
    QLabel *label_2;
    QLabel *lblTime;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    EditCtrl *wLen1Edit;
    QLabel *label_8;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *auLbl;
    QLabel *label_9;
    QLabel *wLen2Title;
    QHBoxLayout *horizontalLayout_2;
    EditCtrl *wLen2Edit;
    QLabel *wLen2Unit;
    QLabel *label;
    QLabel *sampleLbl;
    QLabel *label_13;
    QLabel *basicLbl;

    void setupUi(QWidget *RunPageClass)
    {
        if (RunPageClass->objectName().isEmpty())
            RunPageClass->setObjectName(QString::fromUtf8("RunPageClass"));
        RunPageClass->resize(308, 192);
        gridLayout = new QGridLayout(RunPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(RunPageClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 3, 1, 1);

        label_5 = new QLabel(RunPageClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        auLbl2 = new QLabel(RunPageClass);
        auLbl2->setObjectName(QString::fromUtf8("auLbl2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(auLbl2->sizePolicy().hasHeightForWidth());
        auLbl2->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(auLbl2);

        label_10 = new QLabel(RunPageClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        horizontalLayout_8->setStretch(0, 5);
        horizontalLayout_8->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_8, 2, 4, 1, 1);

        lampCombo = new ComboCtrl(RunPageClass);
        lampCombo->setObjectName(QString::fromUtf8("lampCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lampCombo->sizePolicy().hasHeightForWidth());
        lampCombo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lampCombo, 0, 1, 1, 1);

        line = new QFrame(RunPageClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 4, 1);

        label_2 = new QLabel(RunPageClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        lblTime = new QLabel(RunPageClass);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));

        gridLayout->addWidget(lblTime, 0, 4, 1, 1);

        label_3 = new QLabel(RunPageClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wLen1Edit = new EditCtrl(RunPageClass);
        wLen1Edit->setObjectName(QString::fromUtf8("wLen1Edit"));
        sizePolicy1.setHeightForWidth(wLen1Edit->sizePolicy().hasHeightForWidth());
        wLen1Edit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(wLen1Edit);

        label_8 = new QLabel(RunPageClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        label_6 = new QLabel(RunPageClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        auLbl = new QLabel(RunPageClass);
        auLbl->setObjectName(QString::fromUtf8("auLbl"));
        sizePolicy.setHeightForWidth(auLbl->sizePolicy().hasHeightForWidth());
        auLbl->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(auLbl);

        label_9 = new QLabel(RunPageClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        horizontalLayout_7->setStretch(0, 5);
        horizontalLayout_7->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_7, 1, 4, 1, 1);

        wLen2Title = new QLabel(RunPageClass);
        wLen2Title->setObjectName(QString::fromUtf8("wLen2Title"));

        gridLayout->addWidget(wLen2Title, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wLen2Edit = new EditCtrl(RunPageClass);
        wLen2Edit->setObjectName(QString::fromUtf8("wLen2Edit"));
        sizePolicy1.setHeightForWidth(wLen2Edit->sizePolicy().hasHeightForWidth());
        wLen2Edit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(wLen2Edit);

        wLen2Unit = new QLabel(RunPageClass);
        wLen2Unit->setObjectName(QString::fromUtf8("wLen2Unit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wLen2Unit->sizePolicy().hasHeightForWidth());
        wLen2Unit->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(wLen2Unit);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        label = new QLabel(RunPageClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        sampleLbl = new QLabel(RunPageClass);
        sampleLbl->setObjectName(QString::fromUtf8("sampleLbl"));

        gridLayout->addWidget(sampleLbl, 3, 1, 1, 1);

        label_13 = new QLabel(RunPageClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 3, 3, 1, 1);

        basicLbl = new QLabel(RunPageClass);
        basicLbl->setObjectName(QString::fromUtf8("basicLbl"));

        gridLayout->addWidget(basicLbl, 3, 4, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(0, 1);
        lampCombo->raise();
        label_3->raise();
        label_6->raise();
        wLen2Title->raise();
        label_7->raise();
        label->raise();
        sampleLbl->raise();
        label_13->raise();
        basicLbl->raise();
        label_5->raise();
        line->raise();
        label_2->raise();
        lblTime->raise();

        retranslateUi(RunPageClass);

        QMetaObject::connectSlotsByName(RunPageClass);
    } // setupUi

    void retranslateUi(QWidget *RunPageClass)
    {
        RunPageClass->setWindowTitle(QApplication::translate("RunPageClass", "Form", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RunPageClass", "Abs:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RunPageClass", "Lamp", 0, QApplication::UnicodeUTF8));
        auLbl2->setText(QApplication::translate("RunPageClass", "00000000", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RunPageClass", "AU", 0, QApplication::UnicodeUTF8));
        lampCombo->clear();
        lampCombo->insertItems(0, QStringList()
         << QApplication::translate("RunPageClass", "On", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RunPageClass", "Off", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("RunPageClass", "R.Time:", 0, QApplication::UnicodeUTF8));
        lblTime->setText(QApplication::translate("RunPageClass", "00:00:00", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RunPageClass", "W.Len1:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RunPageClass", "nm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RunPageClass", "Abs:", 0, QApplication::UnicodeUTF8));
        auLbl->setText(QApplication::translate("RunPageClass", "00000000", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("RunPageClass", "AU", 0, QApplication::UnicodeUTF8));
        wLen2Title->setText(QApplication::translate("RunPageClass", "W.Len2:", 0, QApplication::UnicodeUTF8));
        wLen2Unit->setText(QApplication::translate("RunPageClass", "nm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RunPageClass", "S.Val:", 0, QApplication::UnicodeUTF8));
        sampleLbl->setText(QApplication::translate("RunPageClass", "0000000000", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("RunPageClass", "R.Val:", 0, QApplication::UnicodeUTF8));
        basicLbl->setText(QApplication::translate("RunPageClass", "0000000000", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunPageClass: public Ui_RunPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNPAGE_H
