/****************************************************************************
** Meta object code from reading C++ file 'iomodule.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../iomodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iomodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IoModule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      40,    9,    9,    9, 0x05,
      48,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,    9,    9,    9, 0x08,
      73,    9,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,
      93,    9,    9,    9, 0x08,
     103,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IoModule[] = {
    "IoModule\0\0success\0initLampSuccess(bool)\0"
    "bulge()\0resetMachine()\0init_s1()\0"
    "init_s2()\0init_s3()\0init_s4()\0"
    "operation_s()\0readingIO()\0"
};

void IoModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IoModule *_t = static_cast<IoModule *>(_o);
        switch (_id) {
        case 0: _t->initLampSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->bulge(); break;
        case 2: _t->resetMachine(); break;
        case 3: _t->init_s1(); break;
        case 4: _t->init_s2(); break;
        case 5: _t->init_s3(); break;
        case 6: _t->init_s4(); break;
        case 7: _t->operation_s(); break;
        case 8: _t->readingIO(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IoModule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IoModule::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IoModule,
      qt_meta_data_IoModule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IoModule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IoModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IoModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IoModule))
        return static_cast<void*>(const_cast< IoModule*>(this));
    return QObject::qt_metacast(_clname);
}

int IoModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void IoModule::initLampSuccess(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IoModule::bulge()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void IoModule::resetMachine()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
