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
