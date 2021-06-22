QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

PACKAGECONFIG_append_pn-qtbase = " sql-sqlite"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(view/view.pri)

SOURCES += \
    about_form.cpp \
    admin_form.cpp \
    base_technics.cpp \
    bulldozer_form.cpp \
    db.cpp \
    excavator_form.cpp \
    kraz_form.cpp \
    kraz_pl_form.cpp \
    main.cpp \
    mainwindow.cpp \
    motorgrader_form.cpp \
    projectdb.cpp \
    scraper_form.cpp \
    vgm_form.cpp

HEADERS += \
    about_form.h \
    admin_form.h \
    base_technics.h \
    bulldozer_form.h \
    db.h \
    excavator_form.h \
    kraz_form.h \
    kraz_pl_form.h \
    mainwindow.h \
    motorgrader_form.h \
    projectdb.h \
    scraper_form.h \
    vgm_form.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
