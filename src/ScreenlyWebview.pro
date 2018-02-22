TEMPLATE = app

QT += qml quick webkit webkitwidgets dbus
CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    view.cpp

# RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    view.h
