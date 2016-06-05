/****************************************************************************
** Meta object code from reading C++ file 'AdminPage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AdminPage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdminPage[] = {

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
      11,   10,   10,   10, 0x08,
      34,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,
      74,   10,   10,   10, 0x08,
      94,   10,   10,   10, 0x08,
     118,  114,   10,   10, 0x08,
     139,  135,   10,   10, 0x08,
     162,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdminPage[] = {
    "AdminPage\0\0on_activeBtn_clicked()\0"
    "on_utcBtn_clicked()\0on_xtcBtn_clicked()\0"
    "on_ttcBtn_clicked()\0on_lpcBtn_clicked()\0"
    "idx\0changePcPro(int)\0val\0"
    "tryDayChanged(QString)\0on_rstBtn_clicked()\0"
};

void AdminPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AdminPage *_t = static_cast<AdminPage *>(_o);
        switch (_id) {
        case 0: _t->on_activeBtn_clicked(); break;
        case 1: _t->on_utcBtn_clicked(); break;
        case 2: _t->on_xtcBtn_clicked(); break;
        case 3: _t->on_ttcBtn_clicked(); break;
        case 4: _t->on_lpcBtn_clicked(); break;
        case 5: _t->changePcPro((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->tryDayChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_rstBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AdminPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AdminPage::staticMetaObject = {
    { &CBasePage::staticMetaObject, qt_meta_stringdata_AdminPage,
      qt_meta_data_AdminPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdminPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdminPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdminPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdminPage))
        return static_cast<void*>(const_cast< AdminPage*>(this));
    return CBasePage::qt_metacast(_clname);
}

int AdminPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
