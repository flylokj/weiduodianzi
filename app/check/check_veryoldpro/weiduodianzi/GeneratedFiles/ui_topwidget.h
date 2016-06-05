/********************************************************************************
** Form generated from reading UI file 'topwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPWIDGET_H
#define UI_TOPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *TopWidget)
    {
        if (TopWidget->objectName().isEmpty())
            TopWidget->setObjectName(QString::fromUtf8("TopWidget"));
        TopWidget->resize(533, 69);
        gridLayout = new QGridLayout(TopWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TopWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(TopWidget);

        QMetaObject::connectSlotsByName(TopWidget);
    } // setupUi

    void retranslateUi(QWidget *TopWidget)
    {
        TopWidget->setWindowTitle(QApplication::translate("TopWidget", "TopWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TopWidget: public Ui_TopWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPWIDGET_H
