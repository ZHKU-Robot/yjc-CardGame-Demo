#include "cardgame.h"
#include "ui_cardgame.h"

CardGame::CardGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardGame)
{
    ui->setupUi(this);
}

CardGame::~CardGame()
{
    delete ui;
}
