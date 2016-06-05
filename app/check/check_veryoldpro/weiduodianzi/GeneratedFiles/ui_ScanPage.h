/********************************************************************************
** Form generated from reading UI file 'ScanPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANPAGE_H
#define UI_SCANPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "comboctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_ScanPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EditCtrl *sWlen;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    EditCtrl *eWlen;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    EditCtrl *sTime;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *wLenLbl;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *auLbl;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *sLbl;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *rLbl;
    QHBoxLayout *horizontalLayout_10;
    BtnCtrl *scanBtn;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    ComboCtrl *uploadWhichCombo;

    void setupUi(QWidget *ScanPage)
    {
        if (ScanPage->objectName().isEmpty())
            ScanPage->setObjectName(QString::fromUtf8("ScanPage"));
        ScanPage->resize(320, 195);
        gridLayout = new QGridLayout(ScanPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ScanPage);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        sWlen = new EditCtrl(ScanPage);
        sWlen->setObjectName(QString::fromUtf8("sWlen"));
        sizePolicy.setHeightForWidth(sWlen->sizePolicy().hasHeightForWidth());
        sWlen->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(sWlen);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ScanPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        eWlen = new EditCtrl(ScanPage);
        eWlen->setObjectName(QString::fromUtf8("eWlen"));
        sizePolicy.setHeightForWidth(eWlen->sizePolicy().hasHeightForWidth());
        eWlen->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(eWlen);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(ScanPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        sTime = new EditCtrl(ScanPage);
        sTime->setObjectName(QString::fromUtf8("sTime"));
        sizePolicy.setHeightForWidth(sTime->sizePolicy().hasHeightForWidth());
        sTime->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(sTime);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(ScanPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_4);

        wLenLbl = new QLabel(ScanPage);
        wLenLbl->setObjectName(QString::fromUtf8("wLenLbl"));
        sizePolicy.setHeightForWidth(wLenLbl->sizePolicy().hasHeightForWidth());
        wLenLbl->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(wLenLbl);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);

        horizontalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(ScanPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_5);

        auLbl = new QLabel(ScanPage);
        auLbl->setObjectName(QString::fromUtf8("auLbl"));
        sizePolicy.setHeightForWidth(auLbl->sizePolicy().hasHeightForWidth());
        auLbl->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(auLbl);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        horizontalLayout_9->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(ScanPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_6);

        sLbl = new QLabel(ScanPage);
        sLbl->setObjectName(QString::fromUtf8("sLbl"));
        sizePolicy.setHeightForWidth(sLbl->sizePolicy().hasHeightForWidth());
        sLbl->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(sLbl);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(ScanPage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(label_7);

        rLbl = new QLabel(ScanPage);
        rLbl->setObjectName(QString::fromUtf8("rLbl"));
        sizePolicy.setHeightForWidth(rLbl->sizePolicy().hasHeightForWidth());
        rLbl->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(rLbl);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        scanBtn = new BtnCtrl(ScanPage);
        scanBtn->setObjectName(QString::fromUtf8("scanBtn"));
        sizePolicy.setHeightForWidth(scanBtn->sizePolicy().hasHeightForWidth());
        scanBtn->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(scanBtn);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(ScanPage);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        uploadWhichCombo = new ComboCtrl(ScanPage);
        uploadWhichCombo->setObjectName(QString::fromUtf8("uploadWhichCombo"));
        sizePolicy.setHeightForWidth(uploadWhichCombo->sizePolicy().hasHeightForWidth());
        uploadWhichCombo->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(uploadWhichCombo);


        horizontalLayout_10->addLayout(horizontalLayout_6);


        gridLayout->addLayout(horizontalLayout_10, 1, 0, 1, 2);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(ScanPage);

        QMetaObject::connectSlotsByName(ScanPage);
    } // setupUi

    void retranslateUi(QWidget *ScanPage)
    {
        ScanPage->setWindowTitle(QApplication::translate("ScanPage", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScanPage", "S.WLen:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ScanPage", "E.WLen:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ScanPage", "Sc.Tm:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ScanPage", "WLen:", 0, QApplication::UnicodeUTF8));
        wLenLbl->setText(QApplication::translate("ScanPage", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ScanPage", "Au:", 0, QApplication::UnicodeUTF8));
        auLbl->setText(QApplication::translate("ScanPage", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ScanPage", "S:", 0, QApplication::UnicodeUTF8));
        sLbl->setText(QApplication::translate("ScanPage", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ScanPage", "R:", 0, QApplication::UnicodeUTF8));
        rLbl->setText(QApplication::translate("ScanPage", "0", 0, QApplication::UnicodeUTF8));
        scanBtn->setText(QApplication::translate("ScanPage", "Scan", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ScanPage", "Upload", 0, QApplication::UnicodeUTF8));
        uploadWhichCombo->clear();
        uploadWhichCombo->insertItems(0, QStringList()
         << QApplication::translate("ScanPage", "Au", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScanPage", "S", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScanPage", "R", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class ScanPage: public Ui_ScanPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANPAGE_H
