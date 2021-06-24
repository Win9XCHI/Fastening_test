#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/about_form.h"
#include "controller/admin_form.h"
#include "controller/motorgrader_form.h"
#include "controller/excavator_form.h"
#include "controller/bulldozer_form.h"
#include "controller/scraper_form.h"
#include "controller/kraz_pl_form.h"
#include "controller/kraz_form.h"
#include "controller/vgm_form.h"
#include "model/projectdb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    About_Form *about;
    Admin_Form *admin;
    MotorGrader_Form *motorgrader;
    Excavator_Form *excavator;
    Bulldozer_Form *bulldozer;
    Scraper_Form *scraper;
    KRAZ_pl_form *kraz_pl;
    KRAZ_Form *kraz;
    VGM_Form *vgm;

    ProjectDB *DB;
};
#endif // MAINWINDOW_H
