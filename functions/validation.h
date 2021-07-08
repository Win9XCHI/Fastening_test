#ifndef VALIDATION_H
#define VALIDATION_H
#include <QString>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QRegularExpression>
#include <vector>

namespace Validation {
    template <class Container>
    void split(const std::string& str, Container& cont, char delim = ' ');

    bool CheckPIB(QString pib);

    bool CheckPlatoon(QString platoon);

    namespace LineEdit {
        void SetDoubleValidator(QList<QLineEdit *> &allEdits);

        void SetIntValidator(QList<QLineEdit *> &allEdits);
    }
}

#endif // VALIDATION_H
