#ifndef TEST_H
#define TEST_H
#include "user.h"

class Test {
    unsigned int id;
    unsigned int equipment_id;
    unsigned int user_id;
    User object_user;
    QString grade;
    QString date;
    QString equipment;

public:
    Test();
    Test(unsigned int i, unsigned int u_i, User u, QString g, QString d, unsigned int ei);
    Test(User u, QString g, QString d, QString e);
    Test(unsigned int i, unsigned int u_i, QString g, QString d, unsigned int ei);
    ~Test();

    void SetId(unsigned int a);
    void SetUser_id(unsigned int a);
    void SetUser(User a);
    void SetGrade(QString a);
    void SetDate(QString a);
    void SetEquipment(unsigned int a);

    unsigned int GetId();
    unsigned int GetUser_id();
    User GetUser();
    QString GetGrade();
    QString GetDate();
    unsigned int GetEquipment();
    QString operator [](int i); //0 - Name, 1 - Platoon, 2 - grade, 3 - date, 4 - equipment
};

#endif // TEST_H
