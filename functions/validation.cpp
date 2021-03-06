#include "validation.h"

/* Split string on words
 * Input: string, container for words hold, key for split
 * Output: - */
template <class Container>
void Validation::split(const std::string& str, Container& cont, char delim) {
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

/* Check "ПІБ" string
 * Input: string "ПІБ" from main window
 * Output: correct or not */
bool Validation::CheckPIB(QString pib) {
    std::vector<std::string> str;
    Validation::split(pib.toStdString(), str);

    if (str.size() > 100) {
        return false;
    }

    if (str.size() != 3) {
        return false;
    }

    if (pib.contains(QRegularExpression("[^-А-Яа-яіїІЇЄє \f\n\r\t\v]"))) {
        return false;
    }

    return true;
}

/* Check "Взвод" string
 * Input: string "Взвод" from main window
 * Output: correct or not */
bool Validation::CheckPlatoon(QString platoon) {

    if (platoon.size() == 0 || platoon.size() > 5) {
        return false;
    }

    if (platoon.contains(QRegularExpression("[^0-9]"))) {
        return false;
    }

    return true;
}

/* Delete unnecessary gaps in string
 * Input: string
 * Output: string without unnecessary gaps */
QString Validation::DeleteGaps(QString string) {
    int count(0);

    for (int i = 0; i < string.size() - 1; i++) {
        if (string[i] == ' ' && string[i + 1] == ' ') {
            string.remove(i, 1);
        }
    }

    for (int i = 0; i < string.size(); i++) {
        if (string[i] == ' ' && count >= 2) {
            string.remove(i, string.size() - i);
        }
        if (string[i] == ' ') {
            count++;
            i++;
        }
    }
    return string;
}

/* Set up validator for lineEdits items for only double numbers
 * Input: links on lineEdits
 * Output: - */
void Validation::LineEdit::SetDoubleValidator(QList<QLineEdit *> &allEdits) {
    for (auto &element : allEdits) {
        element->setValidator(new CustomQDoubleValidator(0.0, 999.0, 2, element));
    }
}

/* Set up validator for lineEdits items for only integer numbers
 * Input: links on lineEdits
 * Output: - */
void Validation::LineEdit::SetIntValidator(QList<QLineEdit *> &allEdits) {
    for (auto &element : allEdits) {
        element->setValidator( new QIntValidator(0, 10000, element));
    }
}
