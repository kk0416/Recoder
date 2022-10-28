/****************************************************************************
** Meta object code from reading C++ file 'mainwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainWin_t {
    QByteArrayData data[10];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWin_t qt_meta_stringdata_mainWin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "mainWin"
QT_MOC_LITERAL(1, 8, 12), // "recviceImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "image"
QT_MOC_LITERAL(4, 28, 10), // "recviceYUV"
QT_MOC_LITERAL(5, 39, 8), // "AVFrame*"
QT_MOC_LITERAL(6, 48, 5), // "frame"
QT_MOC_LITERAL(7, 54, 14), // "recviceEndFlag"
QT_MOC_LITERAL(8, 69, 4), // "flag"
QT_MOC_LITERAL(9, 74, 7) // "BtnSlot"

    },
    "mainWin\0recviceImage\0\0image\0recviceYUV\0"
    "AVFrame*\0frame\0recviceEndFlag\0flag\0"
    "BtnSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       9,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void mainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainWin *_t = static_cast<mainWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recviceImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->recviceYUV((*reinterpret_cast< AVFrame*(*)>(_a[1]))); break;
        case 2: _t->recviceEndFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->BtnSlot(); break;
        default: ;
        }
    }
}

const QMetaObject mainWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainWin.data,
      qt_meta_data_mainWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainWin.stringdata0))
        return static_cast<void*>(const_cast< mainWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
