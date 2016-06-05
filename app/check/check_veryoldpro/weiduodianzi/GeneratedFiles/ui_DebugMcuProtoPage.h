/********************************************************************************
** Form generated from reading UI file 'DebugMcuProtoPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGMCUPROTOPAGE_H
#define UI_DEBUGMCUPROTOPAGE_H

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
#include "editctrl.h"
#include "tablectrl.h"

QT_BEGIN_NAMESPACE

class Ui_DebugMcuProtoPageClass
{
public:
    QGridLayout *gridLayout;
    TableCtrl *tableView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    EditCtrl *flowEdit;
    BtnCtrl *startBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *pressLbl;
    BtnCtrl *clearBtn;
    BtnCtrl *collectBtn;

    void setupUi(QWidget *DebugMcuProtoPageClass)
    {
        if (DebugMcuProtoPageClass->objectName().isEmpty())
            DebugMcuProtoPageClass->setObjectName(QString::fromUtf8("DebugMcuProtoPageClass"));
        DebugMcuProtoPageClass->resize(343, 194);
        gridLayout = new QGridLayout(DebugMcuProtoPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new TableCtrl(DebugMcuProtoPageClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(DebugMcuProtoPageClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        flowEdit = new EditCtrl(DebugMcuProtoPageClass);
        flowEdit->setObjectName(QString::fromUtf8("flowEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flowEdit->sizePolicy().hasHeightForWidth());
        flowEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(flowEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        startBtn = new BtnCtrl(DebugMcuProtoPageClass);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));
        sizePolicy.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(startBtn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DebugMcuProtoPageClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pressLbl = new QLabel(DebugMcuProtoPageClass);
        pressLbl->setObjectName(QString::fromUtf8("pressLbl"));
        sizePolicy.setHeightForWidth(pressLbl->sizePolicy().hasHeightForWidth());
        pressLbl->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pressLbl);


        verticalLayout->addLayout(horizontalLayout_2);

        clearBtn = new BtnCtrl(DebugMcuProtoPageClass);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        sizePolicy.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy);
        clearBtn->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(clearBtn);

        collectBtn = new BtnCtrl(DebugMcuProtoPageClass);
        collectBtn->setObjectName(QString::fromUtf8("collectBtn"));
        sizePolicy.setHeightForWidth(collectBtn->sizePolicy().hasHeightForWidth());
        collectBtn->setSizePolicy(sizePolicy);
        collectBtn->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(collectBtn);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);
        tableView->raise();
        label_2->raise();
        collectBtn->raise();

        retranslateUi(DebugMcuProtoPageClass);

        QMetaObject::connectSlotsByName(DebugMcuProtoPageClass);
    } // setupUi

    void retranslateUi(QWidget *DebugMcuProtoPageClass)
    {
        DebugMcuProtoPageClass->setWindowTitle(QApplication::translate("DebugMcuProtoPageClass", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DebugMcuProtoPageClass", "Flow:", 0, QApplication::UnicodeUTF8));
        startBtn->setText(QApplication::translate("DebugMcuProtoPageClass", "Start/Stop", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DebugMcuProtoPageClass", "Press:", 0, QApplication::UnicodeUTF8));
        pressLbl->setText(QApplication::translate("DebugMcuProtoPageClass", "0", 0, QApplication::UnicodeUTF8));
        clearBtn->setText(QApplication::translate("DebugMcuProtoPageClass", "Clear Press", 0, QApplication::UnicodeUTF8));
        collectBtn->setText(QApplication::translate("DebugMcuProtoPageClass", "Collect/Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DebugMcuProtoPageClass: public Ui_DebugMcuProtoPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGMCUPROTOPAGE_H
