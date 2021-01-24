/****************************************************************************
** Meta object code from reading C++ file 'cardgraphicsproxywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CcCard/cardgraphicsproxywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardgraphicsproxywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CardGraphicsProxyWidget_t {
    QByteArrayData data[12];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardGraphicsProxyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardGraphicsProxyWidget_t qt_meta_stringdata_CardGraphicsProxyWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "CardGraphicsProxyWidget"
QT_MOC_LITERAL(1, 24, 10), // "widenCards"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "CardGraphicsProxyWidget*"
QT_MOC_LITERAL(4, 61, 3), // "obj"
QT_MOC_LITERAL(5, 65, 11), // "narrowCards"
QT_MOC_LITERAL(6, 77, 7), // "startAE"
QT_MOC_LITERAL(7, 85, 4), // "path"
QT_MOC_LITERAL(8, 90, 1), // "r"
QT_MOC_LITERAL(9, 92, 9), // "updatePos"
QT_MOC_LITERAL(10, 102, 6), // "stopAE"
QT_MOC_LITERAL(11, 109, 12) // "deleteMyself"

    },
    "CardGraphicsProxyWidget\0widenCards\0\0"
    "CardGraphicsProxyWidget*\0obj\0narrowCards\0"
    "startAE\0path\0r\0updatePos\0stopAE\0"
    "deleteMyself"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardGraphicsProxyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    2,   50,    2, 0x06 /* Public */,
       9,    1,   55,    2, 0x06 /* Public */,
      10,    0,   58,    2, 0x06 /* Public */,
      11,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QRectF,    7,    8,
    QMetaType::Void, QMetaType::QRectF,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    2,

       0        // eod
};

void CardGraphicsProxyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CardGraphicsProxyWidget *_t = static_cast<CardGraphicsProxyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->widenCards((*reinterpret_cast< CardGraphicsProxyWidget*(*)>(_a[1]))); break;
        case 1: _t->narrowCards((*reinterpret_cast< CardGraphicsProxyWidget*(*)>(_a[1]))); break;
        case 2: _t->startAE((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 3: _t->updatePos((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 4: _t->stopAE(); break;
        case 5: _t->deleteMyself((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CardGraphicsProxyWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CardGraphicsProxyWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CardGraphicsProxyWidget::*_t)(CardGraphicsProxyWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::widenCards)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CardGraphicsProxyWidget::*_t)(CardGraphicsProxyWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::narrowCards)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CardGraphicsProxyWidget::*_t)(QString , QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::startAE)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CardGraphicsProxyWidget::*_t)(QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::updatePos)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CardGraphicsProxyWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::stopAE)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CardGraphicsProxyWidget::*_t)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CardGraphicsProxyWidget::deleteMyself)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject CardGraphicsProxyWidget::staticMetaObject = {
    { &QGraphicsProxyWidget::staticMetaObject, qt_meta_stringdata_CardGraphicsProxyWidget.data,
      qt_meta_data_CardGraphicsProxyWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CardGraphicsProxyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardGraphicsProxyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CardGraphicsProxyWidget.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsProxyWidget::qt_metacast(_clname);
}

int CardGraphicsProxyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsProxyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CardGraphicsProxyWidget::widenCards(CardGraphicsProxyWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CardGraphicsProxyWidget::narrowCards(CardGraphicsProxyWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CardGraphicsProxyWidget::startAE(QString _t1, QRectF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CardGraphicsProxyWidget::updatePos(QRectF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CardGraphicsProxyWidget::stopAE()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CardGraphicsProxyWidget::deleteMyself(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
