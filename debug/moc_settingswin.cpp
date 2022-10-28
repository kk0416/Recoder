/****************************************************************************
** Meta object code from reading C++ file 'settingswin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settingswin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_settingsWin_t {
    QByteArrayData data[8];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settingsWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settingsWin_t qt_meta_stringdata_settingsWin = {
    {
QT_MOC_LITERAL(0, 0, 11), // "settingsWin"
QT_MOC_LITERAL(1, 12, 21), // "on_PathChoose_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "on_PathChoose_clicked1"
QT_MOC_LITERAL(4, 58, 16), // "setLineEditValue"
QT_MOC_LITERAL(5, 75, 5), // "value"
QT_MOC_LITERAL(6, 81, 9), // "BtnOkSlot"
QT_MOC_LITERAL(7, 91, 13) // "BtnCancelSlot"

    },
    "settingsWin\0on_PathChoose_clicked\0\0"
    "on_PathChoose_clicked1\0setLineEditValue\0"
    "value\0BtnOkSlot\0BtnCancelSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settingsWin[] = {

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
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void settingsWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        settingsWin *_t = static_cast<settingsWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PathChoose_clicked(); break;
        case 1: _t->on_PathChoose_clicked1(); break;
        case 2: _t->setLineEditValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->BtnOkSlot(); break;
        case 4: _t->BtnCancelSlot(); break;
        default: ;
        }
    }
}

const QMetaObject settingsWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_settingsWin.data,
      qt_meta_data_settingsWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *settingsWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settingsWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_settingsWin.stringdata0))
        return static_cast<void*>(const_cast< settingsWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int settingsWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
