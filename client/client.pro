QT += widgets network

TARGET = client
TEMPLATE = app

SOURCES += main.cpp \
           client.cpp \
           encryption/hamming.cpp

HEADERS += client.h \
           encryption/hamming.h

FORMS += client.ui

INCLUDEPATH += encryption

