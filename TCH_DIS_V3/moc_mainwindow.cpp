/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ethercat_t {
    QByteArrayData data[5];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ethercat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ethercat_t qt_meta_stringdata_Ethercat = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Ethercat"
QT_MOC_LITERAL(1, 9, 8), // "updateUI"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "value"
QT_MOC_LITERAL(4, 25, 17) // "etc_communication"

    },
    "Ethercat\0updateUI\0\0value\0etc_communication"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ethercat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Ethercat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ethercat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateUI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->etc_communication(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Ethercat::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Ethercat::updateUI)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ethercat::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Ethercat.data,
    qt_meta_data_Ethercat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ethercat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ethercat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ethercat.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Ethercat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Ethercat::updateUI(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[51];
    char stringdata0[1107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_cycleStartButton_pressed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 26), // "on_cycleStopButton_pressed"
QT_MOC_LITERAL(4, 67, 20), // "on_drvButton_pressed"
QT_MOC_LITERAL(5, 88, 22), // "on_zLockButton_pressed"
QT_MOC_LITERAL(6, 111, 23), // "on_dryRunButton_pressed"
QT_MOC_LITERAL(7, 135, 20), // "on_jogButton_pressed"
QT_MOC_LITERAL(8, 156, 20), // "on_mdiButton_pressed"
QT_MOC_LITERAL(9, 177, 21), // "on_autoButton_pressed"
QT_MOC_LITERAL(10, 199, 18), // "on_xButton_pressed"
QT_MOC_LITERAL(11, 218, 18), // "on_yButton_pressed"
QT_MOC_LITERAL(12, 237, 18), // "on_zButton_pressed"
QT_MOC_LITERAL(13, 256, 21), // "on_plusButton_pressed"
QT_MOC_LITERAL(14, 278, 20), // "on_vvvButton_pressed"
QT_MOC_LITERAL(15, 299, 22), // "on_minusButton_pressed"
QT_MOC_LITERAL(16, 322, 22), // "on_ncRefButton_pressed"
QT_MOC_LITERAL(17, 345, 25), // "on_ncOffsetButton_pressed"
QT_MOC_LITERAL(18, 371, 23), // "on_retForButton_pressed"
QT_MOC_LITERAL(19, 395, 23), // "on_retRevButton_pressed"
QT_MOC_LITERAL(20, 419, 23), // "on_prcEndButton_pressed"
QT_MOC_LITERAL(21, 443, 23), // "on_almOvrButton_pressed"
QT_MOC_LITERAL(22, 467, 23), // "on_almRstButton_pressed"
QT_MOC_LITERAL(23, 491, 24), // "on_lockRstButton_pressed"
QT_MOC_LITERAL(24, 516, 10), // "onUpdateUI"
QT_MOC_LITERAL(25, 527, 8), // "uint32_t"
QT_MOC_LITERAL(26, 536, 11), // "etcOutValue"
QT_MOC_LITERAL(27, 548, 28), // "on_cycleStartButton_released"
QT_MOC_LITERAL(28, 577, 27), // "on_cycleStopButton_released"
QT_MOC_LITERAL(29, 605, 21), // "on_mdiButton_released"
QT_MOC_LITERAL(30, 627, 21), // "on_drvButton_released"
QT_MOC_LITERAL(31, 649, 23), // "on_zLockButton_released"
QT_MOC_LITERAL(32, 673, 24), // "on_dryRunButton_released"
QT_MOC_LITERAL(33, 698, 21), // "on_jogButton_released"
QT_MOC_LITERAL(34, 720, 22), // "on_autoButton_released"
QT_MOC_LITERAL(35, 743, 19), // "on_xButton_released"
QT_MOC_LITERAL(36, 763, 19), // "on_yButton_released"
QT_MOC_LITERAL(37, 783, 19), // "on_zButton_released"
QT_MOC_LITERAL(38, 803, 22), // "on_plusButton_released"
QT_MOC_LITERAL(39, 826, 21), // "on_vvvButton_released"
QT_MOC_LITERAL(40, 848, 23), // "on_minusButton_released"
QT_MOC_LITERAL(41, 872, 23), // "on_ncRefButton_released"
QT_MOC_LITERAL(42, 896, 26), // "on_ncOffsetButton_released"
QT_MOC_LITERAL(43, 923, 24), // "on_retForButton_released"
QT_MOC_LITERAL(44, 948, 24), // "on_prcEndButton_released"
QT_MOC_LITERAL(45, 973, 24), // "on_almOvrButton_released"
QT_MOC_LITERAL(46, 998, 24), // "on_almRstButton_released"
QT_MOC_LITERAL(47, 1023, 25), // "on_lockRstButton_released"
QT_MOC_LITERAL(48, 1049, 24), // "on_retRevButton_released"
QT_MOC_LITERAL(49, 1074, 24), // "on_laserOnButton_toggled"
QT_MOC_LITERAL(50, 1099, 7) // "checked"

    },
    "MainWindow\0on_cycleStartButton_pressed\0"
    "\0on_cycleStopButton_pressed\0"
    "on_drvButton_pressed\0on_zLockButton_pressed\0"
    "on_dryRunButton_pressed\0on_jogButton_pressed\0"
    "on_mdiButton_pressed\0on_autoButton_pressed\0"
    "on_xButton_pressed\0on_yButton_pressed\0"
    "on_zButton_pressed\0on_plusButton_pressed\0"
    "on_vvvButton_pressed\0on_minusButton_pressed\0"
    "on_ncRefButton_pressed\0on_ncOffsetButton_pressed\0"
    "on_retForButton_pressed\0on_retRevButton_pressed\0"
    "on_prcEndButton_pressed\0on_almOvrButton_pressed\0"
    "on_almRstButton_pressed\0"
    "on_lockRstButton_pressed\0onUpdateUI\0"
    "uint32_t\0etcOutValue\0on_cycleStartButton_released\0"
    "on_cycleStopButton_released\0"
    "on_mdiButton_released\0on_drvButton_released\0"
    "on_zLockButton_released\0"
    "on_dryRunButton_released\0on_jogButton_released\0"
    "on_autoButton_released\0on_xButton_released\0"
    "on_yButton_released\0on_zButton_released\0"
    "on_plusButton_released\0on_vvvButton_released\0"
    "on_minusButton_released\0on_ncRefButton_released\0"
    "on_ncOffsetButton_released\0"
    "on_retForButton_released\0"
    "on_prcEndButton_released\0"
    "on_almOvrButton_released\0"
    "on_almRstButton_released\0"
    "on_lockRstButton_released\0"
    "on_retRevButton_released\0"
    "on_laserOnButton_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x08 /* Private */,
       3,    0,  245,    2, 0x08 /* Private */,
       4,    0,  246,    2, 0x08 /* Private */,
       5,    0,  247,    2, 0x08 /* Private */,
       6,    0,  248,    2, 0x08 /* Private */,
       7,    0,  249,    2, 0x08 /* Private */,
       8,    0,  250,    2, 0x08 /* Private */,
       9,    0,  251,    2, 0x08 /* Private */,
      10,    0,  252,    2, 0x08 /* Private */,
      11,    0,  253,    2, 0x08 /* Private */,
      12,    0,  254,    2, 0x08 /* Private */,
      13,    0,  255,    2, 0x08 /* Private */,
      14,    0,  256,    2, 0x08 /* Private */,
      15,    0,  257,    2, 0x08 /* Private */,
      16,    0,  258,    2, 0x08 /* Private */,
      17,    0,  259,    2, 0x08 /* Private */,
      18,    0,  260,    2, 0x08 /* Private */,
      19,    0,  261,    2, 0x08 /* Private */,
      20,    0,  262,    2, 0x08 /* Private */,
      21,    0,  263,    2, 0x08 /* Private */,
      22,    0,  264,    2, 0x08 /* Private */,
      23,    0,  265,    2, 0x08 /* Private */,
      24,    1,  266,    2, 0x08 /* Private */,
      27,    0,  269,    2, 0x08 /* Private */,
      28,    0,  270,    2, 0x08 /* Private */,
      29,    0,  271,    2, 0x08 /* Private */,
      30,    0,  272,    2, 0x08 /* Private */,
      31,    0,  273,    2, 0x08 /* Private */,
      32,    0,  274,    2, 0x08 /* Private */,
      33,    0,  275,    2, 0x08 /* Private */,
      34,    0,  276,    2, 0x08 /* Private */,
      35,    0,  277,    2, 0x08 /* Private */,
      36,    0,  278,    2, 0x08 /* Private */,
      37,    0,  279,    2, 0x08 /* Private */,
      38,    0,  280,    2, 0x08 /* Private */,
      39,    0,  281,    2, 0x08 /* Private */,
      40,    0,  282,    2, 0x08 /* Private */,
      41,    0,  283,    2, 0x08 /* Private */,
      42,    0,  284,    2, 0x08 /* Private */,
      43,    0,  285,    2, 0x08 /* Private */,
      44,    0,  286,    2, 0x08 /* Private */,
      45,    0,  287,    2, 0x08 /* Private */,
      46,    0,  288,    2, 0x08 /* Private */,
      47,    0,  289,    2, 0x08 /* Private */,
      48,    0,  290,    2, 0x08 /* Private */,
      49,    1,  291,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   50,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_cycleStartButton_pressed(); break;
        case 1: _t->on_cycleStopButton_pressed(); break;
        case 2: _t->on_drvButton_pressed(); break;
        case 3: _t->on_zLockButton_pressed(); break;
        case 4: _t->on_dryRunButton_pressed(); break;
        case 5: _t->on_jogButton_pressed(); break;
        case 6: _t->on_mdiButton_pressed(); break;
        case 7: _t->on_autoButton_pressed(); break;
        case 8: _t->on_xButton_pressed(); break;
        case 9: _t->on_yButton_pressed(); break;
        case 10: _t->on_zButton_pressed(); break;
        case 11: _t->on_plusButton_pressed(); break;
        case 12: _t->on_vvvButton_pressed(); break;
        case 13: _t->on_minusButton_pressed(); break;
        case 14: _t->on_ncRefButton_pressed(); break;
        case 15: _t->on_ncOffsetButton_pressed(); break;
        case 16: _t->on_retForButton_pressed(); break;
        case 17: _t->on_retRevButton_pressed(); break;
        case 18: _t->on_prcEndButton_pressed(); break;
        case 19: _t->on_almOvrButton_pressed(); break;
        case 20: _t->on_almRstButton_pressed(); break;
        case 21: _t->on_lockRstButton_pressed(); break;
        case 22: _t->onUpdateUI((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 23: _t->on_cycleStartButton_released(); break;
        case 24: _t->on_cycleStopButton_released(); break;
        case 25: _t->on_mdiButton_released(); break;
        case 26: _t->on_drvButton_released(); break;
        case 27: _t->on_zLockButton_released(); break;
        case 28: _t->on_dryRunButton_released(); break;
        case 29: _t->on_jogButton_released(); break;
        case 30: _t->on_autoButton_released(); break;
        case 31: _t->on_xButton_released(); break;
        case 32: _t->on_yButton_released(); break;
        case 33: _t->on_zButton_released(); break;
        case 34: _t->on_plusButton_released(); break;
        case 35: _t->on_vvvButton_released(); break;
        case 36: _t->on_minusButton_released(); break;
        case 37: _t->on_ncRefButton_released(); break;
        case 38: _t->on_ncOffsetButton_released(); break;
        case 39: _t->on_retForButton_released(); break;
        case 40: _t->on_prcEndButton_released(); break;
        case 41: _t->on_almOvrButton_released(); break;
        case 42: _t->on_almRstButton_released(); break;
        case 43: _t->on_lockRstButton_released(); break;
        case 44: _t->on_retRevButton_released(); break;
        case 45: _t->on_laserOnButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
