#include "admin_form.h"
#include "ui_admin_form.h"

Admin_Form::Admin_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Form)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Студенти/курсанти");
    ui->comboBox->addItem("Техніка");
}

Admin_Form::~Admin_Form()
{
    delete ui;
}

void Admin_Form::on_comboBox_activated(int index)
{
    if (index == 1) {
        ui->groupBox_5->show();
    }
    if (index == 2) {
        ui->groupBox_3->show();
    }
}
