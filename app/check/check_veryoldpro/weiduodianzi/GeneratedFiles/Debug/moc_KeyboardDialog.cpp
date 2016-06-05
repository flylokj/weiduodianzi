/****************************************************************************
** Meta object code from reading C++ file 'KeyboardDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../KeyboardDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyboardDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyBoardDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      43,   15,   15,   15, 0x08,
      69,   15,   15,   15, 0x08,
      91,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     135,   15,   15,   15, 0x08,
     157,   15,   15,   15, 0x08,
     179,   15,   15,   15, 0x08,
     201,   15,   15,   15, 0x08,
     223,   15,   15,   15, 0x08,
     245,   15,   15,   15, 0x08,
     267,   15,   15,   15, 0x08,
     289,   15,   15,   15, 0x08,
     311,   15,   15,   15, 0x08,
     336,   15,   15,   15, 0x08,
     360,   15,   15,   15, 0x08,
     388,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeyBoardDialog[] = {
    "KeyBoardDialog\0\0on_confirmButton_clicked()\0"
    "on_cancelButton_clicked()\0"
    "on__1Button_clicked()\0on__2Button_clicked()\0"
    "on__3Button_clicked()\0on__4Button_clicked()\0"
    "on__5Button_clicked()\0on__6Button_clicked()\0"
    "on__7Button_clicked()\0on__8Button_clicked()\0"
    "on__9Button_clicked()\0on__0Button_clicked()\0"
    "on_ceButton_clicked()\0on_pointButton_clicked()\0"
    "on_backButton_clicked()\0"
    "on_positiveButton_clicked()\0"
    "on_negativeButton_clicked()\0"
};

void KeyBoardDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyBoardDialog *_t = static_cast<KeyBoardDialog *>(_o);
        switch (_id) {
        case 0: _t->on_confirmButton_clicked(); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->on__1Button_clicked(); break;
        case 3: _t->on__2Button_clicked(); break;
        case 4: _t->on__3Button_clicked(); break;
        case 5: _t->on__4Button_clicked(); break;
        case 6: _t->on__5Button_clicked(); break;
        case 7: _t->on__6Button_clicked(); break;
        case 8: _t->on__7Button_clicked(); break;
        case 9: _t->on__8Button_clicked(); break;
        case 10: _t->on__9Button_clicked(); break;
        case 11: _t->on__0Button_clicked(); break;
        case 12: _t->on_ceButton_clicked(); break;
        case 13: _t->on_pointButton_clicked(); break;
        case 14: _t->on_backButton_clicked(); break;
        case 15: _t->on_positiveButton_clicked(); break;
        case 16: _t->on_negativeButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData KeyBoardDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeyBoardDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KeyBoardDialog,
      qt_meta_data_KeyBoardDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyBoardDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyBoardDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyBoardDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyBoardDialog))
        return static_cast<void*>(const_cast< KeyBoardDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int KeyBoardDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
