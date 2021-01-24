/********************************************************************************
** Form generated from reading UI file 'characterstatusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERSTATUSBAR_H
#define UI_CHARACTERSTATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterStatusBar
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *ad;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *de;

    void setupUi(QWidget *CharacterStatusBar)
    {
        if (CharacterStatusBar->objectName().isEmpty())
            CharacterStatusBar->setObjectName(QStringLiteral("CharacterStatusBar"));
        CharacterStatusBar->resize(305, 84);
        horizontalLayout_3 = new QHBoxLayout(CharacterStatusBar);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(CharacterStatusBar);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/fightUiImg/strength.svg);"));

        horizontalLayout_2->addWidget(label_3);

        ad = new QLabel(widget);
        ad->setObjectName(QStringLiteral("ad"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        ad->setFont(font);
        ad->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(ad);


        horizontalLayout_3->addWidget(widget);

        widget_2 = new QWidget(CharacterStatusBar);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/fightUiImg/\347\233\276\347\211\214.svg);"));

        horizontalLayout->addWidget(label_5);

        de = new QLabel(widget_2);
        de->setObjectName(QStringLiteral("de"));
        de->setFont(font);
        de->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(de);


        horizontalLayout_3->addWidget(widget_2);


        retranslateUi(CharacterStatusBar);

        QMetaObject::connectSlotsByName(CharacterStatusBar);
    } // setupUi

    void retranslateUi(QWidget *CharacterStatusBar)
    {
        CharacterStatusBar->setWindowTitle(QApplication::translate("CharacterStatusBar", "Form", Q_NULLPTR));
        label_3->setText(QString());
        ad->setText(QApplication::translate("CharacterStatusBar", "5", Q_NULLPTR));
        label_5->setText(QString());
        de->setText(QApplication::translate("CharacterStatusBar", "5", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CharacterStatusBar: public Ui_CharacterStatusBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERSTATUSBAR_H
