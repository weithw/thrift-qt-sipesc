#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T16:12:07
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += /usr/include/thrift\
            /usr/include/boost

LIBS     += /usr/lib/libthrift.so


TARGET = ThriftClient
TEMPLATE = app


SOURCES += main.cpp\
    ../thrift/gen-cpp/Types_types.cpp \
    ../thrift/gen-cpp/Types_constants.cpp \
    ../thrift/gen-cpp/NetworkService.cpp \
    ../thrift/gen-cpp/Network_types.cpp \
    ../thrift/gen-cpp/Network_constants.cpp\
       logindialog.cpp \
    clientwindow.cpp \
    commandpasrer.cpp \
    globals.cpp


HEADERS  += \
    ../thrift/gen-cpp/Types_types.h \
    ../thrift/gen-cpp/Types_constants.h \
    ../thrift/gen-cpp/NetworkService.h \
    ../thrift/gen-cpp/Network_types.h \
    ../thrift/gen-cpp/Network_constants.h\
     logindialog.h \
    clientwindow.h \
    commandparser.h \
    globals.h



FORMS    += \
    logindialog.ui \
    clientwindow.ui
