#include "kraz.h"

KRAZ::KRAZ(KRAZ_DB db) {
    name = EQUIPMENT_NAME::KRAZ;
    std::map<QString, QString> cont;
    std::map<QString, FromTo> contFT;
    std::map<QString, Dimensions> contD;
    DB = db;

    Quiry(cont, contFT, contD);
    Filling(cont, contFT, contD);
}

KRAZ::~KRAZ() {}

void KRAZ::Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name", "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetFromToValue(contFT);
}

void KRAZ::Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки розтяжок потрібно використати"].toUInt(), cont["Скільки ниток у розтяжці (60)"].toUInt(), cont["Якого діаметру розтяжки потрібно використати"].toUInt()}});
    mas_bar.insert({"thrust", {cont["Скільки потрібно використати упорних брусків"].toUInt(), contD["Які потрібні розміри упорних брусків (мм)"], static_cast<unsigned int>(contFT["Скільки цвяхів (150 мм) на брусок"].GetFrom())}});
    mas_bar.insert({"side", {cont["Скільки потрібно використати бокових брусків"].toUInt(), contD["Які потрібні розміри бокових брусків"], static_cast<unsigned int>(contFT["Скільки цвяхів (150 мм) на брусок"].GetTo())}});
    mas_fromto.insert({"kg/pog", contFT["Які витрати проволоки (кг/пог.м)"]});
    mas_fromto.insert({"distance", contFT["Яка відстань між боковим бруском і покришкою"]});
}

form_answer_KRAZ KRAZ::CheckAnswer(form_KRAZ form) {
    form_answer_KRAZ object;

    if (form.s != mas_stretching["stretch"].GetCount()) {
        object.s = false;
    }
    if (form.t != mas_stretching["stretch"].GetThread()) {
        object.t = false;
    }
    if (form.wd != mas_stretching["stretch"].GetWireDiameter()) {
        object.wd = false;
    }
    if (form.b1 != mas_bar["thrust"].GetCount()) {
        object.b1 = false;
    }
    if (form.n1 != mas_bar["thrust"].GetNails()) {
        object.n1 = false;
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
    if (form.b2 != mas_bar["side"].GetCount()) {
        object.b2 = false;
    }
    if (form.n2 != mas_bar["side"].GetNails()) {
        object.n2 = false;
    }
    if (form.t2 != mas_bar["side"].GetDimensions().GetThickness()) {
        object.t2 = false;
    }
    if (form.w2 != mas_bar["side"].GetDimensions().GetWidth()) {
        object.w2 = false;
    }
    if (form.l2 != mas_bar["side"].GetDimensions().GetLength()) {
        object.l2 = false;
    }
    if (form.kg != mas_fromto["kg/pog"].GetFrom()) {
        object.kg = false;
    }
    if (form.pog != mas_fromto["kg/pog"].GetTo()) {
        object.pog = false;
    }
    if (form.distance1 != mas_fromto["distance"].GetFrom()) {
        object.distance1 = false;
    }
    if (form.distance2 != mas_fromto["distance"].GetTo()) {
        object.distance2 = false;
    }

    return object;
}
