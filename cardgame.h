#ifndef CARDGAME_H
#define CARDGAME_H

#include <QMainWindow>

namespace Ui {
class CardGame;
}

class CardGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardGame(QWidget *parent = 0);
    ~CardGame();

private:
    Ui::CardGame *ui;
};

#endif // CARDGAME_H
