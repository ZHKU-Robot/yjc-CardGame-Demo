#ifndef FIGHTINTERFACE_H
#define FIGHTINTERFACE_H

#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMovie>
#include <QMutex>
#include <QWaitCondition>
#include "QDebug"
#include "cardgraphicsproxywidget.h"
#include "cardwidget.h"
#include "global.h"
#include <QLabel>
#include <QAbstractAnimation>
#include <QAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <qprogressbar.h>
#include"aewidget.h"

#include <QCoreApplication>
#include <QDesktopWidget>
#include <QTimer>
#include <qpushbutton.h>

#include "fightgraphicsview.h"
#include "finishedturnbtn.h"
#include "mpbar.h"
#include <QTime>
namespace Ui {
class FightInterface;
}

class FightInterface : public QWidget
{
    Q_OBJECT

public:
    explicit FightInterface(QWidget *parent = 0);
    FightInterface(Character *figure,QVector<CardWidget*> cardsV, QWidget *parent=0);
    ~FightInterface();
    Ui::FightInterface *ui;
    void createCards();
    void createBoth();
    void formInit();
    void sleep(int msec);

    QPoint getCardPos(int i);
    //view
    QGraphicsView *view= new FightGraphicsView();

    // 属性
    int curCardsNum=totalCardsNum;
    //回合数
    int turn=0;
    FinishedTurnBtn *finishTurnBtn;
    MpBar *mpbar;


    Character *enemy;
    Character *figure;

    QPointF FIGURE_POS;
    QPointF ENEMY_POS;

    QGraphicsScene* scene;

    QVector<CardWidget *> cardsV;
    QVector<CardGraphicsProxyWidget *> cardsProxyV;

    QGraphicsProxyWidget *cardAEProxyWidget=NULL;
    Character *getFigure() const;
    void setFigure(Character *value);

    Character *getEnemy() const;
    void setEnemy(Character *value);


    void setCardsV( QVector<CardWidget*> cardsV);

    void enemyTurn();


public slots:
    void updateCards(QObject*);
    void usingCards(QObject* obj);
    void widenCards(CardGraphicsProxyWidget *obj);
    void narrowCards(CardGraphicsProxyWidget *obj);
    void startAE(QString path,QRectF r);
    void updateAE(QRectF r);
    void stopAE();
    void nextTurn();
    void injuredFontAni(int injured,Character *c);
    void removeCards();
    void getCard(int num);

protected:
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

};

#endif // FIGHTINTERFACE_H
