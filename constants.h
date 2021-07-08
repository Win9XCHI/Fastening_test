#ifndef CONST_MESSAGE_H
#define CONST_MESSAGE_H
#include <QString>

namespace EQUIPMENT {
    const unsigned int EXCAVATOR = 0;
    const unsigned int BULLDOZER = 1;
    const unsigned int MOTORGRADER = 2;
    const unsigned int SCRAPER = 3;
    const unsigned int KRAZ_PL = 4;
    const unsigned int KRAZ = 5;
    const unsigned int VGM = 6;
}

namespace EQUIPMENT_NAME {
    const QString EXCAVATOR = "Екскаватор ЕО-4125 на платформі";
    const QString BULLDOZER = "Бульдозер Д-686 на платформі";
    const QString MOTORGRADER = "Автогрейдер ДЗ-98 на платформі";
    const QString SCRAPER = "Скрепер Д-357П на платформі";
    const QString KRAZ_PL = "КрАЗ-256 порожній на платформі";
    const QString KRAZ = "КрАЗ-256 порожній над зчепом";
    const QString VGM = "Танк";
}

namespace MESSAGE {
    const QString FAIL = "Тест закінчено, ви НЕ СКЛАЛИ тест. Помилки вказані червоним кольором.";
    const QString SUCCESS = "Тест закінчено, ви СКЛАЛИ тест.";

    const QString PREPARATION = "Для підготовки рекомендується використати:";
    const QString EXCAVATOR = "Техническое описание и инструкция по эксплуатации Эо-4125 Экскаватор\nполноповоротный одноковшовый универсальный гидравлический гусеничный\n4125.00.00.0000 ТО В/О 'Машиноэкспорт' 134-135.\nНаставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 83-84.";
    const QString BULLDOZER = "Размещение и крепление техники на железнодорожных платформах Справочник.\nНаставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 83-84.";
    const QString MOTORGRADER = "Наставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 100, 104-105.\nРазмещение и крепление техники на железнодорожных платформах Справочник, стр. 83-84.";
    const QString SCRAPER = "Наставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 100, 104-105.\nРазмещение и крепление техники на железнодорожных платформах Справочник, стр. 90.";
    const QString KRAZ_PL = "Наставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 100, 104-105.\nРазмещение и крепление техники на железнодорожных платформах Справочник, стр. 90.";
    const QString KRAZ = "Наставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 100, 104-105.\nРазмещение и крепление техники на железнодорожных платформах Справочник, стр. 90.";
    const QString VGM = "Наставление по перевозкам войск Приложение 6 и 15 к наставлению, стр. 83-84.";
}

namespace PATHS {
    const QString RESOURCES = "resources/";
    const QString DB = "DB_for_test.db";
}

namespace YES_NO {
    const QString EMPTY = "";
    const QString YES = "Так";
    const QString NO = "Ні";
}

namespace COLOR_EDIT {
    const QString RED = "color: rgb(200, 0, 0)";
    const QString BLACK = "color: rgb(0, 0, 0)";
}

namespace BULLDOZER_FORM {
    namespace WEIGHT {
        const QString T15 = "До 15 т.";
        const QString T25 = "Від 15.1 до 25 т.";
        const QString T50 = "Від 25.1 до 50 т.";
    }

    namespace WIDTH_TRACK {
        const QString LESS400 = "Менше 400 мм.";
        const QString MORE400 = "400 мм. і більше";
    }

    const QString STAPLES = "Будівельні скоби";
    const QString NAILS = "Цвяхи";
    const QString SAID_BARS = "Бокові бруски";
}

namespace VGM_FORM {
    namespace WEIGHT {
        const QString T15 = "До 15 т.";
        const QString T25 = "Від 15.1 до 25 т.";
        const QString T50 = "Від 25.1 до 50 т.";
    }

    namespace WIDTH_TRACK {
        const QString LESS400 = "Менше 400 мм.";
        const QString MORE400 = "400 мм. і більше";
    }

    const QString STAPLES = "Будівельні скоби";
    const QString NAILS = "Цвяхи";
    const QString SAID_BARS = "Бокові бруски";
}

#endif // CONST_MESSAGE_H
