/****************************************************************************
** Meta object code from reading C++ file 'QTimer'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../mocks_library/prac/QTimer"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTimer' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS = QtMocHelpers::stringData(
    "prac::QTimer",
    "timeout",
    "",
    "start",
    "msec",
    "setInterval",
    "interval",
    "setSingleShot",
    "single_shot",
    "stop"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[13];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[5];
    char stringdata5[12];
    char stringdata6[9];
    char stringdata7[14];
    char stringdata8[12];
    char stringdata9[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS_t qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "prac::QTimer"
        QT_MOC_LITERAL(13, 7),  // "timeout"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 5),  // "start"
        QT_MOC_LITERAL(28, 4),  // "msec"
        QT_MOC_LITERAL(33, 11),  // "setInterval"
        QT_MOC_LITERAL(45, 8),  // "interval"
        QT_MOC_LITERAL(54, 13),  // "setSingleShot"
        QT_MOC_LITERAL(68, 11),  // "single_shot"
        QT_MOC_LITERAL(80, 4)   // "stop"
    },
    "prac::QTimer",
    "timeout",
    "",
    "start",
    "msec",
    "setInterval",
    "interval",
    "setSingleShot",
    "single_shot",
    "stop"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSpracSCOPEQTimerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   51,    2, 0x0a,    2 /* Public */,
       3,    0,   54,    2, 0x0a,    4 /* Public */,
       5,    1,   55,    2, 0x0a,    5 /* Public */,
       7,    1,   58,    2, 0x0a,    7 /* Public */,
       9,    0,   61,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject prac::QTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<::QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSpracSCOPEQTimerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QTimer, std::true_type>,
        // method 'timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setInterval'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSingleShot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void prac::QTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTimer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->start((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->setInterval((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setSingleShot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTimer::*)();
            if (_t _q_method = &QTimer::timeout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *prac::QTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *prac::QTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSpracSCOPEQTimerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return ::QObject::qt_metacast(_clname);
}

int prac::QTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ::QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void prac::QTimer::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
