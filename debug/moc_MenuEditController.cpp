/****************************************************************************
** Meta object code from reading C++ file 'MenuEditController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/Controller/Menu/MenuEditController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuEditController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuEditController_t {
    QByteArrayData data[16];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuEditController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuEditController_t qt_meta_stringdata_MenuEditController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MenuEditController"
QT_MOC_LITERAL(1, 19, 6), // "s_Copy"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "s_Paste"
QT_MOC_LITERAL(4, 35, 5), // "s_Cut"
QT_MOC_LITERAL(5, 41, 11), // "s_SelectAll"
QT_MOC_LITERAL(6, 53, 6), // "s_Undo"
QT_MOC_LITERAL(7, 60, 6), // "s_Redo"
QT_MOC_LITERAL(8, 67, 8), // "s_Search"
QT_MOC_LITERAL(9, 76, 12), // "s_SearchNext"
QT_MOC_LITERAL(10, 89, 12), // "s_SearchPrev"
QT_MOC_LITERAL(11, 102, 7), // "s_Suppr"
QT_MOC_LITERAL(12, 110, 4), // "find"
QT_MOC_LITERAL(13, 115, 3), // "mot"
QT_MOC_LITERAL(14, 119, 9), // "s_Replace"
QT_MOC_LITERAL(15, 129, 10) // "replaceAll"

    },
    "MenuEditController\0s_Copy\0\0s_Paste\0"
    "s_Cut\0s_SelectAll\0s_Undo\0s_Redo\0"
    "s_Search\0s_SearchNext\0s_SearchPrev\0"
    "s_Suppr\0find\0mot\0s_Replace\0replaceAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuEditController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      14,    0,   92,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuEditController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuEditController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_Copy(); break;
        case 1: _t->s_Paste(); break;
        case 2: _t->s_Cut(); break;
        case 3: _t->s_SelectAll(); break;
        case 4: _t->s_Undo(); break;
        case 5: _t->s_Redo(); break;
        case 6: _t->s_Search(); break;
        case 7: _t->s_SearchNext(); break;
        case 8: _t->s_SearchPrev(); break;
        case 9: _t->s_Suppr(); break;
        case 10: _t->find((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->s_Replace(); break;
        case 12: _t->replaceAll(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuEditController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MenuEditController.data,
    qt_meta_data_MenuEditController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuEditController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuEditController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuEditController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MenuEditController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
