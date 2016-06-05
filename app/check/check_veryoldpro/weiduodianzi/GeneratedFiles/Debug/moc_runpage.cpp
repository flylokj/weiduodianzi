/****************************************************************************
** Meta object code from reading C++ file 'runpage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../runpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,    9,    8,    8, 0x08,
      72,   67,    8,    8, 0x08,
     120,  114,    8,    8, 0x08,
     152,  142,    8,    8, 0x08,
     187,  183,    8,    8, 0x08,
     212,  183,    8,    8, 0x08,
     237,    8,    8,    8, 0x08,
     262,  257,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RunPage[] = {
    "RunPage\0\0s,r,au,which\0"
    "updateAuValue(quint32,quint32,double,quint8)\0"
    "stat\0changeLampStat(MachineStat::LampStatment)\0"
    "index\0lampComboChanged(int)\0str,which\0"
    "updateWlenDisp(QString,quint8)\0str\0"
    "waveLen1Changed(QString)\0"
    "waveLen2Changed(QString)\0updateStartupTime()\0"
    "wlen\0updateTestSignal(double)\0"
};

void RunPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RunPage *_t = static_cast<RunPage *>(_o);
        switch (_id) {
        case 0: _t->updateAuValue((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 1: _t->changeLampStat((*reinterpret_cast< MachineStat::LampStatment(*)>(_a[1]))); break;
        case 2: _t->lampComboChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateWlenDisp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 4: _t->waveLen1Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->waveLen2Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateStartupTime(); break;
        case 7: _t->updateTestSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RunPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RunPage::staticMetaObject = {
    { &CBasePage::staticMetaObject, qt_meta_stringdata_RunPage,
      qt_meta_data_RunPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunPage))
        return static_cast<void*>(const_cast< RunPage*>(this));
    return CBasePage::qt_metacast(_clname);
}

int RunPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBasePage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
