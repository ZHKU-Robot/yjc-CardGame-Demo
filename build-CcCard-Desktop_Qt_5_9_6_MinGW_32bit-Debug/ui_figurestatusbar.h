/********************************************************************************
** Form generated from reading UI file 'figurestatusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGURESTATUSBAR_H
#define UI_FIGURESTATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FigureStatusBar
{
public:
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;

    void setupUi(QWidget *FigureStatusBar)
    {
        if (FigureStatusBar->objectName().isEmpty())
            FigureStatusBar->setObjectName(QStringLiteral("FigureStatusBar"));
        FigureStatusBar->resize(360, 38);
        horizontalLayout = new QHBoxLayout(FigureStatusBar);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        progressBar = new QProgressBar(FigureStatusBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"            border: none;\n"
"            color: white;\n"
"    border-radius: 10px;\n"
"    text-align: center;\n"
"background: rgb(85, 85, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QProgressBar::chunk {\n"
"    border-radius: 5px;\n"
"border: none;\n"
"background: rgb(255, 255, 255)\n"
"}"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(FigureStatusBar);

        QMetaObject::connectSlotsByName(FigureStatusBar);
    } // setupUi

    void retranslateUi(QWidget *FigureStatusBar)
    {
        FigureStatusBar->setWindowTitle(QApplication::translate("FigureStatusBar", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FigureStatusBar: public Ui_FigureStatusBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGURESTATUSBAR_H
