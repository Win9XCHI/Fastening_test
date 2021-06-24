#include "admin_form.h"
#include "ui_admin_form.h"

Admin_Form::Admin_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Form)
{
    ui->setupUi(this);
}

Admin_Form::~Admin_Form()
{
    delete ui;
}
