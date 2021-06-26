#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/about_form.h"
#include "controller/motorgrader_form.h"
#include "controller/excavator_form.h"
#include "controller/bulldozer_form.h"
#include "controller/scraper_form.h"
#include "controller/kraz_pl_form.h"
#include "controller/kraz_form.h"
#include "controller/vgm_form.h"
#include "controller/password_form.h"
#include "model/excavator_db.h"

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

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //ProjectDB *DB;
};
#endif // MAINWINDOW_H
