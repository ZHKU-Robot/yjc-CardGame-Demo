#ifndef CHARACTER_H
#define CHARACTER_H

#include <QMovie>
#include <QProgressBar>
#include <qboxlayout.h>
#include <qlabel.h>
#include "global.h"
#include "characterstatusbar.h"

class Character
{
public:
    Character(int maxHp,int maxMp,QString path);
    int maxHp;
    int maxMp;
    int ad;
    int curHp;
    int curMp;
    int de;

    void setHp(int value);
    void setMp(int value);

    int getHp() const;
    int getMp() const;
    int getCurMp() const;
    void setCurMp(int value);
    int getCurHp() const;
    void setCurHp(int value);
    Character();

    QProgressBar *characterHpBar;
    QMovie *characterMovie ;
    QLabel *characterLabel;
    QWidget *characterWidget;
    QVBoxLayout *characterLabelLayout;
    CharacterStatusBar *characterStatusBar;


    void enemyInit();
    void figureInit();
    void characterInit();
     void updateStatus();

    void attack(Character *&c);
    void defend(int d);
    void getAttacked(int damage);
    void getConsumed(int consumed);
    void updateDefend(int de);
    void updateAbilityPower(int ad);




    int getDe() const;
    void setDe(int value);
    int getAd() const;
    void setAd(int value);
};

#endif // CHARACTER_H
