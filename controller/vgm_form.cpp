#include "vgm_form.h"
#include "ui_vgm_form.h"

VGM_Form::VGM_Form(VGM_DB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VGM_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    DB = db;
    name = EQUIPMENT_NAME::VGM;
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem(BULLDOZER_FORM::WIDTH_TRACK::LESS400);
    ui->comboBox->addItem(BULLDOZER_FORM::WIDTH_TRACK::MORE400);
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->groupBox_4->hide();
    ui->listWidget->addItem(VGM_FORM::STAPLES);
    ui->listWidget->addItem(VGM_FORM::NAILS);
    ui->listWidget_2->addItem(VGM_FORM::STAPLES);
    ui->listWidget_2->addItem(VGM_FORM::SAID_BARS);
    object_VGM = new VGM(DB);
    VGM_Form::set_image();
    count1 = count2 = 0;

    object_user = u;
    DB.SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    DB.GetUsers(cont);

    if (cont.size() == 0) {
        std::vector<QString> listColumns, listValue;
        listColumns.push_back("Name");
        listColumns.push_back("Platoon");
        listValue.push_back(object_user.GetName());
        listValue.push_back(object_user.GetPlatoon());
        DB.Insert("Student", listColumns, listValue);
    }

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

VGM_Form::~VGM_Form()
{
    DB.close();
    delete ui;
}

void VGM_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void VGM_Form::bar_cursor(QPen pen) {
    QPolygonF polygon;
    polygon << QPointF(270, 155) << QPointF(280, 145) << QPointF(290, 155);
    scene->addPolygon(polygon, pen);

    QPolygonF polygon2;
    polygon2 << QPointF(560, 155) << QPointF(550, 145) << QPointF(540, 155);
    scene->addPolygon(polygon2, pen);
}

void VGM_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(100, 155, 245, 110, pen);
    scene->addLine(700, 155, 580, 125, pen);
}

void VGM_Form::on_pushButton_clicked()
{
    DB.close();
    this->close();
    emit firstWindow();
}

void VGM_Form::on_pushButton_2_clicked()
{
    Default();
    form_VGM object_form;
    FillingFormVGM(object_form);
    form_answer_VGM object_answer = object_VGM->CheckAnswer(object_form);

    frame message;
    QString grade = YES_NO::EMPTY;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::VGM;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::VGM;
        scene->clear();
        set_image();
        grade = "Не склав";
    }
    DB.SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    DB.GetUsers(cont);
    DB.SELECT("id", "Equipment", "Name = '" + name + "'");

    std::vector<QString> listColumns, listValue;
    listColumns.push_back("Date");
    listColumns.push_back("Grade");
    listColumns.push_back("Student_id");
    listColumns.push_back("Equipment_id");
    listValue.push_back(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    listValue.push_back(grade);
    listValue.push_back(QString::number(cont.at(0).GetId()));
    listValue.push_back(QString::number(DB.GetEquipmentId()));
    DB.Insert("Test", listColumns, listValue);

    Message_Form *object = new Message_Form(message);
    object->show();
}

void VGM_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
}

void VGM_Form::FillingFormVGM(form_VGM &object_form) {
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

    object_form.weight = ui->lineEdit_5->text();
    object_form.width = ui->comboBox->currentText();
    if (ui->listWidget->currentRow() != -1) {
        object_form.nail_boards = ui->listWidget->currentItem()->text();
    }
    if (ui->listWidget_2->currentRow() != -1) {
        object_form.side_bar = ui->listWidget_2->currentItem()->text();
    }
}

void VGM_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
}

bool VGM_Form::CheckAnswer(form_answer_VGM form) {
    bool flag(true);

    if (!form.s) {
        ui->lineEdit->setStyleSheet(COLOR_EDIT::RED);
        ui->label_2->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_2->setStyleSheet(COLOR_EDIT::RED);
        ui->label_3->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (ui->lineEdit_5->text() == YES_NO::EMPTY) {
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        flag = false;

    } else {
        if (!form.t) {
            ui->lineEdit_3->setStyleSheet(COLOR_EDIT::RED);
            ui->label_4->setStyleSheet(COLOR_EDIT::RED);
            flag = false;
        }
    }
    if (!form.b) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    if (ui->listWidget->currentRow() == -1) {
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    } else {

        if (ui->listWidget->currentItem()->text() == VGM_FORM::STAPLES) {
            if (!form.st1) {
                ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
                ui->label_15->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
        }
        if (ui->listWidget->currentItem()->text() == VGM_FORM::NAILS) {
            if (!form.n1) {
                ui->lineEdit_16->setStyleSheet(COLOR_EDIT::RED);
                ui->label_21->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.nl1) {
                ui->lineEdit_17->setStyleSheet(COLOR_EDIT::RED);
                ui->label_22->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
        }
    }

    if (ui->listWidget_2->currentRow() == -1) {
        ui->label_7->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    } else {

        if (ui->listWidget_2->currentItem()->text() == VGM_FORM::STAPLES) {
            if (ui->comboBox->currentText() == YES_NO::EMPTY) {
                ui->label_16->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            } else {
                if (!form.st2) {
                    ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
                    ui->label_17->setStyleSheet(COLOR_EDIT::RED);
                    flag = false;
                }
            }
        }

        if (ui->listWidget_2->currentItem()->text() == VGM_FORM::SAID_BARS) {
            if (!form.st) {
                ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
                ui->label_25->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.sw) {
                ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
                ui->label_14->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.sl) {
                ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
                ui->label_26->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.sn) {
                ui->lineEdit_14->setStyleSheet(COLOR_EDIT::RED);
                ui->label_19->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.gap1) {
                ui->lineEdit_15->setStyleSheet(COLOR_EDIT::RED);
                ui->label_20->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
            if (!form.gap2) {
                ui->lineEdit_18->setStyleSheet(COLOR_EDIT::RED);
                ui->label_20->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
        }
    }

    return flag;
}

void VGM_Form::on_lineEdit_5_editingFinished() {
    object_VGM->SetWeight(ui->lineEdit_5->text().toDouble());
}

void VGM_Form::on_listWidget_currentTextChanged(const QString &currentText)
{
    if (currentText == VGM_FORM::STAPLES) {
        ui->groupBox_4->hide();
        ui->groupBox->show();
    }

    if (currentText == VGM_FORM::NAILS) {
        ui->groupBox->hide();
        ui->groupBox_4->show();
    }
    object_VGM->SetNailBoards(currentText);
}

void VGM_Form::on_listWidget_2_currentTextChanged(const QString &currentText)
{
    if (currentText == VGM_FORM::SAID_BARS) {
        ui->groupBox_2->hide();
        ui->groupBox_3->show();
    }

    if (currentText == VGM_FORM::STAPLES) {
        ui->groupBox_3->hide();
        ui->groupBox_2->show();
    }
    object_VGM->SetSideBar(currentText);
}

void VGM_Form::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    stretch_marks_cursor(green_pen());
    show_graphics();
    count1++;
}

void VGM_Form::on_lineEdit_editingFinished()
{
    for (unsigned int i = 0; i < count1; i++) {
        remove_last_item();
        remove_last_item();
    }
    stretch_marks_cursor(red_pen());
    show_graphics();
}

void VGM_Form::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    bar_cursor(green_pen());
    show_graphics();
    count2++;
}

void VGM_Form::on_lineEdit_4_editingFinished()
{
    for (unsigned int i = 0; i < count2; i++) {
        remove_last_item();
        remove_last_item();
    }
    bar_cursor(red_pen());
    show_graphics();
}
