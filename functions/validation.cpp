#include "validation.h"

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

bool Validation::CheckPIB(QString pib) {
    std::vector<std::string> str;
    Validation::split(pib.toStdString(), str);

    if (str.size() != 3) {
        return false;
    }

    if (pib.contains(QRegularExpression("[^А-Яа-яії \f\n\r\t\v]"))) {
        return false;
    }

    return true;
}

bool Validation::CheckPlatoon(QString platoon) {

    if (platoon.size() == 0 || platoon.size() > 5) {
        return false;
    }

    if (platoon.contains(QRegularExpression("[^0-9]"))) {
        return false;
    }

    return true;
}
