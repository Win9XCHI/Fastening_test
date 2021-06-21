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
    StretchMarks_cursor(green_pen());
    BarT_cursor(green_pen());
    BarS_cursor(green_pen());
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

void Bulldozer_Form::StretchMarks_cursor(QPen pen) {
    scene->addLine(20, 200, 60, 170, pen);
    scene->addLine(370, 210, 300, 150, pen);
}

void Bulldozer_Form::BarT_cursor(QPen pen) {
    scene->addLine(40, 190, 60, 190, pen);
    scene->addLine(270, 195, 290, 195, pen);
}

void Bulldozer_Form::BarS_cursor(QPen pen) {
    scene->addLine(80, 195, 250, 195, pen);
}
