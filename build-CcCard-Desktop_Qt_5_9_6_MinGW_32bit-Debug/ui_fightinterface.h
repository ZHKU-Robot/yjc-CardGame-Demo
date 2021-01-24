/********************************************************************************
** Form generated from reading UI file 'fightinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHTINTERFACE_H
#define UI_FIGHTINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FightInterface
{
public:
    QVBoxLayout *verticalLayout_4;

    void setupUi(QWidget *FightInterface)
    {
        if (FightInterface->objectName().isEmpty())
            FightInterface->setObjectName(QStringLiteral("FightInterface"));
        FightInterface->resize(1102, 721);
        verticalLayout_4 = new QVBoxLayout(FightInterface);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);

        retranslateUi(FightInterface);

        QMetaObject::connectSlotsByName(FightInterface);
    } // setupUi

    void retranslateUi(QWidget *FightInterface)
    {
        FightInterface->setWindowTitle(QApplication::translate("FightInterface", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FightInterface: public Ui_FightInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHTINTERFACE_H
