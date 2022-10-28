/****************************************************************************
** Meta object code from reading C++ file 'pictoviewwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pictoviewwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pictoviewwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PicToViewWin_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PicToViewWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PicToViewWin_t qt_meta_stringdata_PicToViewWin = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PicToViewWin"
QT_MOC_LITERAL(1, 13, 15), // "ReturnTlbtnSlot"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "showCalendarSlot"
QT_MOC_LITERAL(4, 47, 11), // "GetItemName"
QT_MOC_LITERAL(5, 59, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 76, 4), // "item"
QT_MOC_LITERAL(7, 81, 13), // "Enlargeimages"
QT_MOC_LITERAL(8, 95, 14) // "ReturnListSlot"

    },
    "PicToViewWin\0ReturnTlbtnSlot\0\0"
    "showCalendarSlot\0GetItemName\0"
    "QListWidgetItem*\0item\0Enlargeimages\0"
    "ReturnListSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PicToViewWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       7,    1,   44,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void PicToViewWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PicToViewWin *_t = static_cast<PicToViewWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnTlbtnSlot(); break;
        case 1: _t->showCalendarSlot(); break;
        case 2: _t->GetItemName((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->Enlargeimages((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->ReturnListSlot(); break;
        default: ;
        }
    }
}

const QMetaObject PicToViewWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PicToViewWin.data,
      qt_meta_data_PicToViewWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PicToViewWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicToViewWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PicToViewWin.stringdata0))
        return static_cast<void*>(const_cast< PicToViewWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int PicToViewWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
