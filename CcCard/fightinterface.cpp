#include "fightinterface.h"
#include "ui_fightinterface.h"

#include "ui_mpbar.h"
#include "ui_finishedturnbtn.h"

FightInterface::FightInterface(Character *figure,QVector<CardWidget*> cardsV, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);
    ui->verticalLayout_4->addWidget(view);
    view->setRenderHints(view->renderHints()
                                          | QPainter::Antialiasing
                                          | QPainter::SmoothPixmapTransform);


    scene=new QGraphicsScene(this);

    view->setScene(scene);
    view->setSceneRect(QRectF(-width()/2,-height()/2,width(),height()));
    screenSize=size();

    setCardsV(cardsV);
    setFigure(figure);
    setEnemy(enemy);
    formInit();

    createBoth();

    QTimer *t =new QTimer();
    connect(t,&QTimer::timeout,this,[=](){
        createCards();
    });
    t->setSingleShot(true);
    t->start(1000);


}



FightInterface::~FightInterface()
{
    delete ui;
}

void FightInterface::createCards()
{

    //遍历卡组,然后根据算法摆角度

    for(int i=-curCardsNum/2;i<(curCardsNum%2==0?curCardsNum/2:curCardsNum/2+1);i++)
    {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int n = qrand() % cardsV.size();


        CardWidget *cw =new CardWidget(cardsV.at(n));
        CardGraphicsProxyWidget * w=new CardGraphicsProxyWidget();
        scene->addItem(w);
        cardsProxyV.append(w);

        w->setWidget(cw);
        w->w=cw;


        QPropertyAnimation *ani =new QPropertyAnimation(cw,"pos");

        ani->setEasingCurve(QEasingCurve::OutInCubic);

        QPoint destination=getCardPos(i);
        QPoint remote=QPoint(-width()/2,-height()/2);

        w->cardId=i+curCardsNum/2;
        w->cardRotationFactor=i;
        w->widgetPos=destination;
        w->setZValue(1);
        w->initWindowsFrame();

        w->cardSize=w->widget()->size();
        w->setRotation(i*ROTATION);
        w->setPos(remote);

        connect(w,SIGNAL(widenCards(CardGraphicsProxyWidget*)),this,SLOT(widenCards(CardGraphicsProxyWidget*)));
        connect(w,SIGNAL(narrowCards(CardGraphicsProxyWidget*)),this,SLOT(narrowCards(CardGraphicsProxyWidget*)));
        connect(w,SIGNAL(startAE(QString,QRectF)),this,SLOT(startAE(QString,QRectF)));
        connect(w,SIGNAL(updatePos(QRectF)),this,SLOT(updateAE(QRectF)));
        connect(w,SIGNAL(stopAE()),this,SLOT(stopAE()));
        connect(w,SIGNAL(deleteMyself(QObject*)),this,SLOT(updateCards(QObject*)));
//        qDebug()<<remote<<destination;
        ani->setStartValue(remote);
        ani->setEndValue(destination);
        ani->setDuration(300);
        ani->start(QAbstractAnimation::DeleteWhenStopped);

        if(i==(curCardsNum%2==0?curCardsNum/2-1:curCardsNum/2)){
            connect(ani,&QPropertyAnimation::finished,this,[=](){
                w->cardsReady=1;
                finishTurnBtn->ui->pushButton->setEnabled(1);
            });

        }
        else{
            connect(ani,&QPropertyAnimation::finished,this,[=](){
                w->cardsReady=1;
            });
        }

    }




//    aniGroup->start();

}
//传入的是 figure和enemy
void FightInterface::createBoth()
{
    QGraphicsProxyWidget *l;
    enemy =new Character(100,10,":/enemyImg/mogutou1.gif");

    l=scene->addWidget(enemy->characterWidget);
    l->setPos(ENEMY_POS);
    l->setGeometry(QRectF(l->x(),l->y(),ENEMY_WIDTH,ENEMY_HEIGHT));
    l->setZValue(0);



    l=scene->addWidget(figure->characterWidget);

    l->setPos(FIGURE_POS);
    l->setGeometry(QRectF(l->x(),l->y(),FIGURE_WIDTH,FIGURE_HEIGHT));

    l->setZValue(0);

}



