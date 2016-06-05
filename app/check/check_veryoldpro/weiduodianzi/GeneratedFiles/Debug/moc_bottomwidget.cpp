/****************************************************************************
** Meta object code from reading C++ file 'bottomwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bottomwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottomwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BottomWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      34,   13,   13,   13, 0x08,
      56,   13,   13,   13, 0x08,
      76,   13,   13,   13, 0x08,
      98,   96,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BottomWidget[] = {
    "BottomWidget\0\0on_runBtn_clicked()\0"
    "on_paramBtn_clicked()\0on_setBtn_clicked()\0"
    "on_dbgBtn_clicked()\0,\0updateWarning(int,QString)\0"
};

void BottomWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BottomWidget *_t = static_cast<BottomWidget *>(_o);
        switch (_id) {
        case 0: _t->on_runBtn_clicked(); break;
        case 1: _t->on_paramBtn_clicked(); break;
        case 2: _t->on_setBtn_clicked(); break;
        case 3: _t->on_dbgBtn_clicked(); break;
        case 4: _t->updateWarning((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BottomWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BottomWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BottomWidget,
      qt_meta_data_BottomWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BottomWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BottomWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BottomWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BottomWidget))
        return static_cast<void*>(const_cast< BottomWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BottomWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
