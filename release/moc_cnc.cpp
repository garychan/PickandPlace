/****************************************************************************
** Meta object code from reading C++ file 'cnc.h'
**
** Created: Sun 11. Mar 16:20:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/cnc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cnc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CNC[] = {

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
      14,    4,    5,    4, 0x0a,
      29,   24,    4,    4, 0x0a,
      48,    4,    4,    4, 0x0a,
      80,   68,   63,    4, 0x0a,
     112,  101,   63,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CNC[] = {
    "CNC\0\0TOOL_POS\0ToolPos()\0Axis\0"
    "StartMoveCont(int)\0StopMoveCont()\0"
    "bool\0NewPosition\0SetToolPos(TOOL_POS)\0"
    "ToolLenght\0SetToolLength(double)\0"
};

void CNC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CNC *_t = static_cast<CNC *>(_o);
        switch (_id) {
        case 0: { TOOL_POS _r = _t->ToolPos();
            if (_a[0]) *reinterpret_cast< TOOL_POS*>(_a[0]) = _r; }  break;
        case 1: _t->StartMoveCont((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->StopMoveCont(); break;
        case 3: { bool _r = _t->SetToolPos((*reinterpret_cast< TOOL_POS(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->SetToolLength((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CNC::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CNC::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CNC,
      qt_meta_data_CNC, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CNC::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CNC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CNC::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CNC))
        return static_cast<void*>(const_cast< CNC*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CNC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
