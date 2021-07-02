#ifndef USER_H
#define USER_H
#include <QString>

class User {
    unsigned int id;
    QString name;
    QString platoon;

public:
    User();
    User(unsigned int i, QString n, QString p);
    User(const User&);
    ~User();

    void SetId(unsigned int a);
    void SetName(QString a);
    void SetPlatoon(QString a);

    unsigned int GetId();
    QString GetName();
    QString GetPlatoon();
    User& operator=(User &other);
};

#endif // USER_H
