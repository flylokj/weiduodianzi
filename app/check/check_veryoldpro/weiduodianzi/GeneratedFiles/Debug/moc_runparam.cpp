/****************************************************************************
** Meta object code from reading C++ file 'runparam.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../runparam.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runparam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunParamPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      37,   33,   13,   13, 0x08,
      62,   33,   13,   13, 0x08,
      87,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RunParamPage[] = {
    "RunParamPage\0\0on_lpBtn_clicked()\0str\0"
    "waveLen1Changed(QString)\0"
    "waveLen2Changed(QString)\0chanelChnaged(int)\0"
};

void RunParamPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RunParamPage *_t = static_cast<RunParamPage *>(_o);
        switch (_id) {
        case 0: _t->on_lpBtn_clicked(); break;
        case 1: _t->waveLen1Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->waveLen2Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->chanelChnaged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RunParamPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RunParamPage::staticMetaObject = {
    { &CBasePage::staticMetaObject, qt_meta_stringdata_RunParamPage,
      qt_meta_data_RunParamPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunParamPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunParamPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunParamPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunParamPage))
        return static_cast<void*>(const_cast< RunParamPage*>(this));
    return CBasePage::qt_metacast(_clname);
}

int RunParamPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBasePage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
