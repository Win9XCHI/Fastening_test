#include "bulldozer_form.h"
#include "ui_bulldozer_form.h"

Bulldozer_Form::Bulldozer_Form(BulldozerDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bulldozer_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    count = 0;
    name = EQUIPMENT_NAME::BULLDOZER;
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem(YES_NO::NO);
    ui->comboBox->addItem(YES_NO::YES);
    ui->comboBox_2->addItem(YES_NO::EMPTY);
    ui->comboBox_2->addItem(BULLDOZER_FORM::WEIGHT::T15);
    ui->comboBox_2->addItem(BULLDOZER_FORM::WEIGHT::T25);
    ui->comboBox_2->addItem(BULLDOZER_FORM::WEIGHT::T50);
    ui->comboBox_3->addItem(YES_NO::EMPTY);
    ui->comboBox_3->addItem(BULLDOZER_FORM::WIDTH_TRACK::LESS400);
    ui->comboBox_3->addItem(BULLDOZER_FORM::WIDTH_TRACK::MORE400);
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->groupBox_4->hide();
    ui->listWidget->addItem(BULLDOZER_FORM::STAPLES);
    ui->listWidget->addItem(BULLDOZER_FORM::NAILS);
    ui->listWidget_2->addItem(BULLDOZER_FORM::STAPLES);
    ui->listWidget_2->addItem(BULLDOZER_FORM::SAID_BARS);
    object_bulldozer = new Bulldozer(db);
    Bulldozer_Form::set_image();

    object_user = u;
    object_bulldozer->GetDB()->SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

Bulldozer_Form::~Bulldozer_Form()
{
    object_bulldozer->GetDB()->close();
    delete ui;
    delete object_bulldozer;
    delete scene;
}

/* Showing graphics
 * Input: -
 * Output: - */
void Bulldozer_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

/* Functions with graphics
 * Input: pen
 * Output: - */
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

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void Bulldozer_Form::on_pushButton_clicked()
{
    emit firstWindow();
    this->~Bulldozer_Form();
}

/* Pressing "Done" button
 * Input: -
 * Output: - */
void Bulldozer_Form::on_pushButton_2_clicked()
{
    Default();
    form_bulldozer object_form;
    FillingFormBulldozer(object_form);
    form_answer_bulldozer object_answer = object_bulldozer->CheckAnswer(object_form);

    frame message;
    QString grade = YES_NO::EMPTY;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        scene->clear();
        set_image();
        grade = "Не склав";
    }
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::BULLDOZER;
    object_bulldozer->GetDB()->SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

/* Set up image in the form
 * Input: -
 * Output: - */
void Bulldozer_Form::set_image() {
    object_bulldozer->GetDB()->SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + object_bulldozer->GetDB()->GetIcon());
    show_graphics();
}

/* Filling а structure from form`s items
 * Input: structure
 * Output: - */
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

    ui->comboBox->currentText() == YES_NO::YES ? object_form.l = true : object_form.l = false;
    object_form.weight = ui->comboBox_2->currentText();
    object_form.width = ui->comboBox_3->currentText();
    if (ui->listWidget->currentRow() != -1) {
        object_form.nail_boards = ui->listWidget->currentItem()->text();
    }
    if (ui->listWidget_2->currentRow() != -1) {
        object_form.side_bar = ui->listWidget_2->currentItem()->text();
    }
}

/* Doing items` color are black
 * Input: -
 * Output: - */
void Bulldozer_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    ui->comboBox->setStyleSheet(COLOR_EDIT::BLACK);
}

/* Cheking logical structure
 * Input: structure
 * Output: - */
bool Bulldozer_Form::CheckAnswer(form_answer_bulldozer form) {
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
    if (!form.weight) {
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

    if (ui->listWidget->currentRow() == -1 || !form.nail_boards) {
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    } else {

        if (ui->listWidget->currentItem()->text() == BULLDOZER_FORM::STAPLES) {
            if (!form.st1) {
                ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
                ui->label_15->setStyleSheet(COLOR_EDIT::RED);
                flag = false;
            }
        }
        if (ui->listWidget->currentItem()->text() == BULLDOZER_FORM::NAILS) {
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

    if (!form.side_bar) {
        ui->label_7->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    } else {
        if (ui->listWidget_2->currentRow() != -1 && ui->listWidget_2->currentItem()->text() == BULLDOZER_FORM::STAPLES) {

            if (ui->comboBox_3->currentText() == YES_NO::EMPTY) {
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

        if (ui->listWidget_2->currentRow() != -1 && ui->listWidget_2->currentItem()->text() == BULLDOZER_FORM::SAID_BARS) {
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


    if (!form.l) {
        ui->label_8->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.ln) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_13->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.lt) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_10->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.lw) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.ll) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    return flag;
}

/* Clear lineEdits
 * Input: -
 * Output: - */
void Bulldozer_Form::clear_staples_nails() {
    ui->lineEdit_9->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
}

void Bulldozer_Form::clear_staples_sideBars() {
    ui->comboBox_3->setCurrentIndex(0);
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_18->setText("");
}

void Bulldozer_Form::on_listWidget_currentTextChanged(const QString &currentText) {

    if (currentText == "") {
        ui->groupBox_4->hide();
        ui->groupBox->hide();
    }

    if (currentText == BULLDOZER_FORM::STAPLES) {
        ui->groupBox_4->hide();
        ui->groupBox->show();
    }

    if (currentText == BULLDOZER_FORM::NAILS) {
        ui->groupBox->hide();
        ui->groupBox_4->show();
    }
    clear_staples_nails();
    object_bulldozer->SetNailBoards(currentText);
}

void Bulldozer_Form::on_listWidget_2_currentTextChanged(const QString &currentText) {

    if (currentText == "") {
        ui->groupBox_2->hide();
        ui->groupBox_3->hide();
    }

    if (currentText == BULLDOZER_FORM::SAID_BARS) {
        ui->groupBox_2->hide();
        ui->groupBox_3->show();
        bar_side_cursor(red_pen());
    }

    if (currentText == BULLDOZER_FORM::STAPLES) {
        ui->groupBox_3->hide();
        ui->groupBox_2->show();
    }
    clear_staples_sideBars();
    object_bulldozer->SetSideBar(currentText);
}

void Bulldozer_Form::on_comboBox_2_activated(const QString &arg1) {
    object_bulldozer->SetWeight(arg1);
    clear_staples_nails();
    clear_staples_sideBars();
    ui->listWidget->setCurrentRow(-1);
    ui->listWidget_2->setCurrentRow(-1);
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
