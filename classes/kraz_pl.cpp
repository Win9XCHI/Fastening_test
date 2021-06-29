#include "kraz_pl.h"

KRAZ_pl::KRAZ_pl(KRAZ_pl_DB db) {
    name = "КрАЗ-256 порожній на платформі";
    std::map<QString, QString> cont;
    std::map<QString, FromTo> contFT;
    std::map<QString, Dimensions> contD;
    DB = db;

    Quiry(cont, contFT, contD);
    Filling(cont, contFT, contD);
}

KRAZ_pl::~KRAZ_pl() {}

void KRAZ_pl::Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name", "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetFromToValue(contFT);
}

void KRAZ_pl::Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки розтяжок потрібно використати"].toUInt(), cont["Скільки ниток в розтяжці (51)"].toUInt(), cont["Якого діаметру розтяжки потрібно використати (мм)"].toUInt()}});
    mas_bar.insert({"thrust", {cont["Скільки потрібно використати упорних брусків"].toUInt(), contD["Які потрібні розміри упорних брусків (мм)"], cont["Скільки цвяхів (150 мм) на брусок"].toUInt()}});
    mas_fromto.insert({"kg/pog", contFT["Які витрати проволоки (кг/пог.м))"]});
}

form_answer_KRAZ_pl KRAZ_pl::CheckAnswer(form_KRAZ_pl form) {
    form_answer_KRAZ_pl object;

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
    if (form.t1 != mas_bar["thrust"].GetDimensions().GetThickness()) {
        object.t1 = false;
    }
    if (form.w1 != mas_bar["thrust"].GetDimensions().GetWidth()) {
        object.w1 = false;
    }
    if (form.l1 != mas_bar["thrust"].GetDimensions().GetLength()) {
        object.l1 = false;
    }
    if (form.kg != mas_fromto["kg/pog"].GetFrom()) {
        object.kg = false;
    }
    if (form.pog != mas_fromto["kg/pog"].GetTo()) {
        object.pog = false;
    }

    return object;
}
