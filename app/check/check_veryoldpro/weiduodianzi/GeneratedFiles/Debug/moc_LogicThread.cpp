/****************************************************************************
** Meta object code from reading C++ file 'LogicThread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Communication/LogicThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogicThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Worker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,    8,    7,    7, 0x05,
      69,    8,    7,    7, 0x05,
     130,  112,    7,    7, 0x05,
     187,  180,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     224,  211,    7,    7, 0x08,
     270,  256,    7,    7, 0x08,
     310,  211,    7,    7, 0x08,
     350,  346,    7,    7, 0x08,
     373,    7,    7,    7, 0x0a,
     387,    8,    7,    7, 0x0a,
     429,  112,    7,    7, 0x0a,
     474,    8,    7,    7, 0x0a,
     521,  517,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Worker[] = {
    "Worker\0\0type,cmd,arg,add\0"
    "process4Mcu(quint8,quint32,quint32,quint32)\0"
    "process4Pc(quint8,quint32,quint32,quint32)\0"
    "hID,hAI,hPFC,nVal\0"
    "process4PcClarity(quint8,quint32,quint32,quint32)\0"
    "reSend\0communicationError(int)\0"
    "type,cmd,arg\0CmdSend(quint8,quint32,quint32)\0"
    "hAI,hPFC,hVal\0CmdSendClarity(quint32,quint32,quint32)\0"
    "CmdSend4Mcu(quint8,quint32,quint32)\0"
    "ack\0sendAckClarity(quint8)\0timeoutFunc()\0"
    "processCmd4Pc(mbyte,uint32,uint32,uint32)\0"
    "processCmd4Clarity(mbyte,mbyte,mbyte,uint32)\0"
    "processCmd4Mcu(mbyte,uint32,uint32,uint32)\0"
    "cmd\0check4Mcu(uint32)\0"
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Worker *_t = static_cast<Worker *>(_o);
        switch (_id) {
        case 0: _t->process4Mcu((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 1: _t->process4Pc((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 2: _t->process4PcClarity((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 3: _t->communicationError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CmdSend((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 5: _t->CmdSendClarity((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 6: _t->CmdSend4Mcu((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 7: _t->sendAckClarity((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 8: _t->timeoutFunc(); break;
        case 9: _t->processCmd4Pc((*reinterpret_cast< mbyte(*)>(_a[1])),(*reinterpret_cast< uint32(*)>(_a[2])),(*reinterpret_cast< uint32(*)>(_a[3])),(*reinterpret_cast< uint32(*)>(_a[4]))); break;
        case 10: _t->processCmd4Clarity((*reinterpret_cast< mbyte(*)>(_a[1])),(*reinterpret_cast< mbyte(*)>(_a[2])),(*reinterpret_cast< mbyte(*)>(_a[3])),(*reinterpret_cast< uint32(*)>(_a[4]))); break;
        case 11: _t->processCmd4Mcu((*reinterpret_cast< mbyte(*)>(_a[1])),(*reinterpret_cast< uint32(*)>(_a[2])),(*reinterpret_cast< uint32(*)>(_a[3])),(*reinterpret_cast< uint32(*)>(_a[4]))); break;
        case 12: _t->check4Mcu((*reinterpret_cast< uint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Worker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Worker,
      qt_meta_data_Worker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Worker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Worker))
        return static_cast<void*>(const_cast< Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Worker::process4Mcu(quint8 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Worker::process4Pc(quint8 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::process4PcClarity(quint8 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Worker::communicationError(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
