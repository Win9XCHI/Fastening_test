#include "excavator_form.h"
#include "ui_excavator_form.h"

Excavator_Form::Excavator_Form(ExcavatorDB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Excavator_Form)
{
    ui->setupUi(this);
    DB = db;
    DB.SELECT("Icon", "Equipment", "Name = 'Екскаватор ЕО-4125 на платформі'");

    object_excavator = new Excavator(DB);
    ui->comboBox->addItem("Ні");
    ui->comboBox->addItem("Так");

    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/" + DB.GetIcon());
    SM_swilev_cursor(green_pen());
    SM_undercarriage_cursor(green_pen());
    SM_root_cursor(green_pen());
    SM_handle_cursor(green_pen());
    SM_trolley_cursor(green_pen());

    lining_cursor(green_pen());
    arrow_cursor(green_pen());
    axis_turnover_cursor(green_pen());
    axis_longitudinal_cursor(green_pen());

    SM_swilev(green_pen());
    SM_undercarriage(green_pen());
    SM_root(green_pen());
    SM_handle(green_pen());
    SM_trolley(green_pen());

    bar_thrust(green_pen());
    bar_side(green_pen(10));
    lining(green_pen());
    show_graphics();
}

Excavator_Form::~Excavator_Form()
{
    DB.close();
    delete ui;
}

void Excavator_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Excavator_Form::SM_swilev_cursor(QPen pen) {
    triangle(pen, 180, 130);
}

void Excavator_Form::SM_undercarriage_cursor(QPen pen) {
    triangle(pen, 245, 170);
    triangle(pen, 375, 170);
}

void Excavator_Form::SM_root_cursor(QPen pen) {
    triangle(pen, 330, 110);
}

void Excavator_Form::SM_handle_cursor(QPen pen) {
    triangle(pen, 590, 100);
}

void Excavator_Form::SM_trolley_cursor(QPen pen) {
    triangle(pen, 310, 190);
}

void Excavator_Form::lining_cursor(QPen pen) {
    triangle(pen, 520, 190);
}

void Excavator_Form::arrow_cursor(QPen pen) {
    scene->addLine(450, 35, 700, 35, pen);
    scene->addLine(700, 35, 700, 190, pen);
    scene->addLine(700, 190, 520, 190, pen);
}

void Excavator_Form::axis_turnover_cursor(QPen pen) {
    scene->addLine(310, 0, 310, 220, pen);
}

void Excavator_Form::axis_longitudinal_cursor(QPen pen) {
    scene->addLine(100, 140, 400, 140, pen);
}

void Excavator_Form::SM_swilev(QPen pen) {
    scene->addLine(100, 190, 180, 130, pen);
}

void Excavator_Form::SM_undercarriage(QPen pen) {
    scene->addLine(200, 190, 220, 170, pen);
    scene->addLine(500, 200, 395, 170, pen);
}

void Excavator_Form::SM_root(QPen pen) {
    scene->addLine(330, 110, 395, 200, pen);
    scene->addLine(330, 110, 500, 200, pen);
}

void Excavator_Form::SM_handle(QPen pen) {
    scene->addLine(590, 100, 635, 220, pen);
}

void Excavator_Form::SM_trolley(QPen pen) {
    scene->addLine(245, 170, 310, 190, pen);
    scene->addLine(310, 190, 375, 170, pen);
}

void Excavator_Form::bar_thrust(QPen pen) {
    scene->addLine(225, 190, 235, 190, pen);
    scene->addLine(390, 190, 400, 190, pen);
}

void Excavator_Form::bar_side(QPen pen) {
    scene->addLine(240, 185, 390, 185, pen);
}

void Excavator_Form::lining(QPen pen) {
    scene->addLine(505, 187, 530, 187, pen);
}

void Excavator_Form::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}

void Excavator_Form::FillingFormExcavator(form_excavator &object_form) {
    object_form.s1 = ui->lineEdit_7->text().toUInt();
    object_form.s2 = ui->lineEdit_9->text().toUInt();
    object_form.s3 = ui->lineEdit_11->text().toUInt();
    object_form.s4 = ui->lineEdit_13->text().toUInt();
    object_form.s5 = ui->lineEdit_15->text().toUInt();

    object_form.t1 = ui->lineEdit_8->text().toUInt();
    object_form.t2 = ui->lineEdit_10->text().toUInt();
    object_form.t3 = ui->lineEdit_12->text().toUInt();
    object_form.t4 = ui->lineEdit_14->text().toUInt();
    object_form.t5 = ui->lineEdit_17->text().toUInt();

    object_form.wd = ui->lineEdit_18->text().toUInt();
    object_form.bh = ui->lineEdit_5->text().toUInt();
    object_form.b1 = ui->lineEdit->text().toUInt();
    object_form.b2 = ui->lineEdit_3->text().toUInt();
    object_form.n1 = ui->lineEdit_2->text().toUInt();
    object_form.n2 = ui->lineEdit_4->text().toUInt();

    ui->comboBox->currentText() == "Так" ? object_form.l = true : object_form.l = false;

    object_form.at = ui->lineEdit_6->text().toDouble();
    object_form.al = ui->lineEdit_16->text().toDouble();
    object_form.gb1 = ui->lineEdit_19->text().toUInt();
    object_form.gb2 = ui->lineEdit_20->text().toUInt();
}

void Excavator_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    ui->comboBox->setStyleSheet("color: rgb(0, 0, 0)");
}

bool Excavator_Form::CheckAnswer(form_answer_excavator form) {
    bool flag(true);

    if (!form.s1) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_3->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s2) {
        ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s3) {
        ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t3) {
        ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_7->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s4) {
        ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_8->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t4) {
        ui->lineEdit_14->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_9->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s5) {
        ui->lineEdit_15->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_10->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t5) {
        ui->lineEdit_17->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    if (!form.gb1) {
        ui->lineEdit_19->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.gb2) {
        ui->lineEdit_20->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    if (!form.b1) {
        ui->lineEdit->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_13->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_2->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_14->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_3->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_15->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_4->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_16->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    if (!form.wd) {
        ui->lineEdit_18->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_2->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.at) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_20->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.al) {
        ui->lineEdit_16->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_17->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l) {
        ui->comboBox->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_18->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.bh) {
        ui->lineEdit_5->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_19->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    return flag;
}

void Excavator_Form::on_pushButton_clicked()
{
    Default();
    form_excavator object_form;
    FillingFormExcavator(object_form);
    form_answer_excavator object_answer = object_excavator->CheckAnswer(object_form);

    frame message;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::EXCAVATOR;
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::EXCAVATOR;
    }
    Message_Form *object = new Message_Form(message);
    object->show();
}
