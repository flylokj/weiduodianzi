/********************************************************************************
** Form generated from reading UI file 'BaseMainPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEMAINPAGE_H
#define UI_BASEMAINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "BasePage.h"
#include "bottomwidget.h"
#include "topwidget.h"

QT_BEGIN_NAMESPACE

class Ui_BaseMainPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    TopWidget *topWidget;
    QGridLayout *gridLayout;
    CBasePage *midWidget;
    BottomWidget *bottomWidget;

    void setupUi(QMainWindow *BaseMainPage)
    {
        if (BaseMainPage->objectName().isEmpty())
            BaseMainPage->setObjectName(QString::fromUtf8("BaseMainPage"));
        BaseMainPage->resize(524, 316);
        centralwidget = new QWidget(BaseMainPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        topWidget = new TopWidget(centralwidget);
        topWidget->setObjectName(QString::fromUtf8("topWidget"));
        topWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        gridLayout = new QGridLayout(topWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addWidget(topWidget);

        midWidget = new CBasePage(centralwidget);
        midWidget->setObjectName(QString::fromUtf8("midWidget"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        midWidget->setFont(font);
        midWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(midWidget);

        bottomWidget = new BottomWidget(centralwidget);
        bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
        bottomWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(bottomWidget);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);
        BaseMainPage->setCentralWidget(centralwidget);

        retranslateUi(BaseMainPage);

        QMetaObject::connectSlotsByName(BaseMainPage);
    } // setupUi

    void retranslateUi(QMainWindow *BaseMainPage)
    {
        BaseMainPage->setWindowTitle(QApplication::translate("BaseMainPage", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BaseMainPage: public Ui_BaseMainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEMAINPAGE_H
