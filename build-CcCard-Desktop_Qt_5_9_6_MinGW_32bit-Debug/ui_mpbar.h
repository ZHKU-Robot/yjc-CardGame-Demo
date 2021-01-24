/********************************************************************************
** Form generated from reading UI file 'mpbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MPBAR_H
#define UI_MPBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MpBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *MpBar)
    {
        if (MpBar->objectName().isEmpty())
            MpBar->setObjectName(QStringLiteral("MpBar"));
        MpBar->resize(139, 53);
        horizontalLayout = new QHBoxLayout(MpBar);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 5, 10, 5);
        label = new QLabel(MpBar);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("border-image: url(:/fightUiImg/006oOWahly1fu28jkjxwbj306v07r0sw.jpg);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(MpBar);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(41, 191, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);


        retranslateUi(MpBar);

        QMetaObject::connectSlotsByName(MpBar);
    } // setupUi

    void retranslateUi(QWidget *MpBar)
    {
        MpBar->setWindowTitle(QApplication::translate("MpBar", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("MpBar", "3/3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MpBar: public Ui_MpBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPBAR_H
