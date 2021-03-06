QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

PACKAGECONFIG_append_pn-qtbase = " sql-sqlite"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    classes/bar.cpp \
    classes/bulldozer.cpp \
    classes/customqdoublevalidator.cpp \
    classes/dimensions.cpp \
    classes/equipment.cpp \
    classes/excavator.cpp \
    classes/fromto.cpp \
    classes/kraz.cpp \
    classes/kraz_pl.cpp \
    classes/lining.cpp \
    classes/motorgrader.cpp \
    classes/scraper.cpp \
    classes/stretching.cpp \
    classes/test.cpp \
    classes/user.cpp \
    classes/vgm.cpp \
    controller/message_form.cpp \
    controller/about_form.cpp \
    controller/admin_form.cpp \
    controller/base\base_technics.cpp \
    controller/bulldozer_form.cpp \
    functions/validation.cpp \
    model/admin_db.cpp \
    model/bulldozer_db.cpp \
    model/driver/db.cpp \
    controller/excavator_form.cpp \
    controller/kraz_form.cpp \
    controller/kraz_pl_form.cpp \
    main.cpp \
    mainwindow.cpp \
    controller/motorgrader_form.cpp \
    controller/scraper_form.cpp \
    controller/vgm_form.cpp \
    controller/password_form.cpp \
    model/excavator_db.cpp \
    model/kraz_db.cpp \
    model/kraz_pl_db.cpp \
    model/motorgrader_db.cpp \
    model/scraper_db.cpp \
    model/user_db.cpp \
    model/vgm_db.cpp

HEADERS += \
    classes/bar.h \
    classes/bulldozer.h \
    classes/customqdoublevalidator.h \
    classes/dimensions.h \
    classes/equipment.h \
    classes/excavator.h \
    classes/fromto.h \
    classes/kraz.h \
    classes/kraz_pl.h \
    classes/lining.h \
    classes/motorgrader.h \
    classes/scraper.h \
    classes/stretching.h \
    classes/test.h \
    classes/user.h \
    classes/vgm.h \
    constants.h \
    controller/message_form.h \
    controller/about_form.h \
    controller/admin_form.h \
    controller/base/base_technics.h \
    controller/bulldozer_form.h \
    exceptions/database_exception.h \
    functions/validation.h \
    model/admin_db.h \
    model/bulldozer_db.h \
    model/driver/db.h \
    controller/excavator_form.h \
    controller/kraz_form.h \
    controller/kraz_pl_form.h \
    mainwindow.h \
    controller/motorgrader_form.h \
    controller/scraper_form.h \
    controller/vgm_form.h \
    controller/password_form.h \
    model/excavator_db.h \
    model/kraz_db.h \
    model/kraz_pl_db.h \
    model/motorgrader_db.h \
    model/scraper_db.h \
    model/user_db.h \
    model/vgm_db.h \
    structure.h

FORMS += \
    view/password_form.ui \
    view/message_form.ui \
    view/about_form.ui \
    view/admin_form.ui \
    view/bulldozer_form.ui \
    view/excavator_form.ui \
    view/kraz_form.ui \
    view/kraz_pl_form.ui \
    view/mainwindow.ui \
    view/motorgrader_form.ui \
    view/scraper_form.ui \
    view/vgm_form.ui

RC_FILE     = resources.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources.rc
