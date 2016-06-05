/********************************************************************************
** Form generated from reading UI file 'PermitPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERMITPAGE_H
#define UI_PERMITPAGE_H

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
#include "imgbutton.h"

QT_BEGIN_NAMESPACE

class Ui_PermitPageClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    BtnCtrl *serialBtn;
    ImgButton *permitBtn;
    QVBoxLayout *verticalLayout_2;
    EditCtrl *licenseEdit;
    BtnCtrl *registerBtn;
    BtnCtrl *updateBtn;
    QLabel *labelTips_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QLabel *labelDay;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    EditCtrl *ipEdit1;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    EditCtrl *ipEdit2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    EditCtrl *ipEdit3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    EditCtrl *ipEdit4;
    QLabel *label_7;

    void setupUi(QWidget *PermitPageClass)
    {
        if (PermitPageClass->objectName().isEmpty())
            PermitPageClass->setObjectName(QString::fromUtf8("PermitPageClass"));
        PermitPageClass->resize(348, 211);
        gridLayout = new QGridLayout(PermitPageClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        serialBtn = new BtnCtrl(PermitPageClass);
        serialBtn->setObjectName(QString::fromUtf8("serialBtn"));

        verticalLayout->addWidget(serialBtn);

        permitBtn = new ImgButton(PermitPageClass);
        permitBtn->setObjectName(QString::fromUtf8("permitBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(permitBtn->sizePolicy().hasHeightForWidth());
        permitBtn->setSizePolicy(sizePolicy);
        permitBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/Permission.png);"));

        verticalLayout->addWidget(permitBtn);

        verticalLayout->setStretch(1, 4);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        licenseEdit = new EditCtrl(PermitPageClass);
        licenseEdit->setObjectName(QString::fromUtf8("licenseEdit"));
        sizePolicy.setHeightForWidth(licenseEdit->sizePolicy().hasHeightForWidth());
        licenseEdit->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(licenseEdit);

        registerBtn = new BtnCtrl(PermitPageClass);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));
        sizePolicy.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(registerBtn);

        updateBtn = new BtnCtrl(PermitPageClass);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        sizePolicy.setHeightForWidth(updateBtn->sizePolicy().hasHeightForWidth());
        updateBtn->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(updateBtn);

        labelTips_2 = new QLabel(PermitPageClass);
        labelTips_2->setObjectName(QString::fromUtf8("labelTips_2"));
        sizePolicy.setHeightForWidth(labelTips_2->sizePolicy().hasHeightForWidth());
        labelTips_2->setSizePolicy(sizePolicy);
        labelTips_2->setLayoutDirection(Qt::LeftToRight);
        labelTips_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        verticalLayout_2->addWidget(labelTips_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label1 = new QLabel(PermitPageClass);
        label1->setObjectName(QString::fromUtf8("label1"));
        sizePolicy.setHeightForWidth(label1->sizePolicy().hasHeightForWidth());
        label1->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label1);

        labelDay = new QLabel(PermitPageClass);
        labelDay->setObjectName(QString::fromUtf8("labelDay"));
        sizePolicy.setHeightForWidth(labelDay->sizePolicy().hasHeightForWidth());
        labelDay->setSizePolicy(sizePolicy);
        labelDay->setLayoutDirection(Qt::LeftToRight);
        labelDay->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        horizontalLayout->addWidget(labelDay);

        label = new QLabel(PermitPageClass);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(PermitPageClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(PermitPageClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ipEdit1 = new EditCtrl(PermitPageClass);
        ipEdit1->setObjectName(QString::fromUtf8("ipEdit1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ipEdit1->sizePolicy().hasHeightForWidth());
        ipEdit1->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(ipEdit1);

        label_4 = new QLabel(PermitPageClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ipEdit2 = new EditCtrl(PermitPageClass);
        ipEdit2->setObjectName(QString::fromUtf8("ipEdit2"));
        sizePolicy1.setHeightForWidth(ipEdit2->sizePolicy().hasHeightForWidth());
        ipEdit2->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ipEdit2);

        label_5 = new QLabel(PermitPageClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ipEdit3 = new EditCtrl(PermitPageClass);
        ipEdit3->setObjectName(QString::fromUtf8("ipEdit3"));
        sizePolicy1.setHeightForWidth(ipEdit3->sizePolicy().hasHeightForWidth());
        ipEdit3->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(ipEdit3);

        label_6 = new QLabel(PermitPageClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ipEdit4 = new EditCtrl(PermitPageClass);
        ipEdit4->setObjectName(QString::fromUtf8("ipEdit4"));
        sizePolicy1.setHeightForWidth(ipEdit4->sizePolicy().hasHeightForWidth());
        ipEdit4->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(ipEdit4);

        label_7 = new QLabel(PermitPageClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 2);


        retranslateUi(PermitPageClass);

        QMetaObject::connectSlotsByName(PermitPageClass);
    } // setupUi

    void retranslateUi(QWidget *PermitPageClass)
    {
        PermitPageClass->setWindowTitle(QApplication::translate("PermitPageClass", "Form", 0, QApplication::UnicodeUTF8));
        serialBtn->setText(QApplication::translate("PermitPageClass", "Serial", 0, QApplication::UnicodeUTF8));
        permitBtn->setText(QString());
        registerBtn->setText(QApplication::translate("PermitPageClass", "Active", 0, QApplication::UnicodeUTF8));
        updateBtn->setText(QApplication::translate("PermitPageClass", "Update", 0, QApplication::UnicodeUTF8));
        labelTips_2->setText(QApplication::translate("PermitPageClass", "Tips", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("PermitPageClass", "Probation period:", 0, QApplication::UnicodeUTF8));
        labelDay->setText(QString());
        label->setText(QApplication::translate("PermitPageClass", "day", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PermitPageClass", "Please input the license", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PermitPageClass", "IP:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PermitPageClass", ".", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PermitPageClass", ".", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PermitPageClass", ".", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PermitPageClass: public Ui_PermitPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERMITPAGE_H
