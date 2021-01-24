/********************************************************************************
** Form generated from reading UI file 'finishedturnbtn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISHEDTURNBTN_H
#define UI_FINISHEDTURNBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinishedTurnBtn
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *FinishedTurnBtn)
    {
        if (FinishedTurnBtn->objectName().isEmpty())
            FinishedTurnBtn->setObjectName(QStringLiteral("FinishedTurnBtn"));
        FinishedTurnBtn->resize(116, 28);
        horizontalLayout = new QHBoxLayout(FinishedTurnBtn);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(FinishedTurnBtn);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);


        retranslateUi(FinishedTurnBtn);

        QMetaObject::connectSlotsByName(FinishedTurnBtn);
    } // setupUi

    void retranslateUi(QWidget *FinishedTurnBtn)
    {
        FinishedTurnBtn->setWindowTitle(QApplication::translate("FinishedTurnBtn", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FinishedTurnBtn", "\347\273\223\346\235\237\345\233\236\345\220\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FinishedTurnBtn: public Ui_FinishedTurnBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISHEDTURNBTN_H
