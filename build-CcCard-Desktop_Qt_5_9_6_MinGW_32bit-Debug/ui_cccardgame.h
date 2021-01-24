/********************************************************************************
** Form generated from reading UI file 'cccardgame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCCARDGAME_H
#define UI_CCCARDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CcCardGame
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *CcCardGame)
    {
        if (CcCardGame->objectName().isEmpty())
            CcCardGame->setObjectName(QStringLiteral("CcCardGame"));
        CcCardGame->resize(1093, 724);
        centralWidget = new QWidget(CcCardGame);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 90, 930, 630));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 210, 118, 23));
        progressBar->setValue(24);
        CcCardGame->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CcCardGame);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CcCardGame->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(CcCardGame);

        QMetaObject::connectSlotsByName(CcCardGame);
    } // setupUi

    void retranslateUi(QMainWindow *CcCardGame)
    {
        CcCardGame->setWindowTitle(QApplication::translate("CcCardGame", "CcCardGame", Q_NULLPTR));
        label->setText(QApplication::translate("CcCardGame", "\346\270\270\346\210\217\345\220\215", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CcCardGame", "\345\215\225\344\272\272\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CcCardGame", "\345\244\232\344\272\272\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CcCardGame", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CcCardGame: public Ui_CcCardGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCCARDGAME_H
