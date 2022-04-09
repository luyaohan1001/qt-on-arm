QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Find those directory with find . -name <header-file-name> if prompted error at build process.
INCLUDEPATH += /opt/opencv/release/
INCLUDEPATH += /opt/opencv/modules/core/include/
INCLUDEPATH += /opt/opencv/modules/highgui/include/
INCLUDEPATH += /opt/opencv/modules/imgcodecs/include
INCLUDEPATH += /opt/opencv/modules/videoio/include

# LIBS locates at the opencv build location.
# We expect *so shared libraries in this directory, include things such as libopencv_core.so, libopencv_highgui.so, libopencv_imgcodecs.so... etc.
 LIBS += -L/opt/opencv/release/lib \
 -lopencv_core \
 -lopencv_highgui \
 -lopencv_imgproc \
 -lopencv_videoio \
 -lopencv_imgcodecs
 INCLUDEPATH += /opt/opencv/release/lib

SOURCES += \
    camera.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    camera.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
