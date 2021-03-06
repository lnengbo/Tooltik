QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

QMAKE_LFLAGS_RELEASE = /INCREMENTAL:NO /DEBUG
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

CONFIG += c++11

include(tableWidgetFiles/tablewidget.pri)
include(moduleFiles/module.pri)
include(utils/utils.pri)
include(breakpad/breakpadsrc.pri)


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    singleApplication/qsingleapplication.cpp

HEADERS += \
    mainwindow.h \
    myDump.h \
    singleApplication/qsingleapplication.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

LIBS += -L"$$PWD/lib/" -lNetAPI32
