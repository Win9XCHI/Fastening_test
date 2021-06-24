QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

PACKAGECONFIG_append_pn-qtbase = " sql-sqlite"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    controller\about_form.cpp \
    controller\admin_form.cpp \
    controller\base\base_technics.cpp \
    controller\bulldozer_form.cpp \
    model\driver\db.cpp \
    controller\excavator_form.cpp \
    controller\kraz_form.cpp \
    controller\kraz_pl_form.cpp \
    main.cpp \
    mainwindow.cpp \
    controller\motorgrader_form.cpp \
    model\projectdb.cpp \
    controller\scraper_form.cpp \
    controller\vgm_form.cpp

HEADERS += \
    controller\about_form.h \
    controller\admin_form.h \
    controller\base\base_technics.h \
    controller\bulldozer_form.h \
    model\driver\db.h \
    controller\excavator_form.h \
    controller\kraz_form.h \
    controller\kraz_pl_form.h \
    model\mainwindow.h \
    controller\motorgrader_form.h \
    projectdb.h \
    controller\scraper_form.h \
    controller\vgm_form.h

FORMS += \
    view\about_form.ui \
    view\admin_form.ui \
    view\bulldozer_form.ui \
    view\excavator_form.ui \
    view\kraz_form.ui \
    view\kraz_pl_form.ui \
    view\mainwindow.ui \
    view\motorgrader_form.ui \
    view\scraper_form.ui \
    view\vgm_form.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
