#include "password_form.h"
#include "ui_password_form.h"

Password_Form::Password_Form(AdminDB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Password_Form)
{
    ui->setupUi(this);
    DB = db;
}

Password_Form::~Password_Form()
{
    delete ui;
}

void Password_Form::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "111") {
        ui->label->setStyleSheet(COLOR_EDIT::BLACK);
        Admin_Form *object = new Admin_Form(DB);
        connect(object, &Admin_Form::firstWindow, this, &Password_Form::return_main);
        emit succes();
        object->show();
        this->close();
    } else {
        ui->label->setStyleSheet(COLOR_EDIT::RED);
    }
}
