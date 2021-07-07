#ifndef VALIDATION_H
#define VALIDATION_H
#include <QString>
#include <QRegularExpression>
#include <vector>

namespace Validation {
    template <class Container>
    void split(const std::string& str, Container& cont, char delim = ' ');

    bool CheckPIB(QString pib);

    bool CheckPlatoon(QString platoon);
}

#endif // VALIDATION_H
