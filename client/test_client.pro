QT += core network widgets testlib

TEMPLATE = app
TARGET = ClientTest

SOURCES += test_client.cpp \
           client.cpp

HEADERS += client.h

FORMS += client.ui
