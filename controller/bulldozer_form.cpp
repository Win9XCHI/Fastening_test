#include "bulldozer_form.h"
#include "ui_bulldozer_form.h"

Bulldozer_Form::Bulldozer_Form(BulldozerDB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bulldozer_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    DB = db;
    count = 0;
    scene = new QGraphicsScene;
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Ні");
    ui->comboBox->addItem("Так");
    ui->comboBox_2->addItem("");
    ui->comboBox_2->addItem("До 15 т.");
    ui->comboBox_2->addItem("Від 15.1 до 25 т.");
    ui->comboBox_2->addItem("Від 25.1 до 50 т.");
    ui->comboBox_3->addItem("");
    ui->comboBox_3->addItem("Менше 400 мм.");
    ui->comboBox_3->addItem("400 мм. і більше");
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->groupBox_4->hide();
    ui->listWidget->addItem("Будівельні скоби");
    ui->listWidget->addItem("Цвяхи");
    ui->listWidget_2->addItem("Будівельні скоби");
    ui->listWidget_2->addItem("Бокові бруски");
    object_bulldozer = new Bulldozer(DB);
    Bulldozer_Form::set_image();
}

Bulldozer_Form::~Bulldozer_Form()
{
    DB.close();
    delete ui;
}

void Bulldozer_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Bulldozer_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(20, 200, 60, 170, pen);
    scene->addLine(370, 210, 300, 150, pen);
}

void Bulldozer_Form::bar_thrust_cursor(QPen pen) {
    scene->addLine(40, 190, 60, 190, pen);
    scene->addLine(270, 195, 290, 195, pen);
}

void Bulldozer_Form::bar_side_cursor(QPen pen) {
    scene->addLine(80, 195, 250, 195, pen);
}

void Bulldozer_Form::lining_cursor(QPen pen) {
    scene->addLine(490, 220, 640, 220, pen);
}

void Bulldozer_Form::on_pushButton_clicked()
{
    DB.close();
    this->close();
    emit firstWindow();
}

void Bulldozer_Form::on_pushButton_2_clicked()
{
    Default();
    form_bulldozer object_form;
    FillingFormBulldozer(object_form);
    form_answer_bulldozer object_answer = object_bulldozer->CheckAnswer(object_form);

    frame message;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::BULLDOZER;
        emit win();
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::BULLDOZER;
        scene->clear();
        set_image();
        emit fail();
    }
    Message_Form *object = new Message_Form(message);
    object->show();
}

void Bulldozer_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = 'Бульдозер Д-686 на платформі'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
}

void Bulldozer_Form::FillingFormBulldozer(form_bulldozer &object_form) {
    object_form.s = ui->lineEdit->text().toUInt();
    object_form.wd = ui->lineEdit_2->text().toUInt();
    object_form.t = ui->lineEdit_3->text().toUInt();
    object_form.b = ui->lineEdit_4->text().toUInt();
    object_form.st1 = ui->lineEdit_9->text().toUInt();
    object_form.n1 = ui->lineEdit_16->text().toUInt();
    object_form.nl1 = ui->lineEdit_17->text().toUInt();
    object_form.st2 = ui->lineEdit_10->text().toUInt();
    object_form.st = ui->lineEdit_11->text().toUInt();
    object_form.sw = ui->lineEdit_12->text().toUInt();
    object_form.sl = ui->lineEdit_13->text().toUInt();
    object_form.sn = ui->lineEdit_14->text().toUInt();
    object_form.gap1 = ui->lineEdit_15->text().toUInt();
    object_form.gap2 = ui->lineEdit_18->text().toUInt();
    object_form.ln = ui->lineEdit_8->text().toUInt();
    object_form.lt = ui->lineEdit_5->text().toUInt();
    object_form.lw = ui->lineEdit_6->text().toUInt();
    object_form.ll = ui->lineEdit_7->text().toUInt();

    ui->comboBox->currentText() == "Так" ? object_form.l = true : object_form.l = false;
    object_form.weight = ui->comboBox_2->currentText();
    object_form.width = ui->comboBox_3->currentText();
    if (ui->listWidget->currentRow() != -1) {
        object_form.nail_boards = ui->listWidget->currentItem()->text();
    }
    if (ui->listWidget_2->currentRow() != -1) {
        object_form.side_bar = ui->listWidget_2->currentItem()->text();
    }
}

