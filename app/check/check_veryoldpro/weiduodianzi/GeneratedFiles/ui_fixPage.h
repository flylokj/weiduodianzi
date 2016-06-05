/********************************************************************************
** Form generated from reading UI file 'fixPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXPAGE_H
#define UI_FIXPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "comboctrl.h"
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_FixPageClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EditCtrl *coefficient;
    ComboCtrl *timeInteCombo;
    BtnCtrl *wavCalBtn;

    void setupUi(QWidget *FixPageClass)
    {
        if (FixPageClass->objectName().isEmpty())
            FixPageClass->setObjectName(QString::fromUtf8("FixPageClass"));
        FixPageClass->resize(320, 195);
        gridLayout = new QGridLayout(FixPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(FixPageClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(100, 100));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/Calibration.png);"));

        horizontalLayout_2->addWidget(pushButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FixPageClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        coefficient = new EditCtrl(FixPageClass);
        coefficient->setObjectName(QString::fromUtf8("coefficient"));
        sizePolicy.setHeightForWidth(coefficient->sizePolicy().hasHeightForWidth());
        coefficient->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(coefficient);


        verticalLayout->addLayout(horizontalLayout);

        timeInteCombo = new ComboCtrl(FixPageClass);
        timeInteCombo->setObjectName(QString::fromUtf8("timeInteCombo"));
        sizePolicy.setHeightForWidth(timeInteCombo->sizePolicy().hasHeightForWidth());
        timeInteCombo->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(timeInteCombo);

        wavCalBtn = new BtnCtrl(FixPageClass);
        wavCalBtn->setObjectName(QString::fromUtf8("wavCalBtn"));
        sizePolicy.setHeightForWidth(wavCalBtn->sizePolicy().hasHeightForWidth());
        wavCalBtn->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(wavCalBtn);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(FixPageClass);

        QMetaObject::connectSlotsByName(FixPageClass);
    } // setupUi

    void retranslateUi(QWidget *FixPageClass)
    {
        FixPageClass->setWindowTitle(QApplication::translate("FixPageClass", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label->setText(QApplication::translate("FixPageClass", "B:", 0, QApplication::UnicodeUTF8));
        timeInteCombo->clear();
        timeInteCombo->insertItems(0, QStringList()
         << QApplication::translate("FixPageClass", "1/8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FixPageClass", "1/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FixPageClass", "1/2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FixPageClass", "1", 0, QApplication::UnicodeUTF8)
        );
        wavCalBtn->setText(QApplication::translate("FixPageClass", "WaveLen Calibration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FixPageClass: public Ui_FixPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXPAGE_H
