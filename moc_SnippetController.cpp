/****************************************************************************
** Meta object code from reading C++ file 'SnippetController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/Controller/Widget/SnippetController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SnippetController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SnippetController_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SnippetController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SnippetController_t qt_meta_stringdata_SnippetController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SnippetController"
QT_MOC_LITERAL(1, 18, 9), // "isDeleted"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "addSnippet"
QT_MOC_LITERAL(4, 40, 8), // "validate"
QT_MOC_LITERAL(5, 49, 10), // "nomSnippet"
QT_MOC_LITERAL(6, 60, 8), // "copyFile"
QT_MOC_LITERAL(7, 69, 4), // "name"
QT_MOC_LITERAL(8, 74, 10), // "modifyFile"
QT_MOC_LITERAL(9, 85, 10) // "deleteFile"

    },
    "SnippetController\0isDeleted\0\0addSnippet\0"
    "validate\0nomSnippet\0copyFile\0name\0"
    "modifyFile\0deleteFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SnippetController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void SnippetController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SnippetController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isDeleted(); break;
        case 1: _t->addSnippet(); break;
        case 2: _t->validate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->copyFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->modifyFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->deleteFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SnippetController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SnippetController.data,
    qt_meta_data_SnippetController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SnippetController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnippetController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SnippetController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SnippetController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
