#include "mpbar.h"
#include "ui_mpbar.h"

MpBar::MpBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MpBar)
{
    ui->setupUi(this);
}

MpBar::~MpBar()
{
    delete ui;
}
