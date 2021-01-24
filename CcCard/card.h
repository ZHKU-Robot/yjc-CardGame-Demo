#ifndef CARD_H
#define CARD_H

#include <QWidget>

namespace Ui {
class Card;
}

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = 0);
    ~Card();

private:
    Ui::Card *ui;
};

#endif // CARD_H
