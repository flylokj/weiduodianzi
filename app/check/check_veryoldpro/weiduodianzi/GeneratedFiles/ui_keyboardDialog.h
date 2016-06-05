/********************************************************************************
** Form generated from reading UI file 'keyboardDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDDIALOG_H
#define UI_KEYBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *_7Button;
    QPushButton *_8Button;
    QPushButton *_9Button;
    QPushButton *_4Button;
    QPushButton *_5Button;
    QPushButton *_6Button;
    QPushButton *_1Button;
    QPushButton *_2Button;
    QPushButton *_3Button;
    QPushButton *_0Button;
    QPushButton *ceButton;
    QPushButton *pointButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *positiveButton;
    QPushButton *negativeButton;
    QPushButton *backButton;
    QPushButton *cancelButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *KeyBoardDialog)
    {
        if (KeyBoardDialog->objectName().isEmpty())
            KeyBoardDialog->setObjectName(QString::fromUtf8("KeyBoardDialog"));
        KeyBoardDialog->setEnabled(true);
        KeyBoardDialog->resize(320, 240);
        gridLayout_2 = new QGridLayout(KeyBoardDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(KeyBoardDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _7Button = new QPushButton(KeyBoardDialog);
        _7Button->setObjectName(QString::fromUtf8("_7Button"));
        sizePolicy.setHeightForWidth(_7Button->sizePolicy().hasHeightForWidth());
        _7Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_7Button, 0, 0, 1, 1);

        _8Button = new QPushButton(KeyBoardDialog);
        _8Button->setObjectName(QString::fromUtf8("_8Button"));
        sizePolicy.setHeightForWidth(_8Button->sizePolicy().hasHeightForWidth());
        _8Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_8Button, 0, 1, 1, 1);

        _9Button = new QPushButton(KeyBoardDialog);
        _9Button->setObjectName(QString::fromUtf8("_9Button"));
        sizePolicy.setHeightForWidth(_9Button->sizePolicy().hasHeightForWidth());
        _9Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_9Button, 0, 2, 1, 1);

        _4Button = new QPushButton(KeyBoardDialog);
        _4Button->setObjectName(QString::fromUtf8("_4Button"));
        sizePolicy.setHeightForWidth(_4Button->sizePolicy().hasHeightForWidth());
        _4Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_4Button, 1, 0, 1, 1);

        _5Button = new QPushButton(KeyBoardDialog);
        _5Button->setObjectName(QString::fromUtf8("_5Button"));
        sizePolicy.setHeightForWidth(_5Button->sizePolicy().hasHeightForWidth());
        _5Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_5Button, 1, 1, 1, 1);

        _6Button = new QPushButton(KeyBoardDialog);
        _6Button->setObjectName(QString::fromUtf8("_6Button"));
        sizePolicy.setHeightForWidth(_6Button->sizePolicy().hasHeightForWidth());
        _6Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_6Button, 1, 2, 1, 1);

        _1Button = new QPushButton(KeyBoardDialog);
        _1Button->setObjectName(QString::fromUtf8("_1Button"));
        sizePolicy.setHeightForWidth(_1Button->sizePolicy().hasHeightForWidth());
        _1Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_1Button, 2, 0, 1, 1);

        _2Button = new QPushButton(KeyBoardDialog);
        _2Button->setObjectName(QString::fromUtf8("_2Button"));
        sizePolicy.setHeightForWidth(_2Button->sizePolicy().hasHeightForWidth());
        _2Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_2Button, 2, 1, 1, 1);

        _3Button = new QPushButton(KeyBoardDialog);
        _3Button->setObjectName(QString::fromUtf8("_3Button"));
        sizePolicy.setHeightForWidth(_3Button->sizePolicy().hasHeightForWidth());
        _3Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_3Button, 2, 2, 1, 1);

        _0Button = new QPushButton(KeyBoardDialog);
        _0Button->setObjectName(QString::fromUtf8("_0Button"));
        sizePolicy.setHeightForWidth(_0Button->sizePolicy().hasHeightForWidth());
        _0Button->setSizePolicy(sizePolicy);

        gridLayout->addWidget(_0Button, 3, 0, 1, 1);

        ceButton = new QPushButton(KeyBoardDialog);
        ceButton->setObjectName(QString::fromUtf8("ceButton"));
        sizePolicy.setHeightForWidth(ceButton->sizePolicy().hasHeightForWidth());
        ceButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ceButton, 3, 1, 1, 1);

        pointButton = new QPushButton(KeyBoardDialog);
        pointButton->setObjectName(QString::fromUtf8("pointButton"));
        sizePolicy.setHeightForWidth(pointButton->sizePolicy().hasHeightForWidth());
        pointButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pointButton, 3, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        positiveButton = new QPushButton(KeyBoardDialog);
        positiveButton->setObjectName(QString::fromUtf8("positiveButton"));
        sizePolicy.setHeightForWidth(positiveButton->sizePolicy().hasHeightForWidth());
        positiveButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(positiveButton);

        negativeButton = new QPushButton(KeyBoardDialog);
        negativeButton->setObjectName(QString::fromUtf8("negativeButton"));
        sizePolicy.setHeightForWidth(negativeButton->sizePolicy().hasHeightForWidth());
        negativeButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(negativeButton);


        verticalLayout->addLayout(horizontalLayout);

        backButton = new QPushButton(KeyBoardDialog);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(backButton);

        cancelButton = new QPushButton(KeyBoardDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(cancelButton);

        confirmButton = new QPushButton(KeyBoardDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        sizePolicy.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(confirmButton);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 6);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(KeyBoardDialog);

        QMetaObject::connectSlotsByName(KeyBoardDialog);
    } // setupUi

    void retranslateUi(QDialog *KeyBoardDialog)
    {
        KeyBoardDialog->setWindowTitle(QApplication::translate("KeyBoardDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        _7Button->setText(QApplication::translate("KeyBoardDialog", "7", 0, QApplication::UnicodeUTF8));
        _8Button->setText(QApplication::translate("KeyBoardDialog", "8", 0, QApplication::UnicodeUTF8));
        _9Button->setText(QApplication::translate("KeyBoardDialog", "9", 0, QApplication::UnicodeUTF8));
        _4Button->setText(QApplication::translate("KeyBoardDialog", "4", 0, QApplication::UnicodeUTF8));
        _5Button->setText(QApplication::translate("KeyBoardDialog", "5", 0, QApplication::UnicodeUTF8));
        _6Button->setText(QApplication::translate("KeyBoardDialog", "6", 0, QApplication::UnicodeUTF8));
        _1Button->setText(QApplication::translate("KeyBoardDialog", "1", 0, QApplication::UnicodeUTF8));
        _2Button->setText(QApplication::translate("KeyBoardDialog", "2", 0, QApplication::UnicodeUTF8));
        _3Button->setText(QApplication::translate("KeyBoardDialog", "3", 0, QApplication::UnicodeUTF8));
        _0Button->setText(QApplication::translate("KeyBoardDialog", "0", 0, QApplication::UnicodeUTF8));
        ceButton->setText(QApplication::translate("KeyBoardDialog", "CE", 0, QApplication::UnicodeUTF8));
        pointButton->setText(QApplication::translate("KeyBoardDialog", ".", 0, QApplication::UnicodeUTF8));
        positiveButton->setText(QApplication::translate("KeyBoardDialog", "+", 0, QApplication::UnicodeUTF8));
        negativeButton->setText(QApplication::translate("KeyBoardDialog", "-", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("KeyBoardDialog", "BS", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("KeyBoardDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        confirmButton->setText(QApplication::translate("KeyBoardDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KeyBoardDialog: public Ui_KeyBoardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDDIALOG_H
