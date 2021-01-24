#ifndef QTJSONOP_H
#define QTJSONOP_H

#include <QJsonDocument>
#include <QJsonObject>
extern QJsonObject qString2Json(QString jsonString);
extern QString JsonToQstring(QJsonObject jsonObject);

#endif // QTJSONOP_H
