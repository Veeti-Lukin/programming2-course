TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    cli.cpp \
    main.cpp \
    orienteeringmap.cpp \
    parser.cpp \
    point.cpp \
    route.cpp

HEADERS += \
    cli.hh \
    orienteeringmap.hh \
    parser.hh \
    point.hh \
    route.hh



