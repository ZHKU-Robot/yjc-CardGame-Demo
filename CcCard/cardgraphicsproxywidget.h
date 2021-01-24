#ifndef CARDGRAPHICSPROXYWIDGET_H
#define CARDGRAPHICSPROXYWIDGET_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QGraphicsProxyWidget>
#include "global.h"
#include "cardwidget.h"
class CardGraphicsProxyWidget :public QGraphicsProxyWidget
{
     Q_OBJECT
public:

    explicit CardGraphicsProxyWidget(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    explicit CardGraphicsProxyWidget(const CardGraphicsProxyWidget &card);
    ~CardGraphicsProxyWidget();

    void initWindowsFrame();
    //
    bool cardsReady=0;


    static    bool hoverEnter;
    static    bool hovered;
    static    bool selected;
    static    bool cardState;

    int cardId;
    int cardRotationFactor;
    int cardType=0;

    QPointF widgetPos;
    QSize cardSize;
    QPointF getWidgetPos() const;
    CardWidget *w;
    int hoverOffset=0;

    void setWidgetPos(const QPointF &value);
    static bool getCardState();
    static void setCardState(bool value);

signals:
    void widenCards(CardGraphicsProxyWidget* obj);
    void narrowCards(CardGraphicsProxyWidget* obj);

    void startAE(QString path,QRectF r);
    void updatePos(QRectF r);
    void stopAE();

    void deleteMyself(QObject*);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;

private:
    QPointF m_z;
    QPointF beforeMove;
    QPointF afterMove;

};

#endif // CARDGRAPHICSPROXYWIDGET_H
