/********************************************************************************
** Form generated from reading UI file 'sensitivePage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSITIVEPAGE_H
#define UI_SENSITIVEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensitivePageClass
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SensitivePageClass)
    {
        if (SensitivePageClass->objectName().isEmpty())
            SensitivePageClass->setObjectName(QString::fromUtf8("SensitivePageClass"));
        SensitivePageClass->resize(320, 195);
        layoutWidget = new QWidget(SensitivePageClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 301, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 0, 20, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 6);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(SensitivePageClass);

        QMetaObject::connectSlotsByName(SensitivePageClass);
    } // setupUi

    void retranslateUi(QWidget *SensitivePageClass)
    {
        SensitivePageClass->setWindowTitle(QApplication::translate("SensitivePageClass", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SensitivePageClass", "Sensitivity", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SensitivePageClass", "nm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SensitivePageClass", "Integration", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SensitivePageClass", "AU", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SensitivePageClass: public Ui_SensitivePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSITIVEPAGE_H
