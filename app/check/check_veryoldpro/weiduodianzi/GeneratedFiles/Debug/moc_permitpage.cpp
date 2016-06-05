/****************************************************************************
** Meta object code from reading C++ file 'permitpage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../permitpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'permitpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PermitPage[] = {

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
      12,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PermitPage[] = {
    "PermitPage\0\0on_registerBtn_clicked()\0"
    "on_updateBtn_clicked()\0on_serialBtn_clicked()\0"
    "ipChanged()\0"
};

void PermitPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PermitPage *_t = static_cast<PermitPage *>(_o);
        switch (_id) {
        case 0: _t->on_registerBtn_clicked(); break;
        case 1: _t->on_updateBtn_clicked(); break;
        case 2: _t->on_serialBtn_clicked(); break;
        case 3: _t->ipChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PermitPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PermitPage::staticMetaObject = {
    { &CBasePage::staticMetaObject, qt_meta_stringdata_PermitPage,
      qt_meta_data_PermitPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PermitPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PermitPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PermitPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PermitPage))
        return static_cast<void*>(const_cast< PermitPage*>(this));
    return CBasePage::qt_metacast(_clname);
}

int PermitPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
