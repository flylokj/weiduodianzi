/****************************************************************************
** Meta object code from reading C++ file 'editctrl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../editctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditCtrl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   44,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditCtrl[] = {
    "EditCtrl\0\0currentData\0dataChanging(QString)\0"
    "var,val\0dateChanged(QString,QString)\0"
};

void EditCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditCtrl *_t = static_cast<EditCtrl *>(_o);
        switch (_id) {
        case 0: _t->dataChanging((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dateChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditCtrl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditCtrl::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_EditCtrl,
      qt_meta_data_EditCtrl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditCtrl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditCtrl))
        return static_cast<void*>(const_cast< EditCtrl*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int EditCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void EditCtrl::dataChanging(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