void Bulldozer_Form::Default() {
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

bool Bulldozer_Form::CheckAnswer(form_answer_bulldozer form) {
    bool flag(true);

    if (!form.s) {
        ui->lineEdit->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_2->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_2->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_3->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (ui->comboBox_2->currentText() == "") {
        ui->label->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;

    } else {
        if (!form.t) {
            ui->lineEdit_3->setStyleSheet("color: rgb(200, 0, 0)");
            ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
            flag = false;
        }
    }
    if (!form.b) {
        ui->lineEdit_4->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    if (ui->listWidget->currentRow() == -1) {
        ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    } else {

        if (ui->listWidget->currentItem()->text() == "Будівельні скоби") {
            if (!form.st1) {
                ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_15->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
        }
        if (ui->listWidget->currentItem()->text() == "Цвяхи") {
            if (!form.n1) {
                ui->lineEdit_16->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_21->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.nl1) {
                ui->lineEdit_17->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_22->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
        }
    }

    if (ui->listWidget_2->currentRow() == -1) {
        ui->label_7->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    } else {

        if (ui->listWidget_2->currentItem()->text() == "Будівельні скоби") {
            if (ui->comboBox_3->currentText() == "") {
                ui->label_16->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            } else {
                if (!form.st2) {
                    ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
                    ui->label_17->setStyleSheet("color: rgb(200, 0, 0)");
                    flag = false;
                }
            }
        }

        if (ui->listWidget_2->currentItem()->text() == "Бокові бруски") {
            if (!form.st) {
                ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_25->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.sw) {
                ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_14->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.sl) {
                ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_26->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.sn) {
                ui->lineEdit_14->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_19->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.gap1) {
                ui->lineEdit_15->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_20->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
            if (!form.gap2) {
                ui->lineEdit_18->setStyleSheet("color: rgb(200, 0, 0)");
                ui->label_20->setStyleSheet("color: rgb(200, 0, 0)");
                flag = false;
            }
        }
    }


    if (!form.l) {
        ui->label_8->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.ln) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_13->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.lt) {
        ui->lineEdit_5->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_10->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.lw) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.ll) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    return flag;
}

void Bulldozer_Form::on_listWidget_currentTextChanged(const QString &currentText) {
    if (currentText == "Будівельні скоби") {
        ui->groupBox_4->hide();
        ui->groupBox->show();
    }

    if (currentText == "Цвяхи" && ui->comboBox_2->currentText() == "До 15 т.") {
        ui->groupBox->hide();
        ui->groupBox_4->show();
    }
    object_bulldozer->SetNailBoards(currentText);
}

void Bulldozer_Form::on_listWidget_2_currentTextChanged(const QString &currentText) {
    if (currentText == "Бокові бруски") {
        ui->groupBox_2->hide();
        ui->groupBox_3->show();
        bar_side_cursor(red_pen());
    }

    if (currentText == "Будівельні скоби") {
        ui->groupBox_3->hide();
        ui->groupBox_2->show();
    }
    object_bulldozer->SetSideBar(currentText);
}

void Bulldozer_Form::on_comboBox_2_activated(const QString &arg1) {
    object_bulldozer->SetWeight(arg1);
}

void Bulldozer_Form::on_lineEdit_cursorPositionChanged(int arg1, int arg2) {
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        stretch_marks_cursor(green_pen());
        show_graphics();
    }
}

void Bulldozer_Form::on_lineEdit_editingFinished() {
    remove_last_item();
    remove_last_item();
    stretch_marks_cursor(red_pen());
    show_graphics();
}

void Bulldozer_Form::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_thrust_cursor(green_pen());
        show_graphics();
    }
}

void Bulldozer_Form::on_lineEdit_4_editingFinished()
{
    remove_last_item();
    remove_last_item();
    bar_thrust_cursor(red_pen());
    show_graphics();
}

void Bulldozer_Form::on_comboBox_3_activated(const QString &arg1) {
    if (!arg1.isEmpty()) {
        object_bulldozer->SetWidthTrack(arg1);
    }
}

void Bulldozer_Form::on_comboBox_highlighted(int index)
{
    lining_cursor(green_pen());
    count++;
    show_graphics();
}

void Bulldozer_Form::on_comboBox_activated(int index)
{
    for (unsigned int i = 0; i < count; i++) {
        remove_last_item();
    }
    count = 0;
    lining_cursor(red_pen());
    show_graphics();
}
