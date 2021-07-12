#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include "controller/about_form.h"
#include "controller/motorgrader_form.h"
#include "controller/excavator_form.h"
#include "controller/bulldozer_form.h"
#include "controller/scraper_form.h"
#include "controller/kraz_pl_form.h"
#include "controller/kraz_form.h"
#include "controller/vgm_form.h"
#include "controller/password_form.h"
#include "functions/validation.h"

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
    /* Pressing "Start test" button
     * Input: -
     * Output: - */
    void on_pushButton_3_clicked();

    /* Pressing "About" button
     * Input: -
     * Output: - */
    void on_pushButton_2_clicked();

    /* Pressing "Admin" button
     * Input: -
     * Output: - */
    void on_pushButton_clicked();

    /* Pressing "Exit" button
     * Input: -
     * Output: - */
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    /* Call form excavator
     * Input: -
     * Output: - */
    void Excavator();

    /* Call form motorgrader
     * Input: -
     * Output: - */
    void MotorGrader();

    /* Call form bulldozer
     * Input: -
     * Output: - */
    void Bulldozer();

    /* Call form KRAZ
     * Input: -
     * Output: - */
    void KRAZ();

    /* Call form KRAZ_PL
     * Input: -
     * Output: - */
    void KRAZ_PL();

    /* Call form scraper
     * Input: -
     * Output: - */
    void Scraper();

    /* Call form VGM
     * Input: -
     * Output: - */
    void VGM();

    /* Create user object from ПІБ and Взвод
     * Input: -
     * Output: user object */
    User create_user();

    /* Check file database near program, if there is not DB then throw exception
     * Input: -
     * Output: - */
    void CheckFileDB();
};
#endif // MAINWINDOW_H
