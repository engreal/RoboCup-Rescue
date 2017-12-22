TARGET = Qt-Astar

QT += widgets

CONFIG += c++11

HEADERS += \
    PrevQueue.h \
    Widget.h

SOURCES += \
    Widget.cpp \
    main.cpp \
    pathplan.cpp

RESOURCES += \
    maps.qrc