void FightInterface::formInit()
{
    FIGURE_POS=QPointF(-width()/2+FIGURE_X_INTERVAL,-height()/2+FIGURE_Y_INTERVAL);
    ENEMY_POS=QPointF(width()/2-ENEMY_WIDTH-ENEMY_X_INTERVAL,-height()/2+ENEMY_Y_INTERVAL);

    //回合结束按钮
    finishTurnBtn=new FinishedTurnBtn();
    finishTurnBtn->ui->pushButton->setEnabled(0);
    QGraphicsProxyWidget *btn= scene->addWidget(finishTurnBtn);
    btn->setZValue(1);
    btn->setPos(ENEMY_POS.x()+110,ENEMY_POS.y()+450);
    connect(finishTurnBtn->ui->pushButton,&QPushButton::clicked,this,&FightInterface::nextTurn);
    //蓝条
    mpbar=new MpBar();
    mpbar->setAttribute(Qt::WA_TranslucentBackground);
    mpbar->ui->label_2->setText(QString::number(figure->curMp)+"/"+QString::number(figure->maxMp));
    QGraphicsProxyWidget *mpProxy= scene->addWidget(mpbar);
    mpProxy->setPos(FIGURE_POS.x()-60,FIGURE_POS.y()+440);
    mpProxy->setZValue(1);

}

void FightInterface::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

QPoint FightInterface::getCardPos(int i)
{
    return QPoint(i*CARD_X_INTERVAL-CARD_WIDTH/3,(i>0?i*(curCardsNum/3):-i*(curCardsNum/3))*CARD_Y_INTERVAL-CARD_0_OFFSET);
}

void FightInterface::setCardsV( QVector<CardWidget*> value)
{
    cardsV = value;
}

void FightInterface::enemyTurn()
{

    QPropertyAnimation *aniAttackForward=new QPropertyAnimation(enemy->characterWidget,"pos");
    QPropertyAnimation *aniAttackBack=new QPropertyAnimation(enemy->characterWidget,"pos");
    QSequentialAnimationGroup *aniGroup=new QSequentialAnimationGroup;
    QPropertyAnimation *aniShake = new QPropertyAnimation(this, "pos");

    QPoint figurePos=figure->characterWidget->pos();
    QPoint enemyPos=enemy->characterWidget->pos();
    AEWidget *ae=new AEWidget(EFFECT_PATH+"is_injured1",figure->characterWidget->size());
    figurePos.setX(figurePos.x()+figure->characterWidget->width());

    qsrand(time(NULL));
    int n = qrand() % 3;

    //查看牌的属性，来做相应的动作
    switch (n) {
    case CardWidget::ATTACK:
        //发动攻击嗷
        aniAttackForward->setStartValue( enemyPos);
        aniAttackForward->setEndValue(figurePos);
        aniAttackForward->setEasingCurve(QEasingCurve::InOutCirc);
        aniAttackForward->setDuration(500);
        connect(aniAttackForward,&QPropertyAnimation::finished,this,[=](){
            int injured=figure->de-enemy->ad;
            scene->addWidget(ae)->setPos(QPointF(figurePos.x()-figure->characterWidget->width(),figurePos.y()));
            ae->startAE();
            injuredFontAni(injured,figure);
            figure->getAttacked(injured);


        });

        aniAttackBack->setStartValue(figurePos);
        aniAttackBack->setEndValue(enemyPos);
        aniAttackBack->setEasingCurve(QEasingCurve::OutCirc);
        aniAttackBack->setDuration(500);
        connect(aniAttackBack,&QPropertyAnimation::finished,this,[=](){

        });


        aniGroup->addAnimation(aniAttackForward);
        aniGroup->addAnimation(aniShake);
        aniGroup->addAnimation(aniAttackBack);

        aniGroup->start(QAbstractAnimation::DeleteWhenStopped);

        //窗口抖动

        aniShake->setDuration(500);
        aniShake->setLoopCount(2);
        aniShake->setEasingCurve(QEasingCurve::InOutSine);

        aniShake->setStartValue(pos());
        aniShake->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
        aniShake->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.95, QPoint(geometry().x()+3, geometry().y()+3));
        aniShake->setEndValue(pos());

        connect(aniShake,&QPropertyAnimation::finished,this,[=](){

        ae->deleteLater();


        });

        break;
    case CardWidget::SKILL:



        break;
    case CardWidget::DEFEND:
        enemy->defend(2);

        break;
    default:
        break;
    }

}

