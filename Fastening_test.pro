QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about_form.cpp \
    admin_form.cpp \
    main.cpp \
    mainwindow.cpp \
    motorgrader_form.cpp \
    vgm_form.cpp

HEADERS += \
    about_form.h \
    admin_form.h \
    mainwindow.h \
    motorgrader_form.h \
    vgm_form.h

FORMS += \
    about_form.ui \
    admin_form.ui \
    mainwindow.ui \
    motorgrader_form.ui \
    vgm_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
