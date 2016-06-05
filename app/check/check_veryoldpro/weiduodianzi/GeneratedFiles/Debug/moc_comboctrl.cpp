/****************************************************************************
** Meta object code from reading C++ file 'comboctrl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../comboctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comboctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComboCtrl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   11,   10,   10, 0x08,
      40,   32,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ComboCtrl[] = {
    "ComboCtrl\0\0nIndex\0saveData(int)\0var,val\0"
    "dateChanged(QString,QString)\0"
};

void ComboCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ComboCtrl *_t = static_cast<ComboCtrl *>(_o);
        switch (_id) {
        case 0: _t->saveData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->dateChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ComboCtrl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComboCtrl::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_ComboCtrl,
      qt_meta_data_ComboCtrl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComboCtrl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComboCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComboCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComboCtrl))
        return static_cast<void*>(const_cast< ComboCtrl*>(this));
    return QComboBox::qt_metacast(_clname);
}

int ComboCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
