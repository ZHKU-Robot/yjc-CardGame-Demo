    #include "cardgraphicsproxywidget.h"

#include <QCursor>
#include <QEvent>
#include <QGraphicsProxyWidget>
#include <QPropertyAnimation>
#include <qapplication.h>
#include "QDebug"
#include "aewidget.h"
#include "ui_cardwidget.h"
bool CardGraphicsProxyWidget::hovered=0;
bool CardGraphicsProxyWidget::hoverEnter=0;
bool CardGraphicsProxyWidget::selected=0;
bool CardGraphicsProxyWidget::cardState=0;
CardGraphicsProxyWidget::CardGraphicsProxyWidget(QGraphicsItem *parent, Qt::WindowFlags wFlags): QGraphicsProxyWidget(parent, wFlags)
{

}

CardGraphicsProxyWidget::CardGraphicsProxyWidget(const CardGraphicsProxyWidget &card)
{

}

CardGraphicsProxyWidget::~CardGraphicsProxyWidget()
{
    deleteLater();
}

void CardGraphicsProxyWidget::initWindowsFrame()
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

bool CardGraphicsProxyWidget::getCardState()
{
    return cardState;
}

void CardGraphicsProxyWidget::setCardState(bool value)
{
    cardState = value;
}


void CardGraphicsProxyWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(selected){
        //        QGraphicsProxyWidget::mouseMoveEvent(event);
        //将鼠标的坐标映射到scene里
        QPointF y = mapToScene(event->pos());
        //计算偏移量
        QPointF x = y - m_z;

        if(widget() != NULL){

            if(x.ry()<CARD_0_OFFSET){
                if(!cardState){
                    setCardState(true);
                    emit startAE(EFFECT_PATH+"card_used",rect());
                }
                emit updatePos(QRectF(pos(),size()));
            }
            else{

                if(cardState){
                    setCardState(false);
                    emit stopAE();
                }
            }
            setPos(QPointF(x.rx(), x.ry()));

        }
    }



}
void CardGraphicsProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    下面这条注释了的语句 nmsl 困扰我两个钟
//        QGraphicsProxyWidget::mousePressEvent(event);
    if(!selected){

        setRotation(0);
        beforeMove = scenePos();
        m_z = mapToScene(event->pos()) - beforeMove;
        selected=1;


    }
}

void CardGraphicsProxyWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{


    QGraphicsProxyWidget::mouseReleaseEvent(event);

    if(selected){

        afterMove = scenePos();
        if(widget() != NULL){
            if(afterMove.ry()<CARD_0_OFFSET){
                emit deleteMyself(this);
                setCardState(false);
                emit stopAE();
            }
            else{
                QPropertyAnimation *ani=new QPropertyAnimation(w,"pos");
                ani->setDuration(CARD_ANI_DURATION);
                ani->setEasingCurve(QEasingCurve::OutCubic);
                ani->setStartValue(QPointF(afterMove.rx(), afterMove.ry()));
                ani->setEndValue(QPointF(widgetPos.rx(), widgetPos.ry()));
                setGeometry(QRectF(afterMove.rx(), afterMove.ry(),cardSize.width(),cardSize.height()));

                setRotation(cardRotationFactor*ROTATION);
                ani->start(QAbstractAnimation::DeleteWhenStopped);
                connect(ani,&QPropertyAnimation::finished,this,[=](){
                    setGeometry(QRectF(widgetPos.rx(), widgetPos.ry(),cardSize.width(),cardSize.height()));
                    emit narrowCards(this);
                });

            }
            selected=0;

        }
    }



}

void CardGraphicsProxyWidget::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    if(cardsReady && !hoverEnter && !selected){
        QPoint p=widgetPos.toPoint();
        setRotation(0);
        hoverOffset=cardSize.height()-screenSize.height()-p.y();
        setGeometry(QRectF(p.x(),p.y()-hoverOffset*1.5,rect().width()+hoverOffset/3,rect().height()+hoverOffset/3));
//        w->ui->img->setFixedSize(rect().width()+hoverOffset/3,rect().height()+hoverOffset/3);
        hoverEnter=1;

        emit widenCards(this);
    }
}

void CardGraphicsProxyWidget::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{


    if(cardsReady && hoverEnter && !selected){

       QPropertyAnimation *ani = new QPropertyAnimation(w,"geometry");
       setRotation(cardRotationFactor*ROTATION);
       QPoint p=widgetPos.toPoint();
       ani->setStartValue(QRect(scenePos().toPoint(),size().toSize()));
       ani->setEndValue(QRect(p,cardSize));
       ani->setDuration(10);
       ani->start(QAbstractAnimation::DeleteWhenStopped);
       connect(ani,&QPropertyAnimation::finished,this,[=](){
           setGeometry(QRectF(p.x(),p.y(),cardSize.width(),cardSize.height()));
//           w->ui->img->setFixedSize(181,110);
           hoverEnter=0;

           emit narrowCards(this);
       });

    }
}

void CardGraphicsProxyWidget::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
//       qDebug()<<cardId<<"moved";
//    if(cardsReady && hovered){
//        w->raise();
//        QPoint p=widgetPos.toPoint();
//        setRotation(0);
//        int offset=cardSize.height()-screenSize.height()-p.y();
//        setGeometry(QRectF(p.x(),p.y()-offset,rect().width()+offset,rect().height()+offset));
//    }
}


