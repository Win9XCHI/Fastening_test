#include "password_form.h"
#include "ui_password_form.h"

Password_Form::Password_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Password_Form)
{
    ui->setupUi(this);
}

Password_Form::~Password_Form()
{
    delete ui;
}

void Password_Form::on_pushButton_clicked()
{
    Admin_Form *object = new Admin_Form();
    object->show();
    this->close();
}
