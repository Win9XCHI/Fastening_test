#include "message_form.h"
#include "ui_message_form.h"

Message_Form::Message_Form(frame object, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Message_Form)
{
    ui->setupUi(this);
    ui->label->setText(object.result);
    ui->label_2->setText(object.preparation);
    ui->label_3->setText(object.string);
}

Message_Form::~Message_Form()
{
    delete ui;
}
