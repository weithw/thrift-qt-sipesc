#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T16:12:43
#
#-------------------------------------------------

QT       += core gui sql

INCLUDEPATH += /usr/include/thrift\
            /usr/include/boost

LIBS     += /usr/lib/libthrift.so\
            /usr/lib/libevent.so\
            /usr/lib/libthriftnb.so

TARGET = ThriftServer
TEMPLATE = app


SOURCES += main.cpp\
     serverwindow.cpp \
    database.cpp \
    taskparser.cpp \
    usermanager.cpp \
    taskmanager.cpp \
    networkservicehandler.cpp \
    ../thrift/gen-cpp/Types_types.cpp \
    ../thrift/gen-cpp/Types_constants.cpp \
    ../thrift/gen-cpp/NetworkService.cpp \
    ../thrift/gen-cpp/Network_types.cpp \
    ../thrift/gen-cpp/Network_constants.cpp \
    workerthread.cpp \
    workerthreadpool.cpp \
    tasklistener.cpp

HEADERS  += \
     serverwindow.h \
    database.h \
    taskparser.h \
    usermanager.h \
    taskmanager.h \
    networkservicehandler.h \
    ../thrift/gen-cpp/Types_types.h \
    ../thrift/gen-cpp/Types_constants.h \
    ../thrift/gen-cpp/NetworkService.h \
    ../thrift/gen-cpp/Network_types.h \
    ../thrift/gen-cpp/Network_constants.h \
    workerthread.h \
    workerthreadpool.h \
    tasklistener.h




FORMS    += \
    serverwindow.ui
