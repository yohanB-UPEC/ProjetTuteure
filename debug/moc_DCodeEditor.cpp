/****************************************************************************
** Meta object code from reading C++ file 'DCodeEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/View/Widget/DCodeEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DCodeEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DCodeEditor_t {
    QByteArrayData data[7];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DCodeEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DCodeEditor_t qt_meta_stringdata_DCodeEditor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DCodeEditor"
QT_MOC_LITERAL(1, 12, 19), // "leftAreaWidthUpdate"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "scrollLeftAreaUpdate"
QT_MOC_LITERAL(4, 54, 4), // "rect"
QT_MOC_LITERAL(5, 59, 2), // "dy"
QT_MOC_LITERAL(6, 62, 20) // "highlightCurrentLine"

    },
    "DCodeEditor\0leftAreaWidthUpdate\0\0"
    "scrollLeftAreaUpdate\0rect\0dy\0"
    "highlightCurrentLine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DCodeEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    2,   30,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::Int,    4,    5,
    QMetaType::Void,

       0        // eod
};

void DCodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DCodeEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->leftAreaWidthUpdate(); break;
        case 1: _t->scrollLeftAreaUpdate((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->highlightCurrentLine(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DCodeEditor::staticMetaObject = { {
    &QPlainTextEdit::staticMetaObject,
    qt_meta_stringdata_DCodeEditor.data,
    qt_meta_data_DCodeEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DCodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DCodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DCodeEditor.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int DCodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_LeftLineArea_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeftLineArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeftLineArea_t qt_meta_stringdata_LeftLineArea = {
    {
QT_MOC_LITERAL(0, 0, 12) // "LeftLineArea"

    },
    "LeftLineArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeftLineArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LeftLineArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LeftLineArea::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LeftLineArea.data,
    qt_meta_data_LeftLineArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LeftLineArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeftLineArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LeftLineArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LeftLineArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
