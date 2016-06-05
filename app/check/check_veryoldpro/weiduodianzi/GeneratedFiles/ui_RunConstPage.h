/********************************************************************************
** Form generated from reading UI file 'RunConstPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNCONSTPAGE_H
#define UI_RUNCONSTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunConstPageClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *lightIniBtn;
    QCheckBox *lightOnCheck;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *frenEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *motorIniBtn;
    QCheckBox *dirCheck;
    QCheckBox *freqCheck;
    QCheckBox *coilCheck;

    void setupUi(QWidget *RunConstPageClass)
    {
        if (RunConstPageClass->objectName().isEmpty())
            RunConstPageClass->setObjectName(QString::fromUtf8("RunConstPageClass"));
        RunConstPageClass->resize(320, 195);
        verticalLayout = new QVBoxLayout(RunConstPageClass);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 30, -1, 30);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lightIniBtn = new QPushButton(RunConstPageClass);
        lightIniBtn->setObjectName(QString::fromUtf8("lightIniBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lightIniBtn->sizePolicy().hasHeightForWidth());
        lightIniBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lightIniBtn);

        lightOnCheck = new QCheckBox(RunConstPageClass);
        lightOnCheck->setObjectName(QString::fromUtf8("lightOnCheck"));

        horizontalLayout->addWidget(lightOnCheck);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 20, -1);
        label = new QLabel(RunConstPageClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        frenEdit = new QLineEdit(RunConstPageClass);
        frenEdit->setObjectName(QString::fromUtf8("frenEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frenEdit->sizePolicy().hasHeightForWidth());
        frenEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(frenEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        motorIniBtn = new QPushButton(RunConstPageClass);
        motorIniBtn->setObjectName(QString::fromUtf8("motorIniBtn"));
        sizePolicy.setHeightForWidth(motorIniBtn->sizePolicy().hasHeightForWidth());
        motorIniBtn->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(motorIniBtn);

        dirCheck = new QCheckBox(RunConstPageClass);
        dirCheck->setObjectName(QString::fromUtf8("dirCheck"));

        horizontalLayout_3->addWidget(dirCheck);

        freqCheck = new QCheckBox(RunConstPageClass);
        freqCheck->setObjectName(QString::fromUtf8("freqCheck"));

        horizontalLayout_3->addWidget(freqCheck);

        coilCheck = new QCheckBox(RunConstPageClass);
        coilCheck->setObjectName(QString::fromUtf8("coilCheck"));

        horizontalLayout_3->addWidget(coilCheck);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(RunConstPageClass);

        QMetaObject::connectSlotsByName(RunConstPageClass);
    } // setupUi

    void retranslateUi(QWidget *RunConstPageClass)
    {
        RunConstPageClass->setWindowTitle(QApplication::translate("RunConstPageClass", "Form", 0, QApplication::UnicodeUTF8));
        lightIniBtn->setText(QApplication::translate("RunConstPageClass", "\347\201\257\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        lightOnCheck->setText(QApplication::translate("RunConstPageClass", "\345\274\200/\345\205\263", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RunConstPageClass", "\351\242\221\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        motorIniBtn->setText(QApplication::translate("RunConstPageClass", "\347\224\265\346\234\272\345\210\235\345\247\213\345\214\226", 0, QApplication::UnicodeUTF8));
        dirCheck->setText(QApplication::translate("RunConstPageClass", "\346\255\243", 0, QApplication::UnicodeUTF8));
        freqCheck->setText(QApplication::translate("RunConstPageClass", "\351\242\221\347\216\207", 0, QApplication::UnicodeUTF8));
        coilCheck->setText(QApplication::translate("RunConstPageClass", "\347\224\265\347\243\201\351\230\200\345\274\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RunConstPageClass: public Ui_RunConstPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNCONSTPAGE_H
