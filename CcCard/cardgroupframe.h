#ifndef CARDGROUPFRAME_H
#define CARDGROUPFRAME_H

#include <QFrame>
#include <QWidget>
#include "card.h"


class CardGroupFrame : public QFrame
{
    Q_OBJECT
public:
    CardGroupFrame(QWidget *parent=nullptr);
    void paintEvent(QPaintEvent *event)override;

};

#endif // CARDGROUPFRAME_H
