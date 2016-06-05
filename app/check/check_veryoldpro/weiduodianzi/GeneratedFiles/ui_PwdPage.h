/********************************************************************************
** Form generated from reading UI file 'PwdPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWDPAGE_H
#define UI_PWDPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "editctrl.h"

QT_BEGIN_NAMESPACE

class Ui_PwdPage
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    EditCtrl *usrEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    EditCtrl *pwdEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QPushButton *loginBtn;
    QLabel *label;

    void setupUi(QWidget *PwdPage)
    {
        if (PwdPage->objectName().isEmpty())
            PwdPage->setObjectName(QString::fromUtf8("PwdPage"));
        PwdPage->resize(320, 195);
        horizontalLayout_4 = new QHBoxLayout(PwdPage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 30, -1, 30);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(PwdPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/user.png);"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(PwdPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_6);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(PwdPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        usrEdit = new EditCtrl(PwdPage);
        usrEdit->setObjectName(QString::fromUtf8("usrEdit"));
        sizePolicy.setHeightForWidth(usrEdit->sizePolicy().hasHeightForWidth());
        usrEdit->setSizePolicy(sizePolicy);
        usrEdit->setMaximumSize(QSize(16777215, 16777215));
        usrEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(usrEdit);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(PwdPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        pwdEdit = new EditCtrl(PwdPage);
        pwdEdit->setObjectName(QString::fromUtf8("pwdEdit"));
        sizePolicy.setHeightForWidth(pwdEdit->sizePolicy().hasHeightForWidth());
        pwdEdit->setSizePolicy(sizePolicy);
        pwdEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(pwdEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(PwdPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_5);

        loginBtn = new QPushButton(PwdPage);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        sizePolicy.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(loginBtn);

        label = new QLabel(PwdPage);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 5);

        retranslateUi(PwdPage);

        QMetaObject::connectSlotsByName(PwdPage);
    } // setupUi

    void retranslateUi(QWidget *PwdPage)
    {
        PwdPage->setWindowTitle(QApplication::translate("PwdPage", "Form", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_6->setText(QString());
        label_3->setText(QApplication::translate("PwdPage", "USR:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PwdPage", "PWD:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        loginBtn->setText(QApplication::translate("PwdPage", "Login", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PwdPage: public Ui_PwdPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWDPAGE_H
