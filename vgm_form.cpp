#include "vgm_form.h"
#include "ui_vgm_form.h"

VGM_Form::VGM_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VGM_Form)
{
    ui->setupUi(this);
}

VGM_Form::~VGM_Form()
{
    delete ui;
}
