#ifndef FIGHTGRAPHICSVIEW_H
#define FIGHTGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
class FightGraphicsView : public QGraphicsView
{
public:
    FightGraphicsView(QWidget *parent=nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;


};

#endif // FIGHTGRAPHICSVIEW_H
