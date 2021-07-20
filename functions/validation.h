#ifndef VALIDATION_H
#define VALIDATION_H
#include <QString>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QRegularExpression>
#include <vector>

namespace Validation {

    /* Split string on words
     * Input: string, container for words hold, key for split
     * Output: - */
    template <class Container>
    void split(const std::string& str, Container& cont, char delim = ' ');

    /* Check "ПІБ" string
     * Input: string "ПІБ" from main window
     * Output: correct or not */
    bool CheckPIB(QString pib);

    /* Check "Взвод" string
     * Input: string "Взвод" from main window
     * Output: correct or not */
    bool CheckPlatoon(QString platoon);

    /* Delete unnecessary gaps in string
     * Input: string
     * Output: string without unnecessary gaps */
    QString DeleteGaps(QString string);

    namespace LineEdit {

        /* Set up validator for lineEdits items for only double numbers
         * Input: links on lineEdits
         * Output: - */
        void SetDoubleValidator(QList<QLineEdit *> &allEdits);

        /* Set up validator for lineEdits items for only integer numbers
         * Input: links on lineEdits
         * Output: - */
        void SetIntValidator(QList<QLineEdit *> &allEdits);
    }
}

#endif // VALIDATION_H
