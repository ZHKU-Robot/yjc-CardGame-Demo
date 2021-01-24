#include "characterstatusbar.h"
#include "ui_characterstatusbar.h"

CharacterStatusBar::CharacterStatusBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterStatusBar)
{
    ui->setupUi(this);
}

CharacterStatusBar::~CharacterStatusBar()
{
    delete ui;
}
