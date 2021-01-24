#include "finishedturnbtn.h"
#include "ui_finishedturnbtn.h"

FinishedTurnBtn::FinishedTurnBtn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinishedTurnBtn)
{
    ui->setupUi(this);
}

FinishedTurnBtn::~FinishedTurnBtn()
{
    delete ui;
}
