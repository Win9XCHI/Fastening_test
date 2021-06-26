#include "excavator.h"

Excavator::Excavator(ExcavatorDB db) {
    name = "Екскаватор ЕО-4125 на платформі";
    std::map<QString, QString> cont;
    std::map<QString, FromTo> contFT;
    DB = db;

    Quiry(cont, contFT);
    Filling(cont, contFT);
}

Excavator::~Excavator() {
    if (object_lining != nullptr) {
        delete object_lining;
    }
}

void Excavator::Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name", "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetFromToValue(contFT);

    DB.SELECT("Yn.Answer, Cha.Name", "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetYesNoValue(cont);
}

void Excavator::Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT) {
    mas_stretching.insert({"swivel platform", {cont["Скільки розтяжок потрібно для кріплення поворотної платформи"].toUInt(), cont["Скільки ниток в розтяжці (2)"].toUInt()}});
    mas_stretching.insert({"chassis", {cont["Скільки розтяжок потрібно для кріплення ходової частини"].toUInt(), cont["Скільки ниток в розтяжці (4)"].toUInt()}});
    mas_stretching.insert({"arrow root", {cont["Скільки розтяжок потрібно для кріплення корня стріли"].toUInt(), cont["Скільки ниток в розтяжці (6)"].toUInt()}});
    mas_stretching.insert({"arrow handle", {cont["Скільки розтяжок потрібно для кріплення рукояті стріли"].toUInt(), cont["Скільки ниток в розтяжці (8)"].toUInt()}});
    mas_stretching.insert({"caterpillar trolley", {cont["Скільки розтяжок потрібно для кріплення гусенічного візка"].toUInt(), cont["Скільки ниток в розтяжці (10)"].toUInt()}});

    mas_bar.insert({"thrust", {cont["Скільки потрібно упорних брусків"].toUInt(), cont["Скільки потрібно цвяхів в кожний брусок (13)"].toUInt()}});
    mas_bar.insert({"side", {cont["Скільки потрібно бічних брусків від поперечного зміщення при відкритих ботах платформи"].toUInt(), cont["Скільки потрібно цвяхів в кожний брусок (15)"].toUInt()}});

    mas_fromto.insert({"gap", contFT["Який зазор повинен бути між гусеницями і боковими брусками (мм)? від"]});

    wire_diameter = cont["Якого діаметру треба застосувати проволоку (мм)"].toUInt();
    boom_height = cont["Після опускання стріли відстань між полом платформи та верхньою точкою стріли не повинна перевищувати ... (м)"].toUInt();
    axis_turnover = cont["На скільки потрібно змістити вісь обертання ексковатора від середини платформи назад (м)"].toDouble();
    axis_longitudinal = cont["На скільки повинна бути зміщена повздовжня вісь ексковатора відносно вісі платформи вправо (м)"].toDouble();

    bool flag(false);
    if (cont["Чи потрібна дерев'яна підкладка під ковш"] == "Так") {
        flag = true;
    }
    object_lining = new Lining(flag);
}

form_answer_excavator Excavator::CheckAnswer(form_excavator form) {
    form_answer_excavator object;

    if (form.s1 != mas_stretching["swivel platform"].GetCount()) {
        object.s1 = false;
    }
    if (form.t1 != mas_stretching["swivel platform"].GetThread()) {
        object.t1 = false;
    }
    if (form.s2 != mas_stretching["chassis"].GetCount()) {
        object.s2 = false;
    }
    if (form.t2 != mas_stretching["chassis"].GetThread()) {
        object.t2 = false;
    }
    if (form.s3 != mas_stretching["arrow root"].GetCount()) {
        object.s3 = false;
    }
    if (form.t3 != mas_stretching["arrow root"].GetThread()) {
        object.t3 = false;
    }
    if (form.s4 != mas_stretching["arrow handle"].GetCount()) {
        object.s4 = false;
    }
    if (form.t4 != mas_stretching["arrow handle"].GetThread()) {
        object.t4 = false;
    }
    if (form.s5 != mas_stretching["caterpillar trolley"].GetCount()) {
        object.s5 = false;
    }
    if (form.t5 != mas_stretching["caterpillar trolley"].GetThread()) {
        object.t5 = false;
    }

    if (form.gb1 != mas_fromto["gap"].GetFrom()) {
        object.gb1 = false;
    }
    if (form.gb2 != mas_fromto["gap"].GetTo()) {
        object.gb2 = false;
    }

    if (form.b1 != mas_bar["thrust"].GetCount()) {
        object.b1 = false;
    }
    if (form.n1 != mas_bar["thrust"].GetNails()) {
        object.n1 = false;
    }
    if (form.b2 != mas_bar["side"].GetCount()) {
        object.b2 = false;
    }
    if (form.n2 != mas_bar["side"].GetNails()) {
        object.n2 = false;
    }

    if (form.wd != wire_diameter) {
        object.wd = false;
    }
    if (form.at != axis_turnover) {
        object.at = false;
    }
    if (form.al != axis_longitudinal) {
        object.al = false;
    }
    if (form.l != object_lining->GetYesNo()) {
        object.l = false;
    }
    if (form.bh != boom_height) {
        object.bh = false;
    }

    return object;
}