Character *FightInterface::getEnemy() const
{
    return enemy;
}

void FightInterface::setEnemy(Character *value)
{
    enemy = value;
}

Character *FightInterface::getFigure() const
{
    return figure;
}

void FightInterface::setFigure(Character *value)
{
    figure = value;
}

void FightInterface::updateCards(QObject* obj)
{
    //这里埋个坑,即在代理控件里 动用了delete 而不是在scene 里 removeitem
    //使用QObject的效果并且更新手牌
    //

    usingCards(obj);

    CardGraphicsProxyWidget *d=static_cast<CardGraphicsProxyWidget*>(obj);
    cardsProxyV.remove(d->cardId);
    curCardsNum--;
    int i=-curCardsNum/2;
    qDebug()<<d->cardId;
    foreach (CardGraphicsProxyWidget *card, cardsProxyV) {

        card->cardRotationFactor=i;
        card->cardId=i+curCardsNum/2;
        card->setRotation(i*ROTATION);
        card->setPos(getCardPos(i));
        card->widgetPos=card->pos();
        i++;

    }

}

void FightInterface::usingCards(QObject* obj)
{
    CardGraphicsProxyWidget *d=static_cast<CardGraphicsProxyWidget*>(obj);
    QPropertyAnimation *aniAttackForward=new QPropertyAnimation(figure->characterWidget,"pos");
    QPropertyAnimation *aniAttackBack=new QPropertyAnimation(figure->characterWidget,"pos");
    QSequentialAnimationGroup *aniGroup=new QSequentialAnimationGroup;
    QPropertyAnimation *aniShake = new QPropertyAnimation(this, "pos");

    QPoint figurePos=figure->characterWidget->pos();
    QPoint enemyPos=enemy->characterWidget->pos();
    AEWidget *ae=new AEWidget(EFFECT_PATH+"is_injured1",enemy->characterWidget->size());
    enemyPos.setX(enemyPos.x()-enemy->characterWidget->width());



    //查看牌的属性，来做相应的动作
    switch (d->cardType) {
    case CardWidget::ATTACK:
        //发动攻击嗷

        aniAttackForward->setStartValue(figurePos);
        aniAttackForward->setEndValue(enemyPos);
        aniAttackForward->setEasingCurve(QEasingCurve::OutCirc);
        aniAttackForward->setDuration(500);
        connect(aniAttackForward,&QPropertyAnimation::finished,this,[=](){
            scene->addWidget(ae)->setPos(QPointF(enemyPos.x()+enemy->characterWidget->width(),enemyPos.y()));
            ae->startAE();
            d->w->effect(figure,enemy,d->w);
            injuredFontAni(enemy->de-figure->ad,enemy);
            d->deleteLater();

            //造成伤害
        });

        aniAttackBack->setStartValue(enemyPos);
        aniAttackBack->setEndValue(figurePos);
        aniAttackBack->setEasingCurve(QEasingCurve::OutCirc);
        aniAttackBack->setDuration(500);


        aniGroup->addAnimation(aniAttackForward);
        aniGroup->addAnimation(aniShake);
        aniGroup->addAnimation(aniAttackBack);
        aniGroup->start(QAbstractAnimation::DeleteWhenStopped);

        //窗口抖动

        aniShake->setDuration(500);
        aniShake->setLoopCount(2);
        aniShake->setEasingCurve(QEasingCurve::InOutSine);

        aniShake->setStartValue(pos());
        aniShake->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
        aniShake->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
        aniShake->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
        aniShake->setKeyValueAt(0.95, QPoint(geometry().x()+3, geometry().y()+3));
        aniShake->setEndValue(pos());

        connect(aniShake,&QPropertyAnimation::finished,this,[=](){

        ae->deleteLater();


        });

        break;
    case CardWidget::SKILL:

        break;
    default:
        break;
    }
    mpbar->ui->label_2->setText(QString::number(figure->curMp)+"/"+QString::number(figure->maxMp));
}

