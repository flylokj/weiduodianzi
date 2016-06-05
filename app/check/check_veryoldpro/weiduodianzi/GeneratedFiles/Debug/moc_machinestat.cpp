/****************************************************************************
** Meta object code from reading C++ file 'machinestat.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../machinestat.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'machinestat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MachineStat[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,
      67,   12,   12,   12, 0x05,
     101,   13,   12,   12, 0x05,
     157,  144,   12,   12, 0x05,
     212,  202,   12,   12, 0x05,
     240,   12,   12,   12, 0x05,
     263,  255,   12,   12, 0x05,
     288,   12,   12,   12, 0x05,
     313,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     336,  332,   12,   12, 0x0a,
     361,  355,   12,   12, 0x0a,
     387,   12,   12,   12, 0x08,
     409,  401,   12,   12, 0x08,
     431,   12,   12,   12, 0x08,
     448,   12,   12,   12, 0x08,
     462,   12,   12,   12, 0x08,
     485,   12,   12,   12, 0x08,
     498,   12,   12,   12, 0x08,
     511,   12,   12,   12, 0x08,
     523,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MachineStat[] = {
    "MachineStat\0\0stat\0"
    "machineStatChanged(MachineStat::MachineStatment)\0"
    "updateStartupTimeDisplay(quint32)\0"
    "changeLightStat(MachineStat::LampStatment)\0"
    "s,r,au,which\0updateAuValue(quint32,quint32,double,quint8)\0"
    "str,which\0wLenChanged(QString,quint8)\0"
    "wLenScanDone()\0num,str\0systemError(int,QString)\0"
    "motorInitSuccessSignal()\0testSignal(double)\0"
    "src\0changeLampSrc(int)\0which\0"
    "setUploadPcValChanel(int)\0timeoutFunc()\0"
    "success\0lightIniSuccess(bool)\0"
    "waveScanUpdate()\0initStartup()\0"
    "delayAfterUpdateWave()\0clearWave1()\0"
    "clearWave2()\0dealBulge()\0changeWlenLater()\0"
};

void MachineStat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MachineStat *_t = static_cast<MachineStat *>(_o);
        switch (_id) {
        case 0: _t->machineStatChanged((*reinterpret_cast< MachineStat::MachineStatment(*)>(_a[1]))); break;
        case 1: _t->updateStartupTimeDisplay((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->changeLightStat((*reinterpret_cast< MachineStat::LampStatment(*)>(_a[1]))); break;
        case 3: _t->updateAuValue((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 4: _t->wLenChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 5: _t->wLenScanDone(); break;
        case 6: _t->systemError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->motorInitSuccessSignal(); break;
        case 8: _t->testSignal((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->changeLampSrc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setUploadPcValChanel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->timeoutFunc(); break;
        case 12: _t->lightIniSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->waveScanUpdate(); break;
        case 14: _t->initStartup(); break;
        case 15: _t->delayAfterUpdateWave(); break;
        case 16: _t->clearWave1(); break;
        case 17: _t->clearWave2(); break;
        case 18: _t->dealBulge(); break;
        case 19: _t->changeWlenLater(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MachineStat::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MachineStat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MachineStat,
      qt_meta_data_MachineStat, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MachineStat::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MachineStat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MachineStat::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MachineStat))
        return static_cast<void*>(const_cast< MachineStat*>(this));
    return QObject::qt_metacast(_clname);
}

int MachineStat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MachineStat::machineStatChanged(MachineStat::MachineStatment _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MachineStat::updateStartupTimeDisplay(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MachineStat::changeLightStat(MachineStat::LampStatment _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MachineStat::updateAuValue(quint32 _t1, quint32 _t2, double _t3, quint8 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MachineStat::wLenChanged(QString _t1, quint8 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MachineStat::wLenScanDone()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MachineStat::systemError(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MachineStat::motorInitSuccessSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MachineStat::testSignal(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
