/****************************************************************************
** Meta object code from reading C++ file 'FlowFixPage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowFixPage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlowFixPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlowFixPage[] = {

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
      17,   13,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,
      60,   12,   12,   12, 0x08,
      81,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FlowFixPage[] = {
    "FlowFixPage\0\0dir\0getOutTableFocus(int)\0"
    "on_saveBtn_clicked()\0on_backBtn_clicked()\0"
    "updateFlowList()\0waveLenChanged(QString)\0"
};

void FlowFixPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlowFixPage *_t = static_cast<FlowFixPage *>(_o);
        switch (_id) {
        case 0: _t->getOutTableFocus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_saveBtn_clicked(); break;
        case 2: _t->on_backBtn_clicked(); break;
        case 3: _t->updateFlowList(); break;
        case 4: _t->waveLenChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlowFixPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlowFixPage::staticMetaObject = {
    { &CBasePage::staticMetaObject, qt_meta_stringdata_FlowFixPage,
      qt_meta_data_FlowFixPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlowFixPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlowFixPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlowFixPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlowFixPage))
        return static_cast<void*>(const_cast< FlowFixPage*>(this));
    return CBasePage::qt_metacast(_clname);
}

int FlowFixPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBasePage::qt_metacall(_c, _id, _a);
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
