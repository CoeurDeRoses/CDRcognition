/****************************************************************************
** Meta object code from reading C++ file 'fenetre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CDRcognition/fenetre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Fenetre_t {
    QByteArrayData data[15];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Fenetre_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Fenetre_t qt_meta_stringdata_Fenetre = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Fenetre"
QT_MOC_LITERAL(1, 8, 9), // "Commencer"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "Arreter"
QT_MOC_LITERAL(4, 27, 17), // "SecondesActuelles"
QT_MOC_LITERAL(5, 45, 6), // "Verif1"
QT_MOC_LITERAL(6, 52, 6), // "Verif2"
QT_MOC_LITERAL(7, 59, 6), // "Verif3"
QT_MOC_LITERAL(8, 66, 6), // "Verif4"
QT_MOC_LITERAL(9, 73, 7), // "Effacer"
QT_MOC_LITERAL(10, 81, 1), // "a"
QT_MOC_LITERAL(11, 83, 8), // "Initial1"
QT_MOC_LITERAL(12, 92, 8), // "Initial2"
QT_MOC_LITERAL(13, 101, 8), // "Initial3"
QT_MOC_LITERAL(14, 110, 8) // "Initial4"

    },
    "Fenetre\0Commencer\0\0Arreter\0SecondesActuelles\0"
    "Verif1\0Verif2\0Verif3\0Verif4\0Effacer\0"
    "a\0Initial1\0Initial2\0Initial3\0Initial4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fenetre[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    1,   81,    2, 0x0a /* Public */,
      11,    0,   84,    2, 0x0a /* Public */,
      12,    0,   85,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Fenetre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Fenetre *_t = static_cast<Fenetre *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Commencer(); break;
        case 1: _t->Arreter(); break;
        case 2: _t->SecondesActuelles(); break;
        case 3: _t->Verif1(); break;
        case 4: _t->Verif2(); break;
        case 5: _t->Verif3(); break;
        case 6: _t->Verif4(); break;
        case 7: _t->Effacer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->Initial1(); break;
        case 9: _t->Initial2(); break;
        case 10: _t->Initial3(); break;
        case 11: _t->Initial4(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Fenetre::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Fenetre.data,
      qt_meta_data_Fenetre,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Fenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
