/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "addLog"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 15), // "timeEqualSignal"
QT_MOC_LITERAL(4, 35, 23), // "process_msg_from_serial"
QT_MOC_LITERAL(5, 59, 27), // "process_msg_from_serial_log"
QT_MOC_LITERAL(6, 87, 7), // "showLog"
QT_MOC_LITERAL(7, 95, 21), // "button_serial_clicked"
QT_MOC_LITERAL(8, 117, 11), // "changelight"
QT_MOC_LITERAL(9, 129, 11), // "changemotor"
QT_MOC_LITERAL(10, 141, 11), // "updatetimer"
QT_MOC_LITERAL(11, 153, 13), // "slotTimeEqual"
QT_MOC_LITERAL(12, 167, 8), // "openFile"
QT_MOC_LITERAL(13, 176, 8), // "saveFile"
QT_MOC_LITERAL(14, 185, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 207, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(16, 231, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(17, 255, 23) // "on_pushButton_4_clicked"

    },
    "MainWindow\0addLog\0\0timeEqualSignal\0"
    "process_msg_from_serial\0"
    "process_msg_from_serial_log\0showLog\0"
    "button_serial_clicked\0changelight\0"
    "changemotor\0updatetimer\0slotTimeEqual\0"
    "openFile\0saveFile\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       1,    1,  102,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  106,    2, 0x08 /* Private */,
       5,    1,  109,    2, 0x08 /* Private */,
       6,    1,  112,    2, 0x08 /* Private */,
       7,    0,  115,    2, 0x08 /* Private */,
       8,    1,  116,    2, 0x08 /* Private */,
       9,    1,  119,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addLog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->timeEqualSignal(); break;
        case 3: _t->process_msg_from_serial((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->process_msg_from_serial_log((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->showLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->button_serial_clicked(); break;
        case 7: _t->changelight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changemotor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updatetimer(); break;
        case 10: _t->slotTimeEqual(); break;
        case 11: _t->openFile(); break;
        case 12: _t->saveFile(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_pushButton_2_clicked(); break;
        case 15: _t->on_pushButton_3_clicked(); break;
        case 16: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addLog)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addLog)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::timeEqualSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addLog(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::addLog(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::timeEqualSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
