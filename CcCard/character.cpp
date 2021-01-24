#include "character.h"
#include "ui_characterstatusbar.h"

#include <qpropertyanimation.h>
Character::Character()
{

}

void Character::enemyInit()
{

}

void Character::figureInit()
{

}

void Character::characterInit()
{

    characterWidget=new QWidget();
    characterLabelLayout=new QVBoxLayout();
    characterLabel=new QLabel();
    characterHpBar=new QProgressBar();

    characterStatusBar=new CharacterStatusBar();

//    characterStatusBar->setAlignment(Qt::AlignVCenter);
//    characterStatusBar->setRange(0,maxMp);
//    characterStatusBar->setValue(curMp);
//    characterStatusBar->setFormat(QString("MP:"+QString::number(curMp)+"/"+QString::number(maxMp)));
//    characterStatusBar->setStyleSheet("QProgressBar{\
//                                                  border: none;\
//                               color: white;\
//                       border-radius: 10px;\
//background: rgb(0, 150, 222);\
//                       text-align: center;\
//                   font: 10pt \"微软雅黑\";\
//                   }\
//                   QProgressBar::chunk {\
//                       border-radius: 5px;\
//                   border: none;\
//                    background: rgb(0, 170, 255);\
//                   }");

    characterHpBar->setAlignment(Qt::AlignVCenter);
    characterHpBar->setRange(0,maxHp);
    characterHpBar->setValue(curHp);
    characterHpBar->setFormat(QString("HP:"+QString::number(curHp)+"/"+QString::number(maxHp)));
    characterHpBar->setStyleSheet("QProgressBar{\
                               border: none;\
            color: white;\
    border-radius: 10px;\
    text-align: center;\
font: 10pt \"微软雅黑\";\
}\
QProgressBar::chunk {\
    border-radius: 5px;\
border: none;\
background: rgb(255, 0, 0);\
}");

characterLabel->setScaledContents(true);
characterLabel->setFixedSize(FIGURE_WIDTH,FIGURE_HEIGHT);


characterWidget->setLayout(characterLabelLayout);

characterLabelLayout->addWidget(characterHpBar);
characterLabelLayout->addWidget(characterLabel);
characterLabelLayout->addWidget(characterStatusBar);
}

void Character::updateStatus()
{


}

void Character::attack(Character *&c)
{
    c->getAttacked(ad);
    this->characterStatusBar->ui->ad->setText(QString::number(ad));
}

void Character::defend(int d)
{
    de+=d;
    this->characterStatusBar->ui->de->setText(QString::number(de));
}



void Character::getAttacked(int damage)
{
    if(damage>de){
        curHp+=de-damage;
        setDe(0);
    }
    else{
        de-=damage;
    }
    updateDefend(de);
    this->characterHpBar->setValue(curHp);
    characterHpBar->setFormat(QString("HP:"+QString::number(curHp)+"/"+QString::number(maxHp)));


}

void Character::getConsumed(int consumed)
{
    curMp-=consumed;
//    this->characterStatusBar->ui->mp->setText(QString::number(curMp));
}

void Character::updateDefend(int de)
{
    setDe(de);
    this->characterStatusBar->ui->de->setText(QString::number(de));
}

void Character::updateAbilityPower(int ad)
{
    this->ad=ad;
        this->characterStatusBar->ui->ad->setText(QString::number(ad));
}




Character::Character(int hp, int mp, QString path)
{

    setHp(hp);
    setMp(mp);
    setCurHp(hp);
    setCurMp(mp);
    setAd(10);
    setDe(5);
   characterInit();

    QMovie *m=new QMovie(path);
    characterLabel->setMovie(m);
    m->start();
}

int Character::getAd() const
{
    return ad;
}

void Character::setAd(int value)
{
    ad = value;

}

int Character::getDe() const
{
    return de;
}

void Character::setDe(int value)
{
    de = value;

}



int Character::getCurHp() const
{
    return curHp;
}

void Character::setCurHp(int value)
{
    curHp = value;
}

int Character::getCurMp() const
{
    return curMp;
}

void Character::setCurMp(int value)
{
    curMp = value;
}

int Character::getMp() const
{
    return maxMp;
}

int Character::getHp() const
{
    return maxHp;
}

void Character::setMp(int value)
{
    maxMp = value;
}

void Character::setHp(int value)
{
    maxHp = value;
}
