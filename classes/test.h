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

public:
    Test();
    Test(unsigned int i, unsigned int u_i, User u, QString g, QString d, unsigned int ei);
    Test(unsigned int i, unsigned int u_i, QString g, QString d, unsigned int ei);
    ~Test();

    void SetId(unsigned int a);
    void SetUser_id(unsigned int a);
    void SetUser(User a);
    void SetGrade(QString a);
    void SetDate(QString a);

    unsigned int GetId();
    unsigned int GetUser_id();
    User GetUser();
    QString GetGrade();
    QString GetDate();
};

#endif // TEST_H
