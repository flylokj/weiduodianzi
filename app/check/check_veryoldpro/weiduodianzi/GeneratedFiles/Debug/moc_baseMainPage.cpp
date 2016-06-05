/****************************************************************************
** Meta object code from reading C++ file 'baseMainPage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../baseMainPage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseMainPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BaseMainPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x08,
      68,   13,   13,   13, 0x08,
      89,   13,   13,   13, 0x0a,
     110,   13,   13,   13, 0x0a,
     132,   13,   13,   13, 0x0a,
     151,   13,   13,   13, 0x0a,
     172,   13,   13,   13, 0x0a,
     185,   13,   13,   13, 0x0a,
     202,   13,   13,   13, 0x0a,
     218,   13,   13,   13, 0x0a,
     234,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BaseMainPage[] = {
    "BaseMainPage\0\0stat\0"
    "machineStatChanged(MachineStat::MachineStatment)\0"
    "loopTestChangePage()\0focusNextLeftChild()\0"
    "focusNextRightChild()\0focusNextUpChild()\0"
    "focusNextDownChild()\0shortCutAZ()\0"
    "shortCutlamuda()\0shortCutRange()\0"
    "shortCutSuper()\0backToPage()\0"
};

void BaseMainPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BaseMainPage *_t = static_cast<BaseMainPage *>(_o);
        switch (_id) {
        case 0: _t->machineStatChanged((*reinterpret_cast< MachineStat::MachineStatment(*)>(_a[1]))); break;
        case 1: _t->loopTestChangePage(); break;
        case 2: _t->focusNextLeftChild(); break;
        case 3: _t->focusNextRightChild(); break;
        case 4: _t->focusNextUpChild(); break;
        case 5: _t->focusNextDownChild(); break;
        case 6: _t->shortCutAZ(); break;
        case 7: _t->shortCutlamuda(); break;
        case 8: _t->shortCutRange(); break;
        case 9: _t->shortCutSuper(); break;
        case 10: _t->backToPage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BaseMainPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BaseMainPage::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BaseMainPage,
      qt_meta_data_BaseMainPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BaseMainPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BaseMainPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BaseMainPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaseMainPage))
        return static_cast<void*>(const_cast< BaseMainPage*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BaseMainPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
