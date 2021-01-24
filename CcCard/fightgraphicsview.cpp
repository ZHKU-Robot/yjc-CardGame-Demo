#include "fightgraphicsview.h"
#include "QDebug"

#include <QMouseEvent>
FightGraphicsView::FightGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    setObjectName("fightGraphicsView");
    setStyleSheet("QGraphicsView#fightGraphicsView{padding:0px;border:0px;background: transparent;}");
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void FightGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void FightGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug()<<event->pos();
    QGraphicsView::mouseReleaseEvent(event);
}
void FightGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug()<<event->pos();
    QGraphicsView::mouseMoveEvent(event);
}



