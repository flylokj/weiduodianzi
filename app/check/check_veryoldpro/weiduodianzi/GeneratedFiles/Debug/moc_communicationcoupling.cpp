/****************************************************************************
** Meta object code from reading C++ file 'communicationcoupling.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../communicationcoupling.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communicationcoupling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommunicationCoupling[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   23,   22,   22, 0x05,
      61,   23,   22,   22, 0x05,
      93,   23,   22,   22, 0x05,
     137,  133,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     173,  156,   22,   22, 0x08,
     220,  156,   22,   22, 0x08,
     284,  266,   22,   22, 0x08,
     344,  337,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CommunicationCoupling[] = {
    "CommunicationCoupling\0\0,,\0"
    "mcuCmdSend(quint8,quint32,quint32)\0"
    "cmdSend(quint8,quint32,quint32)\0"
    "cmdSendClarity(quint32,quint32,quint32)\0"
    "ack\0ackClarity(quint8)\0type,cmd,arg,add\0"
    "processCmd4Mcu(quint8,quint32,quint32,quint32)\0"
    "processCmd4Pc(quint8,quint32,quint32,quint32)\0"
    "hID,hAI,hPFC,hVal\0"
    "processCmd4PcClarity(quint8,quint32,quint32,quint32)\0"
    "reSend\0communicationError(int)\0"
};

void CommunicationCoupling::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommunicationCoupling *_t = static_cast<CommunicationCoupling *>(_o);
        switch (_id) {
        case 0: _t->mcuCmdSend((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 1: _t->cmdSend((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 2: _t->cmdSendClarity((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 3: _t->ackClarity((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 4: _t->processCmd4Mcu((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 5: _t->processCmd4Pc((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 6: _t->processCmd4PcClarity((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 7: _t->communicationError((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommunicationCoupling::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommunicationCoupling::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommunicationCoupling,
      qt_meta_data_CommunicationCoupling, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommunicationCoupling::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommunicationCoupling::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommunicationCoupling::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicationCoupling))
        return static_cast<void*>(const_cast< CommunicationCoupling*>(this));
    return QObject::qt_metacast(_clname);
}

int CommunicationCoupling::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CommunicationCoupling::mcuCmdSend(quint8 _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommunicationCoupling::cmdSend(quint8 _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommunicationCoupling::cmdSendClarity(quint32 _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommunicationCoupling::ackClarity(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
