/****************************************************************************
** Meta object code from reading C++ file 'calendarkj.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calendarkj.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarkj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calendarKJ_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calendarKJ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calendarKJ_t qt_meta_stringdata_calendarKJ = {
    {
QT_MOC_LITERAL(0, 0, 10), // "calendarKJ"
QT_MOC_LITERAL(1, 11, 21), // "signalSetCalendarTime"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "data"
QT_MOC_LITERAL(4, 39, 12), // "onbtnClicked"
QT_MOC_LITERAL(5, 52, 16) // "btnEnsureClicked"

    },
    "calendarKJ\0signalSetCalendarTime\0\0"
    "data\0onbtnClicked\0btnEnsureClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendarKJ[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calendarKJ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendarKJ *_t = static_cast<calendarKJ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSetCalendarTime((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: _t->onbtnClicked(); break;
        case 2: _t->btnEnsureClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendarKJ::*_t)(const QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendarKJ::signalSetCalendarTime)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject calendarKJ::staticMetaObject = {
    { &QCalendarWidget::staticMetaObject, qt_meta_stringdata_calendarKJ.data,
      qt_meta_data_calendarKJ,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calendarKJ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendarKJ::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calendarKJ.stringdata0))
        return static_cast<void*>(const_cast< calendarKJ*>(this));
    return QCalendarWidget::qt_metacast(_clname);
}

int calendarKJ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCalendarWidget::qt_metacall(_c, _id, _a);
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
void calendarKJ::signalSetCalendarTime(const QDate & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
