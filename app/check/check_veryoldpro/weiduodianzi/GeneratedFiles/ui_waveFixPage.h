/********************************************************************************
** Form generated from reading UI file 'waveFixPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFIXPAGE_H
#define UI_WAVEFIXPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "editctrl.h"
#include "tablectrl.h"

QT_BEGIN_NAMESPACE

class Ui_WaveFixPageClass
{
public:
    QGridLayout *gridLayout;
    TableCtrl *tableView;
    QHBoxLayout *horizontalLayout;
    BtnCtrl *saveBtn;
    BtnCtrl *backBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    EditCtrl *wlenEdit;

    void setupUi(QWidget *WaveFixPageClass)
    {
        if (WaveFixPageClass->objectName().isEmpty())
            WaveFixPageClass->setObjectName(QString::fromUtf8("WaveFixPageClass"));
        WaveFixPageClass->resize(328, 205);
        gridLayout = new QGridLayout(WaveFixPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(5, 0, 5, 5);
        tableView = new TableCtrl(WaveFixPageClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveBtn = new BtnCtrl(WaveFixPageClass);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        horizontalLayout->addWidget(saveBtn);

        backBtn = new BtnCtrl(WaveFixPageClass);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));

        horizontalLayout->addWidget(backBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(WaveFixPageClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        wlenEdit = new EditCtrl(WaveFixPageClass);
        wlenEdit->setObjectName(QString::fromUtf8("wlenEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wlenEdit->sizePolicy().hasHeightForWidth());
        wlenEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(wlenEdit);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(WaveFixPageClass);

        QMetaObject::connectSlotsByName(WaveFixPageClass);
    } // setupUi

    void retranslateUi(QWidget *WaveFixPageClass)
    {
        WaveFixPageClass->setWindowTitle(QApplication::translate("WaveFixPageClass", "Form", 0, QApplication::UnicodeUTF8));
        saveBtn->setText(QApplication::translate("WaveFixPageClass", "Save", 0, QApplication::UnicodeUTF8));
        backBtn->setText(QApplication::translate("WaveFixPageClass", "Back", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WaveFixPageClass", "wlen:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WaveFixPageClass: public Ui_WaveFixPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFIXPAGE_H
