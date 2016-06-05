/********************************************************************************
** Form generated from reading UI file 'bottomwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMWIDGET_H
#define UI_BOTTOMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "btnctrl.h"

QT_BEGIN_NAMESPACE

class Ui_BottomWidget
{
public:
    QGridLayout *gridLayout;
    BtnCtrl *runBtn;
    BtnCtrl *paramBtn;
    BtnCtrl *setBtn;
    BtnCtrl *dbgBtn;
    QLabel *label;

    void setupUi(QWidget *BottomWidget)
    {
        if (BottomWidget->objectName().isEmpty())
            BottomWidget->setObjectName(QString::fromUtf8("BottomWidget"));
        BottomWidget->resize(510, 86);
        gridLayout = new QGridLayout(BottomWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        runBtn = new BtnCtrl(BottomWidget);
        runBtn->setObjectName(QString::fromUtf8("runBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(runBtn->sizePolicy().hasHeightForWidth());
        runBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(runBtn, 0, 0, 1, 1);

        paramBtn = new BtnCtrl(BottomWidget);
        paramBtn->setObjectName(QString::fromUtf8("paramBtn"));
        sizePolicy.setHeightForWidth(paramBtn->sizePolicy().hasHeightForWidth());
        paramBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(paramBtn, 0, 1, 1, 1);

        setBtn = new BtnCtrl(BottomWidget);
        setBtn->setObjectName(QString::fromUtf8("setBtn"));
        sizePolicy.setHeightForWidth(setBtn->sizePolicy().hasHeightForWidth());
        setBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(setBtn, 0, 2, 1, 1);

        dbgBtn = new BtnCtrl(BottomWidget);
        dbgBtn->setObjectName(QString::fromUtf8("dbgBtn"));
        sizePolicy.setHeightForWidth(dbgBtn->sizePolicy().hasHeightForWidth());
        dbgBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dbgBtn, 0, 3, 1, 1);

        label = new QLabel(BottomWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label, 0, 4, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 2);

        retranslateUi(BottomWidget);

        QMetaObject::connectSlotsByName(BottomWidget);
    } // setupUi

    void retranslateUi(QWidget *BottomWidget)
    {
        BottomWidget->setWindowTitle(QApplication::translate("BottomWidget", "BottomWidget", 0, QApplication::UnicodeUTF8));
        runBtn->setText(QApplication::translate("BottomWidget", "Run", 0, QApplication::UnicodeUTF8));
        paramBtn->setText(QApplication::translate("BottomWidget", "Param", 0, QApplication::UnicodeUTF8));
        setBtn->setText(QApplication::translate("BottomWidget", "Setup", 0, QApplication::UnicodeUTF8));
        dbgBtn->setText(QApplication::translate("BottomWidget", "Debug", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BottomWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BottomWidget: public Ui_BottomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMWIDGET_H
