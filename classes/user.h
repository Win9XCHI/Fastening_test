#ifndef USER_H
#define USER_H
#include <QString>

class User {
    unsigned int id;
    QString name;
    QString platoon;

public:
    User();
    User(QString n, QString p, unsigned int i = 0);
    User(const User&);
    ~User();

    void SetId(unsigned int a);
    void SetName(QString a);
    void SetPlatoon(QString a);

    unsigned int GetId();
    QString GetName();
    QString GetPlatoon();
    User& operator=(User &other);
    QString operator [](int i); //0 - Name, 1 - Platoon, 2 - id
};

#endif // USER_H
