#include "bulldozer_form.h"
#include "ui_bulldozer_form.h"

Bulldozer_Form::Bulldozer_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bulldozer_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/bulldozer.bmp");
    show_graphics();
}

Bulldozer_Form::~Bulldozer_Form()
{
    delete ui;
}

void Bulldozer_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
