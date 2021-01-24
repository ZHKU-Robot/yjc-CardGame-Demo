#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <qmovie.h>
#include "character.h"
namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CardWidget(QWidget *parent = 0);
    CardWidget(const CardWidget *c);
    ~CardWidget();

    CardWidget(QWidget *parent, QJsonObject j);
    //消耗的体力
    int consume;
    int type;
    QString name;
    QString description;

    enum T{
        ATTACK,
        SKILL,
        DEFEND
    };
    QString imgPath;
    QJsonObject json;

    bool (*effect)(Character *f, Character *e, CardWidget *card);
    void setEffect(bool (*effect)(Character *f, Character *e,CardWidget *card)) ;


    void setLabelImage(QString url);
    void setLabelDescrition(QString d);
    int getConsume() const;
    void setConsume(int value);

    QJsonObject getJson() const;
    void setJson(const QJsonObject &value);

    QString getName() const;
    void setName(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getType() const;
    void setType(int value);



    QString getImgPath() const;
    void setImgPath(const QString &value);
    Ui::CardWidget *ui;
private:

};

#endif // CARDWIDGET_H
