#ifndef CUSTOMQDOUBLEVALIDATOR_H
#define CUSTOMQDOUBLEVALIDATOR_H
#include <QDoubleValidator>

class CustomQDoubleValidator : public QDoubleValidator {
    QStringList _decimalPoints;
    public:
        CustomQDoubleValidator(double bottom, double top, int decimals, QObject *parent = nullptr){
            _decimalPoints.append(".");
            QDoubleValidator(bottom, top, decimals, parent);
        }

        /* Overloaded function */
        State validate(QString &str, int &pos) const{
            QString s(str);

            for(QStringList::ConstIterator point = _decimalPoints.begin(); point != _decimalPoints.end(); ++point){
                s.replace(*point, locale().decimalPoint());
            }
            return QDoubleValidator::validate(s, pos);
        }
};

#endif // CUSTOMQDOUBLEVALIDATOR_H
