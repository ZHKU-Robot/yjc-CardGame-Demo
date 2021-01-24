#include "cardwidget.h"
#include "ui_cardwidget.h"
#include "QDebug"
#include "global.h"
CardWidget::CardWidget(QWidget *parent,QJsonObject j) :
    QWidget(parent),
    ui(new Ui::CardWidget)
{
    ui->setupUi(this);
    setJson(j);
    resize(QSize(CARD_WIDTH,CARD_HEIGHT));
    ui->img->    setScaledContents(true);
//    ui->img->    setFixedSize(181,110);

    setConsume(j["consume"].toInt());
    setDescription(j["description"].toString());
    setName(j["name"].toString());
    setType(j["type"].toInt());

    if(!j["gif"].toString().isEmpty()){
        QMovie *m =new QMovie(j["gif"].toString());

        ui->img->setStyleSheet("");
        ui->img->setMovie(m);
        m->start();
    }
    else
        setImgPath(j["imgPath"].toString());



}

void CardWidget::setEffect(bool (*effect)(Character *f, Character *e,CardWidget *card))
{
      this->effect=effect;
}


QString CardWidget::getImgPath() const
{
    return imgPath;
}

void CardWidget::setImgPath(const QString &value)
{
    imgPath = value;
    setLabelImage(imgPath);
}



int CardWidget::getType() const
{
    return type;
}

void CardWidget::setType(int value)
{

    type = value;
    switch (type) {
    case ATTACK:
        ui->type->setText("攻击");
        break;
    case SKILL:
        ui->type->setText("技能");
        break;
    case DEFEND:
        ui->type->setText("防御");
        break;
    default:
        break;
    }
}

QString CardWidget::getDescription() const
{
    return description;
}

void CardWidget::setDescription(const QString &value)
{
    description = value;
    ui->description->setText(description);
}

QString CardWidget::getName() const
{
    return name;
}

void CardWidget::setName(const QString &value)
{
    name = value;
    ui->name->setText(value);
}

QJsonObject CardWidget::getJson() const
{
    return json;
}

void CardWidget::setJson(const QJsonObject &value)
{
    json = value;
}

int CardWidget::getConsume() const
{
    return consume;
}



void CardWidget::setConsume(int value)
{
    consume = value;
    ui->consume->setText("消耗:"+QString::number(consume)+"MP");
}

CardWidget::CardWidget(const CardWidget *c)
{
    c->ui->setupUi(this);
    setEffect(c->effect);
    resize(QSize(CARD_WIDTH,CARD_HEIGHT));
    c->ui->img->setScaledContents(true);
//    ui->img->    setFixedSize(181,110);

    consume = c->consume;
    c->ui->consume->setText("消耗:"+QString::number(consume)+"MP");
    description = c->description;
    c->ui->description->setText(description);
    name = c->name;
    c->ui->name->setText(name);

    type = c->type;
    switch (type) {
    case ATTACK:
        c->ui->type->setText("攻击");
        break;
    case SKILL:
        c->ui->type->setText("技能");
        break;
    case DEFEND:
        c->ui->type->setText("防御");
        break;
    default:
        break;
    }

    if(!c->json["gif"].toString().isEmpty()){
        QMovie *m =new QMovie(c->json["gif"].toString());
        c->ui->img->setStyleSheet("");
        c->ui->img->setMovie(m);
        m->start();
    }
    else
        c->ui->img->setStyleSheet("border-image: url("+c->json["imgPath"].toString()+");");


}

CardWidget::~CardWidget()
{
    delete ui;
}



void CardWidget::setLabelImage(QString url)
{
    ui->img->setStyleSheet("border-image: url("+url+");");
}

void CardWidget::setLabelDescrition(QString d)
{
    ui->description->setText(d);
}


