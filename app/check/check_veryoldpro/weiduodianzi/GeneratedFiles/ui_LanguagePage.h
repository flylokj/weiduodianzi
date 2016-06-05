/********************************************************************************
** Form generated from reading UI file 'LanguagePage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGEPAGE_H
#define UI_LANGUAGEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguagePageClass
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *globalBtn;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ChineseBtn;
    QPushButton *EnglishBtn;

    void setupUi(QWidget *LanguagePageClass)
    {
        if (LanguagePageClass->objectName().isEmpty())
            LanguagePageClass->setObjectName(QString::fromUtf8("LanguagePageClass"));
        LanguagePageClass->resize(320, 195);
        horizontalLayout = new QHBoxLayout(LanguagePageClass);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        globalBtn = new QPushButton(LanguagePageClass);
        globalBtn->setObjectName(QString::fromUtf8("globalBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(globalBtn->sizePolicy().hasHeightForWidth());
        globalBtn->setSizePolicy(sizePolicy);
        globalBtn->setMaximumSize(QSize(150, 150));
        globalBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/global.png);"));

        verticalLayout->addWidget(globalBtn);

        verticalLayout->setStretch(0, 8);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ChineseBtn = new QPushButton(LanguagePageClass);
        ChineseBtn->setObjectName(QString::fromUtf8("ChineseBtn"));
        sizePolicy.setHeightForWidth(ChineseBtn->sizePolicy().hasHeightForWidth());
        ChineseBtn->setSizePolicy(sizePolicy);
        ChineseBtn->setMaximumSize(QSize(120, 80));
        ChineseBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/chinese.png);"));

        verticalLayout_2->addWidget(ChineseBtn);

        EnglishBtn = new QPushButton(LanguagePageClass);
        EnglishBtn->setObjectName(QString::fromUtf8("EnglishBtn"));
        sizePolicy.setHeightForWidth(EnglishBtn->sizePolicy().hasHeightForWidth());
        EnglishBtn->setSizePolicy(sizePolicy);
        EnglishBtn->setMaximumSize(QSize(120, 80));
        EnglishBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/weiduodianzi/ui/english.png);"));

        verticalLayout_2->addWidget(EnglishBtn);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(LanguagePageClass);

        QMetaObject::connectSlotsByName(LanguagePageClass);
    } // setupUi

    void retranslateUi(QWidget *LanguagePageClass)
    {
        LanguagePageClass->setWindowTitle(QApplication::translate("LanguagePageClass", "Form", 0, QApplication::UnicodeUTF8));
        globalBtn->setText(QString());
        ChineseBtn->setText(QString());
        EnglishBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LanguagePageClass: public Ui_LanguagePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGEPAGE_H
