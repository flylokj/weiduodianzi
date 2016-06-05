/********************************************************************************
** Form generated from reading UI file 'MsgPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGPAGE_H
#define UI_MSGPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "imgbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MsgPageClass
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    ImgButton *msgBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelVersion;
    QLabel *labelVersionx;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelLicense;
    QLabel *labelLicensex;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelSerial;
    QLabel *labelSerialx;

    void setupUi(QWidget *MsgPageClass)
    {
        if (MsgPageClass->objectName().isEmpty())
            MsgPageClass->setObjectName(QString::fromUtf8("MsgPageClass"));
        MsgPageClass->resize(320, 195);
        horizontalLayout_4 = new QHBoxLayout(MsgPageClass);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        msgBtn = new ImgButton(MsgPageClass);
        msgBtn->setObjectName(QString::fromUtf8("msgBtn"));
        msgBtn->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msgBtn->sizePolicy().hasHeightForWidth());
        msgBtn->setSizePolicy(sizePolicy);
        msgBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/message.png);"));

        verticalLayout->addWidget(msgBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelVersion = new QLabel(MsgPageClass);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));

        horizontalLayout->addWidget(labelVersion);

        labelVersionx = new QLabel(MsgPageClass);
        labelVersionx->setObjectName(QString::fromUtf8("labelVersionx"));

        horizontalLayout->addWidget(labelVersionx);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelLicense = new QLabel(MsgPageClass);
        labelLicense->setObjectName(QString::fromUtf8("labelLicense"));

        horizontalLayout_2->addWidget(labelLicense);

        labelLicensex = new QLabel(MsgPageClass);
        labelLicensex->setObjectName(QString::fromUtf8("labelLicensex"));

        horizontalLayout_2->addWidget(labelLicensex);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelSerial = new QLabel(MsgPageClass);
        labelSerial->setObjectName(QString::fromUtf8("labelSerial"));

        horizontalLayout_3->addWidget(labelSerial);

        labelSerialx = new QLabel(MsgPageClass);
        labelSerialx->setObjectName(QString::fromUtf8("labelSerialx"));

        horizontalLayout_3->addWidget(labelSerialx);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);

        retranslateUi(MsgPageClass);

        QMetaObject::connectSlotsByName(MsgPageClass);
    } // setupUi

    void retranslateUi(QWidget *MsgPageClass)
    {
        MsgPageClass->setWindowTitle(QApplication::translate("MsgPageClass", "Form", 0, QApplication::UnicodeUTF8));
        msgBtn->setText(QString());
        labelVersion->setText(QApplication::translate("MsgPageClass", "Version:", 0, QApplication::UnicodeUTF8));
        labelVersionx->setText(QApplication::translate("MsgPageClass", "xxxxx", 0, QApplication::UnicodeUTF8));
        labelLicense->setText(QApplication::translate("MsgPageClass", "License:", 0, QApplication::UnicodeUTF8));
        labelLicensex->setText(QApplication::translate("MsgPageClass", "xxxxx", 0, QApplication::UnicodeUTF8));
        labelSerial->setText(QApplication::translate("MsgPageClass", "Serial:", 0, QApplication::UnicodeUTF8));
        labelSerialx->setText(QApplication::translate("MsgPageClass", "xxxxx", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MsgPageClass: public Ui_MsgPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGPAGE_H
