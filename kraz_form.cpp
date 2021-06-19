#include "kraz_form.h"
#include "ui_kraz_form.h"

KRAZ_Form::KRAZ_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/kraz.bmp");
    show_graphics();
}

KRAZ_Form::~KRAZ_Form()
{
    delete ui;
}

void KRAZ_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
