#include "motorgrader.h"

MotorGrader::MotorGrader(MotorGraderDB db) {
    name = EQUIPMENT_NAME::MOTORGRADER;
    std::map<QString, QString> cont;
    std::map<QString, Dimensions> contD;
    DB = db;

    Quiry(cont, contD);
    Filling(cont, contD);
}

MotorGrader::~MotorGrader() {}

MotorGraderDB* MotorGrader::GetDB() {
    return &DB;
}

/* Execute queries to database
 * Input: containers for answer
 * Output: - */
void MotorGrader::Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Yn.Answer, Cha.Name", "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetYesNoValue(cont);
}

/* Filling class`s variables
 * Input: containers with data from database
 * Output: - */
void MotorGrader::Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки розтяжок потрібно для кріплення автогрейдера"].toUInt(), cont["Скільки ниток в розтяжці (47)"].toUInt(), cont["Якого діаметру повинен бути дріт (мм)"].toUInt()}});

    mas_bar.insert({"thrust", {cont["Скільки упорних брусків потрібно для кріплення автогрейдера"].toUInt(), cont["Скільки цвяхів потрібно для закріплення кожного бруска"].toUInt()}});

    bool flag1(false), flag2(false);
    if (cont["Чи потрібна підкладка під ніж відвалу"] == YES_NO::YES) {
        flag1 = true;
    }
    mas_lining.insert({"dump", {flag1, contD["Розміри підкладки під ніж відвалу (мм)"], cont["Кількість цвяхів на підкладку під ніж відвалу"].toUInt()}});

    if (cont["Чи потрібна підкладка під ніж корчувача"] == YES_NO::YES) {
        flag2 = true;
    }
    mas_lining.insert({"grubber", {flag2, contD["Розміри підкладки під ніж корчувача (мм)"], cont["Кількість цвяхів на підкладку під ніж корчувача"].toUInt()}});
}

/* Check answer from form and data from database
 * Input: structure with data from form
 * Output: logical structure with data about true each variables */
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

    if (form.wd != mas_stretching["stretch"].GetWireDiameter()) {
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
