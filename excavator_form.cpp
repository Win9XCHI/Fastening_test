#include "excavator_form.h"
#include "ui_excavator_form.h"

Excavator_Form::Excavator_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Excavator_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/excavator.bmp");
    show_graphics();
}

Excavator_Form::~Excavator_Form()
{
    delete ui;
}

void Excavator_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
