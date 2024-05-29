QT += core network

CONFIG += console
CONFIG -= app_bundle

TARGET = server
TEMPLATE = app

SOURCES += main.cpp \
           server.cpp \
#           encryption/hamming.cpp \
#           routing_table.cpp

HEADERS += server.h \
#           encryption/hamming.h \
#           routing_table.h

# Включите дополнительные пути к исходным файлам, если необходимо
INCLUDEPATH += encryption

