/********************************************************************************
** Form generated from reading UI file 'GradientTable.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADIENTTABLE_H
#define UI_GRADIENTTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "btnctrl.h"
#include "tablectrl.h"

QT_BEGIN_NAMESPACE

class Ui_GradientTableClass
{
public:
    QVBoxLayout *verticalLayout;
    TableCtrl *tableView;
    QHBoxLayout *horizontalLayout;
    BtnCtrl *saveBtn;
    BtnCtrl *backBtn;

    void setupUi(QWidget *GradientTableClass)
    {
        if (GradientTableClass->objectName().isEmpty())
            GradientTableClass->setObjectName(QString::fromUtf8("GradientTableClass"));
        GradientTableClass->resize(328, 205);
        verticalLayout = new QVBoxLayout(GradientTableClass);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new TableCtrl(GradientTableClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveBtn = new BtnCtrl(GradientTableClass);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        horizontalLayout->addWidget(saveBtn);

        backBtn = new BtnCtrl(GradientTableClass);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));

        horizontalLayout->addWidget(backBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GradientTableClass);

        QMetaObject::connectSlotsByName(GradientTableClass);
    } // setupUi

    void retranslateUi(QWidget *GradientTableClass)
    {
        GradientTableClass->setWindowTitle(QApplication::translate("GradientTableClass", "Form", 0, QApplication::UnicodeUTF8));
        saveBtn->setText(QApplication::translate("GradientTableClass", "Save", 0, QApplication::UnicodeUTF8));
        backBtn->setText(QApplication::translate("GradientTableClass", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GradientTableClass: public Ui_GradientTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADIENTTABLE_H
