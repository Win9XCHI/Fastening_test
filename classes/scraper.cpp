#include "scraper.h"

Scraper::Scraper(ScraperDB db) {
    name = "Скрепер Д-357П на платформі";
    std::map<QString, QString> cont;
    std::map<QString, Dimensions> contD;
    DB = db;

    Quiry(cont, contD);
    Filling(cont, contD);
}

Scraper::~Scraper() {}

void Scraper::Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD) {
    DB.SELECT("Con.Value, Cha.Name", "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "' AND Con.Value NOT NULL");
    DB.GetGeneralValue(cont);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name", "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Yn.Answer, Cha.Name", "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + name + "'");
    DB.GetYesNoValue(cont);
}

void Scraper::Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD) {
    mas_stretching.insert({"stretch", {cont["Скільки розтяжок потрібно для кріплення скрепера"].toUInt(), cont["Скільки ниток в розтяжці (75)"].toUInt(), cont["Якого діаметру повинен бути дріт (мм)"].toUInt()}});

    mas_bar.insert({"thrust", {cont["Скільки упорних брусків потрібно для кріплення скрепера"].toUInt(), cont["Скільки цвяхів потрібно для закріплення кожного бруска"].toUInt()}});
    mas_bar.insert({"side", {cont["Скільки потрібно бічних брусків від поперечного зміщення при відкритих бортах платформи"].toUInt(), contD["Розміри бічних брусків (мм):"], cont["Кількість цвяхів на брусок"].toUInt()}});

    bool flag(false);
    if (cont["Чи потрібна підкладка під ніж скрепера"] == "Так") {
        flag = true;
    }
    mas_lining.insert({"dump", {flag, contD["Розміри підкладки під ніж скрепера (мм):"], cont["Кількість цвяхів на підкладку (69)"].toUInt()}});
}

form_answer_scraper Scraper::CheckAnswer(form_scraper form) {
    form_answer_scraper object;

    if (form.s != mas_stretching["stretch"].GetCount()) {
        object.s = false;
    }
    if (form.t != mas_stretching["stretch"].GetThread()) {
        object.t = false;
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
    if (form.t2 != mas_bar["side"].GetDimensions().GetThickness()) {
        object.t2 = false;
    }
    if (form.w2 != mas_bar["side"].GetDimensions().GetWidth()) {
        object.w2 = false;
    }
    if (form.l2 != mas_bar["side"].GetDimensions().GetLength()) {
        object.l2 = false;
    }

    if (form.wd != mas_stretching["stretch"].GetWireDiameter()) {
        object.wd = false;
    }

    if (form.li != mas_lining["dump"].GetYesNo()) {
        object.li = false;
    }
    if (form.nli != mas_lining["dump"].GetNails()) {
        object.nli = false;
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

    return object;
}
