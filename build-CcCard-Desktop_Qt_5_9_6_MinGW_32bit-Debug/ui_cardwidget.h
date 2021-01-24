/********************************************************************************
** Form generated from reading UI file 'cardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWIDGET_H
#define UI_CARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *consume;
    QLabel *img;
    QLabel *type;
    QLabel *name;
    QLabel *description;

    void setupUi(QWidget *CardWidget)
    {
        if (CardWidget->objectName().isEmpty())
            CardWidget->setObjectName(QStringLiteral("CardWidget"));
        CardWidget->resize(221, 340);
        CardWidget->setFocusPolicy(Qt::NoFocus);
        CardWidget->setStyleSheet(QLatin1String("QWidget#CardWidget{padding:0px;border:0px;background: transparent;}\n"
""));
        verticalLayout_2 = new QVBoxLayout(CardWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CardWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMouseTracking(false);
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{border-image: url(:/cardImg/\346\255\246\344\276\240\345\215\241\347\211\214\347\275\221\346\270\270ui\347\264\240\346\235\220-\346\225\231\344\270\273\346\227\245\350\256\260ui\347\264\240\346\235\220-UI \345\234\272\346\231\257 raid_\347\210\261\347\273\231\347\275\221_aigei_com.png);}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        consume = new QLabel(widget);
        consume->setObjectName(QStringLiteral("consume"));
        consume->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(consume);

        img = new QLabel(widget);
        img->setObjectName(QStringLiteral("img"));
        img->setStyleSheet(QStringLiteral("border-image: url(:/cardImg/6af89bc8gw1f8od7wwm32j206o04qglj.jpg);"));

        verticalLayout->addWidget(img);

        type = new QLabel(widget);
        type->setObjectName(QStringLiteral("type"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        type->setFont(font);
        type->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(type);

        name = new QLabel(widget);
        name->setObjectName(QStringLiteral("name"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        name->setFont(font1);
        name->setTextFormat(Qt::AutoText);
        name->setScaledContents(true);
        name->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        name->setWordWrap(true);

        verticalLayout->addWidget(name);

        description = new QLabel(widget);
        description->setObjectName(QStringLiteral("description"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        description->setFont(font2);
        description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        description->setWordWrap(true);

        verticalLayout->addWidget(description);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 6);

        verticalLayout_2->addWidget(widget);


        retranslateUi(CardWidget);

        QMetaObject::connectSlotsByName(CardWidget);
    } // setupUi

    void retranslateUi(QWidget *CardWidget)
    {
        CardWidget->setWindowTitle(QApplication::translate("CardWidget", "Form", Q_NULLPTR));
        consume->setText(QApplication::translate("CardWidget", "\350\203\275\351\207\217\346\266\210\350\200\227", Q_NULLPTR));
        img->setText(QString());
        type->setText(QApplication::translate("CardWidget", "\346\212\200\350\203\275\347\261\273\345\236\213", Q_NULLPTR));
        name->setText(QApplication::translate("CardWidget", "\346\212\200\350\203\275\345\220\215\345\255\227", Q_NULLPTR));
        description->setText(QApplication::translate("CardWidget", "\346\212\200\350\203\275\350\257\264\346\230\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardWidget: public Ui_CardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWIDGET_H
