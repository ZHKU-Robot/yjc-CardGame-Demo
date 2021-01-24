#include "cccardgame.h"
#include "ui_cccardgame.h"

CcCardGame::CcCardGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CcCardGame)
{
    ui->setupUi(this);
    initCards();
    createCards();
    createFigure();

    startFight();


}

CcCardGame::~CcCardGame()
{
    delete ui;
}

void CcCardGame::initCards()
{

    QJsonObject j;
    j["id"]=0;
    j["consume"]= 1;
    j["type"]=CardWidget::ATTACK;
    j["name"]="普通攻击";
    j["description"]="发动表情包最基本的力量，造成自己攻击力的伤害";
    j["imgPath"]=":/cardImg/6af89bc8gw1f8nlbw10kij205d05i743.jpg";
//    j["gif"]=":/figureImg/mogutou2.gif";
    CardWidget *card = new CardWidget(NULL,j);
    auto func=[&](Character *f,Character *e,CardWidget *card)->bool{
        e->getAttacked(f->ad);
        f->getConsumed(card->consume);
        return true;
    };
    card->setEffect(func);
    CardsVector.append(card);

    j=QJsonObject();
    j["id"]=1;
    j["consume"]= 1;
    j["type"]=CardWidget::DEFEND;
    j["name"]="没用的";
    j["description"]="发动表情包的防御姿态，增强5防御力";
    j["imgPath"]=":/cardImg/defend1.jpg";
    j["gif"]="";

    card = new CardWidget(NULL,j);
    auto func1=[&](Character *f,Character *e,CardWidget *card)->bool{
        f->updateDefend(5);
        f->getConsumed(card->consume);

        return true;
    };
    card->setEffect(func1);
    CardsVector.append(card);

}

void CcCardGame::addCard(QJsonObject info)
{

}
//所有 有的牌组
void CcCardGame::createCards()
{

}

void CcCardGame::createFigure()
{
    figure=new Character(figureInitHp,figureInitMp,":/figureImg/mogutou2.gif");
    figure->ad=figureAd;

}


void CcCardGame::startFight()
{

   fightUi=new FightInterface(figure,CardsVector);
   fightUi->show();
}
