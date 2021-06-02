#-------------------------------------------------
#
# Project created by QtCreator 2020-02-12T15:17:02
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawDXF
TEMPLATE = app

VERSION = 1.2.3.0

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS += -gstabs+
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        cgraphicslineitem.cpp \
        dxflib/dl_dxf.cpp \
        dxflib/dl_writer_ascii.cpp \
        dxfreader.cpp \
        jlineitem.cpp \
        jtextitem.cpp \
        main.cpp \
        mainwindow.cpp \
        mygraphicsscene.cpp \
        mygraphicsview.cpp \
        myopenglwidget.cpp

HEADERS += \
        cgraphicslineitem.h \
        dxflib/dl_attributes.h \
        dxflib/dl_codes.h \
        dxflib/dl_creationadapter.h \
        dxflib/dl_creationinterface.h \
        dxflib/dl_dxf.h \
        dxflib/dl_entities.h \
        dxflib/dl_exception.h \
        dxflib/dl_extrusion.h \
        dxflib/dl_writer.h \
        dxflib/dl_writer_ascii.h \
        dxfreader.h \
        jlineitem.h \
        jtextitem.h \
        mainwindow.h \
        mygraphicsscene.h \
        mygraphicsview.h \
        myopenglwidget.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lopengl32 -lglu32
