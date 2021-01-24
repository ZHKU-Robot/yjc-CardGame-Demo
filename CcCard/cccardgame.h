#ifndef CCCARDGAME_H
#define CCCARDGAME_H

#include <QMainWindow>
#include "fightinterface.h"
#include "ui_fightinterface.h"
#include "cardgraphicsproxywidget.h"
namespace Ui {
class CcCardGame;
}

class CcCardGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CcCardGame(QWidget *parent = 0);
    ~CcCardGame();

    int figureInitHp=100;
    int figureInitMp=10;
    int figureAd=10;

    int level=1;

    int totalCardsCount=10;



    Character *figure;
    //牌库代理
    QVector<CardGraphicsProxyWidget*> curTotalProxyCardsVector;
    //现在的手牌代理
    QVector<CardGraphicsProxyWidget*> curHaveProxyCardsVector;
    //
    QVector<QJsonObject> cardInfoJson;
    //牌库
    QVector<CardWidget*> CardsVector;
    void initCards();
    void addCard(QJsonObject info);
    void createCards();
    void createFigure();
    FightInterface *fightUi;
    void startFight();
private:
    Ui::CcCardGame *ui;

};

#endif // CCCARDGAME_H
