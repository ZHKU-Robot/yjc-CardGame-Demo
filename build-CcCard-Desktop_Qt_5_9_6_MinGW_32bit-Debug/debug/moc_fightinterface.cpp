/****************************************************************************
** Meta object code from reading C++ file 'fightinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CcCard/fightinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fightinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FightInterface_t {
    QByteArrayData data[21];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FightInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FightInterface_t qt_meta_stringdata_FightInterface = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FightInterface"
QT_MOC_LITERAL(1, 15, 11), // "updateCards"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "usingCards"
QT_MOC_LITERAL(4, 39, 3), // "obj"
QT_MOC_LITERAL(5, 43, 10), // "widenCards"
QT_MOC_LITERAL(6, 54, 24), // "CardGraphicsProxyWidget*"
QT_MOC_LITERAL(7, 79, 11), // "narrowCards"
QT_MOC_LITERAL(8, 91, 7), // "startAE"
QT_MOC_LITERAL(9, 99, 4), // "path"
QT_MOC_LITERAL(10, 104, 1), // "r"
QT_MOC_LITERAL(11, 106, 8), // "updateAE"
QT_MOC_LITERAL(12, 115, 6), // "stopAE"
QT_MOC_LITERAL(13, 122, 8), // "nextTurn"
QT_MOC_LITERAL(14, 131, 14), // "injuredFontAni"
QT_MOC_LITERAL(15, 146, 7), // "injured"
QT_MOC_LITERAL(16, 154, 10), // "Character*"
QT_MOC_LITERAL(17, 165, 1), // "c"
QT_MOC_LITERAL(18, 167, 11), // "removeCards"
QT_MOC_LITERAL(19, 179, 7), // "getCard"
QT_MOC_LITERAL(20, 187, 3) // "num"

    },
    "FightInterface\0updateCards\0\0usingCards\0"
    "obj\0widenCards\0CardGraphicsProxyWidget*\0"
    "narrowCards\0startAE\0path\0r\0updateAE\0"
    "stopAE\0nextTurn\0injuredFontAni\0injured\0"
    "Character*\0c\0removeCards\0getCard\0num"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FightInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       3,    1,   72,    2, 0x0a /* Public */,
       5,    1,   75,    2, 0x0a /* Public */,
       7,    1,   78,    2, 0x0a /* Public */,
       8,    2,   81,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    2,   91,    2, 0x0a /* Public */,
      18,    0,   96,    2, 0x0a /* Public */,
      19,    1,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    2,
    QMetaType::Void, QMetaType::QObjectStar,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QRectF,    9,   10,
    QMetaType::Void, QMetaType::QRectF,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,   15,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void FightInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FightInterface *_t = static_cast<FightInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCards((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->usingCards((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 2: _t->widenCards((*reinterpret_cast< CardGraphicsProxyWidget*(*)>(_a[1]))); break;
        case 3: _t->narrowCards((*reinterpret_cast< CardGraphicsProxyWidget*(*)>(_a[1]))); break;
        case 4: _t->startAE((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 5: _t->updateAE((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 6: _t->stopAE(); break;
        case 7: _t->nextTurn(); break;
        case 8: _t->injuredFontAni((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Character*(*)>(_a[2]))); break;
        case 9: _t->removeCards(); break;
        case 10: _t->getCard((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CardGraphicsProxyWidget* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CardGraphicsProxyWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject FightInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FightInterface.data,
      qt_meta_data_FightInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FightInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FightInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FightInterface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FightInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
