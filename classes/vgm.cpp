#include "vgm.h"

VGM::VGM(VGM_DB db) : staple(0) {
    name = "Танк";
    std::map<QString, QString> cont;
    DB = db;
    weight = "";

    Quiry(cont);
    Filling(cont);
}

VGM::~VGM() {}

void VGM::Quiry(std::map<QString, QString> &cont) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL AND Con.Conditions_id IS NULL AND Cha.Name != 'Вага ВГМ'");
    DB.GetValue(cont);
}

void VGM::Filling(std::map<QString, QString> cont) {
    mas_stretching.insert({"stretch", {cont["розтяжек  по"].toUInt(), 0, 0}});
    mas_bar.insert({"thrust", {cont["упорних брусків"].toUInt()}});
    staple = cont["скоб від поперечного зміщення"].toUInt();
}

void VGM::SetWeight(double number) {
    QString string("");

    if (number <= 0 || number > 50) {
        weight = "";
        return;
    }
    if (number > 0 && number < 15.1) {
        string = "До 15 т.";
    }
    if (number > 15 && number < 25.1) {
        string = "Від 15.1 до 25 т.";
    }
    if (number > 25 && number <= 50) {
        string = "Від 25.1 до 50 т.";
    }

    mas_stretching["stretch"].SetThread(0);
    mas_bar["thrust"].SetNails(0);
    mas_bar["thrust"].SetStaple(0);
    weight = string;
    std::map<QString, QString> cont;
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "')");
    DB.GetValue(cont);
    mas_stretching["stretch"].SetThread(cont["нитки"].toUInt());
    mas_bar["thrust"].SetNails(cont["цвяхів в один упорний брусок"].toUInt());
    mas_bar["thrust"].SetStaple(cont["скоб в один брусок"].toUInt());
}

form_answer_VGM VGM::CheckAnswer(form_VGM form) {
    form_answer_VGM object;

    if (form.s != mas_stretching["stretch"].GetCount()) {
        object.s = false;
    }
    if (form.t != mas_stretching["stretch"].GetThread()) {
        object.t = false;
    }
    if (form.b != mas_bar["thrust"].GetCount()) {
        object.b = false;
    }
    if (form.st1 != mas_bar["thrust"].GetStaple()) {
        object.st1 = false;
    }
    if (form.n != mas_bar["thrust"].GetNails()) {
        object.n = false;
    }
    if (form.st2 != staple) {
        object.st2 = false;
    }
    if (weight == "") {
        object.weight = false;
    }

    return object;
}
