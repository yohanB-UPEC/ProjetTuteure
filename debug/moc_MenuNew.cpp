/****************************************************************************
** Meta object code from reading C++ file 'MenuNew.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/View/Menu/MenuNew.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuNew.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuNew_t {
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuNew_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuNew_t qt_meta_stringdata_MenuNew = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MenuNew"
QT_MOC_LITERAL(1, 8, 6), // "s_File"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "s_Project"
QT_MOC_LITERAL(4, 26, 9), // "s_Package"
QT_MOC_LITERAL(5, 36, 7), // "s_Class"
QT_MOC_LITERAL(6, 44, 11), // "s_Interface"
QT_MOC_LITERAL(7, 56, 6), // "s_Enum"
QT_MOC_LITERAL(8, 63, 8), // "s_Folder"
QT_MOC_LITERAL(9, 72, 11) // "s_SrcFolder"

    },
    "MenuNew\0s_File\0\0s_Project\0s_Package\0"
    "s_Class\0s_Interface\0s_Enum\0s_Folder\0"
    "s_SrcFolder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuNew[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuNew::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuNew *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_File(); break;
        case 1: _t->s_Project(); break;
        case 2: _t->s_Package(); break;
        case 3: _t->s_Class(); break;
        case 4: _t->s_Interface(); break;
        case 5: _t->s_Enum(); break;
        case 6: _t->s_Folder(); break;
        case 7: _t->s_SrcFolder(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MenuNew::staticMetaObject = { {
    &QMenu::staticMetaObject,
    qt_meta_stringdata_MenuNew.data,
    qt_meta_data_MenuNew,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuNew::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuNew::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuNew.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int MenuNew::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
