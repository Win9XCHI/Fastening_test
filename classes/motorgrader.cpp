#include "motorgrader.h"

MotorGrader::MotorGrader(MotorGraderDB db) {
    name = "Автогрейдер ДЗ-98 на платформі";
    std::map<QString, QString> cont;
    std::map<QString, Dimensions> contD;
    DB = db;

    Quiry(cont, contD);
    Filling(cont, contD);
}

MotorGrader::~MotorGrader() {}

void MotorGrader::Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Yn.Answer, Cha.Name", "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetYesNoValue(cont);
}

void MotorGrader::Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки розтяжок потрібно для кріплення автогрейдера"].toUInt(), cont["Скільки ниток в розтяжці (47)"].toUInt()}});

    mas_bar.insert({"thrust", {cont["Скільки упорних брусків потрібно для кріплення автогрейдера"].toUInt(), cont["Скільки цвяхів потрібно для закріплення кожного бруска"].toUInt()}});

    wire_diameter = cont["Якого діаметру повинен бути дріт (мм)"].toUInt();

    if (cont["Чи потрібна підкладка під ніж відвалу"] == "Так") {
        mas_lining.insert({"dump", {true, contD["Розміри підкладки під ніж відвалу (мм)"], cont["Кількість цвяхів на підкладку (44)"].toUInt()}});
    }
    if (cont["Чи потрібна підкладка під ніж корчувача"] == "Так") {
        mas_lining.insert({"grubber", {true, contD["Розміри підкладки під ніж корчувача (мм)"], cont["Кількість цвяхів на підкладку (41)"].toUInt()}});
    }
}

form_answer_motorgrader MotorGrader::CheckAnswer(form_motorgrader form) {
    form_answer_motorgrader object;

    if (form.s != mas_stretching["stretch"].GetCount()) {
        object.s = false;
    }
    if (form.t != mas_stretching["stretch"].GetThread()) {
        object.t = false;
    }

    if (form.b != mas_bar["thrust"].GetCount()) {
        object.b = false;
    }
    if (form.n != mas_bar["thrust"].GetNails()) {
        object.n = false;
    }

    if (form.wd != wire_diameter) {
        object.wd = false;
    }

    if (form.li1 != mas_lining["dump"].GetYesNo()) {
        object.li1 = false;
    }
    if (form.nli1 != mas_lining["dump"].GetNails()) {
        object.nli1 = false;
    }
    if (form.t1 != mas_lining["dump"].GetDimensions().GetThickness()) {
        object.t1 = false;
    }
    if (form.w1 != mas_lining["dump"].GetDimensions().GetWidth()) {
        object.w1 = false;
    }
    if (form.l1 != mas_lining["dump"].GetDimensions().GetLength()) {
        object.l1 = false;
    }

    if (form.li2 != mas_lining["grubber"].GetYesNo()) {
        object.li2 = false;
    }
    if (form.nli2 != mas_lining["grubber"].GetNails()) {
        object.nli2 = false;
    }
    if (form.t2 != mas_lining["grubber"].GetDimensions().GetThickness()) {
        object.t2 = false;
    }
    if (form.w2 != mas_lining["grubber"].GetDimensions().GetWidth()) {
        object.w2 = false;
    }
    if (form.l2 != mas_lining["grubber"].GetDimensions().GetLength()) {
        object.l2 = false;
    }

    return object;
}
