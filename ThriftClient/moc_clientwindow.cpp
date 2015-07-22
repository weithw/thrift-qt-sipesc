/****************************************************************************
** Meta object code from reading C++ file 'clientwindow.h'
**
** Created: Wed Jul 22 10:06:28 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      40,   13,   13,   13, 0x08,
      67,   13,   13,   13, 0x08,
      97,   13,   13,   13, 0x08,
     126,   13,   13,   13, 0x08,
     150,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClientWindow[] = {
    "ClientWindow\0\0on_submitButton_clicked()\0"
    "on_addFileButton_clicked()\0"
    "on_clearfilesButton_clicked()\0"
    "on_sendFilesButton_clicked()\0"
    "onUpdateStatus(QString)\0"
    "on_removeFileButton_clicked()\0"
};

void ClientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClientWindow *_t = static_cast<ClientWindow *>(_o);
        switch (_id) {
        case 0: _t->on_submitButton_clicked(); break;
        case 1: _t->on_addFileButton_clicked(); break;
        case 2: _t->on_clearfilesButton_clicked(); break;
        case 3: _t->on_sendFilesButton_clicked(); break;
        case 4: _t->onUpdateStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_removeFileButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClientWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClientWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ClientWindow,
      qt_meta_data_ClientWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWindow))
        return static_cast<void*>(const_cast< ClientWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
