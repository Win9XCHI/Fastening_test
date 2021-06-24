#include "kraz_pl_form.h"
#include "ui_kraz_pl_form.h"

KRAZ_pl_form::KRAZ_pl_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_pl_form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/kraz_pl.bmp");
    bar_cursor(green_pen());
    bars(green_pen());
    stretch_marks_cursor(green_pen());
    show_graphics();
}

KRAZ_pl_form::~KRAZ_pl_form()
{
    delete ui;
}

void KRAZ_pl_form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void KRAZ_pl_form::bar_cursor(QPen pen) {
    triangle(pen, 190, 280);
    triangle(pen, 240, 280);
    triangle(pen, 490, 280);
    triangle(pen, 640, 280);
}

void KRAZ_pl_form::bars(QPen pen) {
    scene->addLine(180, 280, 190, 280, pen);
    scene->addLine(240, 280, 250, 280, pen);
    scene->addLine(480, 280, 490, 280, pen);
    scene->addLine(640, 280, 650, 280, pen);
}

void KRAZ_pl_form::stretch_marks_cursor(QPen pen) {
    scene->addLine(80, 280, 180, 250, pen);
    scene->addLine(710, 300, 660, 250, pen);
}

void KRAZ_pl_form::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}