void FightInterface::widenCards(CardGraphicsProxyWidget *obj)
{

    obj->setZValue(1);
    for(int i=0;i<obj->cardId;i++){
       CardGraphicsProxyWidget *o=cardsProxyV.at(i);
       o->setPos(QPointF(o->widgetPos.x()-CARD_WIDTH/2,o->widgetPos.y()));
       o->setZValue(0);
    }

    for (int i=obj->cardId+1;i<curCardsNum;i++){

         CardGraphicsProxyWidget *o=cardsProxyV.at(i);
         o->setPos(QPointF(o->widgetPos.x()+CARD_WIDTH,o->widgetPos.y()));
         o->setZValue(0);
    }
}

void FightInterface::narrowCards(CardGraphicsProxyWidget *obj)
{

    for(int i=0;i<obj->cardId;i++){
       CardGraphicsProxyWidget *o=cardsProxyV.at(i);
       o->setPos(QPointF(o->widgetPos.x(),o->widgetPos.y()));
    }

    for (int i=obj->cardId+1;i<curCardsNum;i++){
         CardGraphicsProxyWidget *o=cardsProxyV.at(i);
         o->setPos(QPointF(o->widgetPos.x(),o->widgetPos.y()));
    }

}

void FightInterface::startAE(QString path, QRectF r)
{
        AEWidget *cardAE=new AEWidget(EFFECT_PATH+"card_used/0005",QSize(r.width(),r.height()/2));
        cardAEProxyWidget=scene->addWidget(cardAE);
        cardAEProxyWidget->setPos(QPointF(r.x(),r.y()-r.height()/4));
        cardAEProxyWidget->setZValue(2);
        cardAE->startAE();
}

void FightInterface::updateAE(QRectF r)
{
    cardAEProxyWidget->setPos(QPointF(r.x(),r.y()-r.height()/4));
}

void FightInterface::stopAE()
{
    cardAEProxyWidget->deleteLater();
}

void FightInterface::nextTurn()
{
    //下一回合
    finishTurnBtn->ui->pushButton->setEnabled(0);
    //丢掉所有手牌
    removeCards();
    enemyTurn();
    QTimer *t= new QTimer();
    t->setSingleShot(1);
    connect(t,&QTimer::timeout,this,[=](){
        createCards();
    });
    t->start(2000);



}

void FightInterface::injuredFontAni(int injured, Character *c)
{
    QLabel *l;
    if(injured<=0){
        l=new QLabel(QString::number(injured));

    }
    else{
        l=new QLabel(QString::number(0));
    }
    l->setFixedSize(c->characterLabel->size());
    l->setAttribute(Qt::WA_TranslucentBackground, true);
    l->setStyleSheet("font: 30pt \"微软雅黑\"; \
                     color: rgb(223, 45, 45);"
                                             "");
    l->setAlignment(Qt::AlignHCenter);
    QGraphicsProxyWidget *pw=scene->addWidget(l);
    QPropertyAnimation *ani = new QPropertyAnimation(pw,"pos");

    ani->setDuration(1000);
    ani->setStartValue(c->characterWidget->pos());
    ani->setEndValue(QPoint(c->characterWidget->x(),c->characterWidget->y()-100));
    ani->start(QAbstractAnimation::DeleteWhenStopped);
    connect(ani,&QPropertyAnimation::finished,pw,&QGraphicsProxyWidget::deleteLater);
}

void FightInterface::removeCards()
{
    //BUG
    int _size=cardsProxyV.size();
    for(int i=0;i<_size;i++) {

        CardGraphicsProxyWidget *card = cardsProxyV[0];
        card->cardsReady=0;
        cardsProxyV.removeFirst();

        QPropertyAnimation *ani =new QPropertyAnimation(card,"pos");
        ani->setStartValue(card->pos().toPoint());
        ani->setEndValue(QPoint(width(),height()));
        ani->setDuration(500);
        ani->start(QAbstractAnimation::DeleteWhenStopped);

        connect(ani,&QPropertyAnimation::finished,this,[=](){
             scene->removeItem(card);
             card->close();

        });

        QTimer *tim=new QTimer();
        tim->setSingleShot(1);
        connect(tim,&QTimer::timeout,this,[=](){

        });
        tim->start(1000);
    }


//    cardsProxyV.remove(0,cardsProxyV.size());

}

void FightInterface::getCard(int num)
{

}




void FightInterface::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}

void FightInterface::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

void FightInterface::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}







