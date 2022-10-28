/****************************************************************************
** Meta object code from reading C++ file 'videoplaybackwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../videoplaybackwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplaybackwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPlaybackWin_t {
    QByteArrayData data[14];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlaybackWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlaybackWin_t qt_meta_stringdata_VideoPlaybackWin = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VideoPlaybackWin"
QT_MOC_LITERAL(1, 17, 15), // "ReturnTlbtnSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "PlayOrStpTlbtnSlot"
QT_MOC_LITERAL(4, 53, 15), // "LastVdTlbtnSlot"
QT_MOC_LITERAL(5, 69, 15), // "NextVdTlbtnSlot"
QT_MOC_LITERAL(6, 85, 16), // "PrintScTlbtnSlot"
QT_MOC_LITERAL(7, 102, 12), // "recviceImage"
QT_MOC_LITERAL(8, 115, 5), // "image"
QT_MOC_LITERAL(9, 121, 10), // "recviceYUV"
QT_MOC_LITERAL(10, 132, 8), // "AVFrame*"
QT_MOC_LITERAL(11, 141, 5), // "frame"
QT_MOC_LITERAL(12, 147, 14), // "recviceEndFlag"
QT_MOC_LITERAL(13, 162, 4) // "flag"

    },
    "VideoPlaybackWin\0ReturnTlbtnSlot\0\0"
    "PlayOrStpTlbtnSlot\0LastVdTlbtnSlot\0"
    "NextVdTlbtnSlot\0PrintScTlbtnSlot\0"
    "recviceImage\0image\0recviceYUV\0AVFrame*\0"
    "frame\0recviceEndFlag\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlaybackWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void VideoPlaybackWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoPlaybackWin *_t = static_cast<VideoPlaybackWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnTlbtnSlot(); break;
        case 1: _t->PlayOrStpTlbtnSlot(); break;
        case 2: _t->LastVdTlbtnSlot(); break;
        case 3: _t->NextVdTlbtnSlot(); break;
        case 4: _t->PrintScTlbtnSlot(); break;
        case 5: _t->recviceImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 6: _t->recviceYUV((*reinterpret_cast< AVFrame*(*)>(_a[1]))); break;
        case 7: _t->recviceEndFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VideoPlaybackWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoPlaybackWin.data,
      qt_meta_data_VideoPlaybackWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoPlaybackWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlaybackWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlaybackWin.stringdata0))
        return static_cast<void*>(const_cast< VideoPlaybackWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoPlaybackWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
