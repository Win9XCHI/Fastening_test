#include "bulldozer.h"

Bulldozer::Bulldozer(BulldozerDB db) {
    name = "Бульдозер на платформі";
    std::map<QString, QString> cont;
    std::map<QString, Dimensions> contD;
    DB = db;
    weight = nail_boards = side_bar = "";
    width_trackYesNo = false;

    Quiry(cont, contD);
    Filling(cont, contD);
}

Bulldozer::~Bulldozer() {}

void Bulldozer::Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL AND Con.Conditions_id IS NULL AND Cha.Name != 'Вага бульдозера'");
    DB.GetValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Yn.Answer, Cha.Name", "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetYesNoValue(cont);
}

void Bulldozer::Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки буде використано розтяжок"].toUInt(), 0, cont["Дріт якого діаметру треба застосувати"].toUInt()}});
    mas_bar.insert({"thrust", {cont["Скільки упорних брусків треба використати"].toUInt()}});
    bool flag(false);
    if (cont["Чи потрібна дерев'яна підкладки під ніж бульдозера"] == "Так") {
        flag = true;
    }
    mas_lining.insert({"lining", {flag, contD["Розміри підкладки під ніж бульдозера (мм)"], cont["Кількість цвяхів на підкладку"].toUInt()}});
}

void Bulldozer::ClearNailBoards() {
    nail_boards = "";
    mas_bar["thrust"].SetStaple(0);
    mas_bar["thrust"].SetNails(0);
    mas_bar["thrust"].SetLengthNail(0);
}

void Bulldozer::ClearSideBar() {
    side_bar = "";
    width_trackYesNo = false;
    if (mas_bar.find("side") != mas_bar.cend()) {
        mas_bar.erase(mas_bar.find("side"));
    }
}

void Bulldozer::SetWeight(QString string) {
    ClearNailBoards();
    ClearSideBar();
    weight = string;
    std::map<QString, QString> cont;
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Cha.Name != 'Чим будуть прибивати бруски до платформи' AND Cha.Name != 'Чим будете кріпити бульдозер від поперечного зміщення при відкритих бортах платформи' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "')");
    DB.GetValue(cont);
    mas_stretching["stretch"].SetThread(cont["Скільки ниток в кожній розтяжці"].toUInt());
}

void Bulldozer::SetNailBoards(QString string) {
    ClearNailBoards();
    nail_boards = string;
    string = "Чим будуть прибивати бруски до платформи";
    std::map<QString, QString> cont;
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + nail_boards + "' AND Cha.Name = '" + string + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "'))");
    DB.GetValue(cont);

    if (nail_boards == "Будівельні скоби") {
        mas_bar["thrust"].SetStaple(cont["Скільки скоб треба застосувати для кріплення одного бруска"].toUInt());
    } else {
        mas_bar["thrust"].SetNails(cont["Скільки цвяхів треба застосувати для кріплення одного бруска?"].toUInt());
        mas_bar["thrust"].SetLengthNail(cont["Якої довжини мають бути цвяхи?"].toUInt());
    }
}

void Bulldozer::SetSideBar(QString string) {
    ClearSideBar();
    side_bar = string;
    string = "Чим будете кріпити бульдозер від поперечного зміщення при відкритих бортах платформи";
    std::map<QString, QString> cont;
    std::map<QString, FromTo> contFT;
    std::map<QString, Dimensions> contD;
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + side_bar + "' AND Cha.Name = '" + string + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "'))");
    DB.GetValue(cont);

    if (side_bar == "Бокові бруски") {
        DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name",
                  "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + side_bar + "' AND Cha.Name = '" + string + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "'))");
        DB.GetDimensionsValue(contD);

        DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name",
                  "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + side_bar + "' AND Cha.Name = '" + string + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "'));");
        DB.GetFromToValue(contFT);

        mas_bar.insert({"side", {2, contD["Який розмір бокових брусків (мм)"], cont["Скільки цвяхів потрібно забити в кожний брусок"].toUInt()}});
        mas_fromto.insert({"gap", {contFT["Який зазор між боковим бруском та гусеницею (мм)"]}});

    } else {
        width_trackYesNo = true;
    }
}

void Bulldozer::SetWidthTrack(QString string) {
    if (width_trackYesNo) {
        width_track = string;
        std::map<QString, QString> cont;
        DB.SELECT("Con.Value, Cha.Name",
                  "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + width_track + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + side_bar + "' AND Cha.Name = 'Чим будете кріпити бульдозер від поперечного зміщення при відкритих бортах платформи' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + name + "' AND Con.Value = '" + weight + "')))");
        DB.GetValue(cont);
        mas_bar.insert({"side", {2, 0, 0, cont["Скільки будівельних скоб потрібно для закріплення"].toUInt()}});
    }
}

form_answer_bulldozer Bulldozer::CheckAnswer(form_bulldozer form) {
    form_answer_bulldozer object;

    if (form.s != mas_stretching["stretch"].GetCount()) {
        object.s = false;
    }
    if (form.wd != mas_stretching["stretch"].GetWireDiameter()) {
        object.wd = false;
    }
    if (form.t != mas_stretching["stretch"].GetThread()) {
        object.t = false;
    }
    if (form.b != mas_bar["thrust"].GetCount()) {
        object.b = false;
    }
    if (form.l != mas_lining["lining"].GetYesNo()) {
        object.l = false;
    }
    if (form.ln != mas_lining["lining"].GetNails()) {
        object.ln = false;
    }
    if (form.lt != mas_lining["lining"].GetDimensions().GetThickness()) {
        object.lt = false;
    }
    if (form.lw != mas_lining["lining"].GetDimensions().GetWidth()) {
        object.lw = false;
    }
    if (form.ll != mas_lining["lining"].GetDimensions().GetLength()) {
        object.ll = false;
    }

    if (nail_boards  == "Будівельні скоби") {
        if (form.st1 != mas_bar["thrust"].GetStaple()) {
            object.st1 = false;
        }
    }
    if (nail_boards == "Цвяхи") {
        if (form.n1 != mas_bar["thrust"].GetNails()) {
            object.n1 = false;
        }
        if (form.nl1 != mas_bar["thrust"].GetLengthNail()) {
            object.nl1 = false;
        }
    }

    if (side_bar == "Бокові бруски") {
        if (form.sn != mas_bar["side"].GetNails()) {
            object.sn = false;
        }
        if (form.st != mas_bar["side"].GetDimensions().GetThickness()) {
            object.st = false;
        }
        if (form.sw != mas_bar["side"].GetDimensions().GetWidth()) {
            object.sw = false;
        }
        if (form.sl != mas_bar["side"].GetDimensions().GetLength()) {
            object.sl = false;
        }
        if (form.gap1 != mas_fromto["gap"].GetFrom()) {
            object.gap1 = false;
        }
        if (form.gap2 != mas_fromto["gap"].GetTo()) {
            object.gap2 = false;
        }
    }

    if (side_bar == "Будівельні скоби") {
        if (form.st2 != mas_bar["side"].GetStaple()) {
            object.st2 = false;
        }
    }

    return object;
}
