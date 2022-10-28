/****************************************************************************
** Meta object code from reading C++ file 'fdecode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fdecode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fdecode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_fdecode_t {
    QByteArrayData data[9];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fdecode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fdecode_t qt_meta_stringdata_fdecode = {
    {
QT_MOC_LITERAL(0, 0, 7), // "fdecode"
QT_MOC_LITERAL(1, 8, 9), // "sendImage"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "img"
QT_MOC_LITERAL(4, 23, 7), // "sendYUV"
QT_MOC_LITERAL(5, 31, 8), // "AVFrame*"
QT_MOC_LITERAL(6, 40, 5), // "frame"
QT_MOC_LITERAL(7, 46, 11), // "sendEndFlag"
QT_MOC_LITERAL(8, 58, 4) // "flag"

    },
    "fdecode\0sendImage\0\0img\0sendYUV\0AVFrame*\0"
    "frame\0sendEndFlag\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fdecode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       7,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void fdecode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fdecode *_t = static_cast<fdecode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->sendYUV((*reinterpret_cast< AVFrame*(*)>(_a[1]))); break;
        case 2: _t->sendEndFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fdecode::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fdecode::sendImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (fdecode::*_t)(AVFrame * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fdecode::sendYUV)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (fdecode::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fdecode::sendEndFlag)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject fdecode::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_fdecode.data,
      qt_meta_data_fdecode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fdecode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fdecode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fdecode.stringdata0))
        return static_cast<void*>(const_cast< fdecode*>(this));
    return QThread::qt_metacast(_clname);
}

int fdecode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void fdecode::sendImage(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fdecode::sendYUV(AVFrame * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void fdecode::sendEndFlag(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
