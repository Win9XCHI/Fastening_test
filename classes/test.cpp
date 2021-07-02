#include "test.h"

Test::Test() : id(0), equipment_id(0), user_id(0), grade(""), date("") {
}

Test::Test(unsigned int i, unsigned int u_i, User u, QString g, QString d, unsigned int ei) : id(i), equipment_id(ei), user_id(u_i), grade(g), date(d) {
    object_user = u;
}

Test::Test(unsigned int i, unsigned int u_i, QString g, QString d, unsigned int ei) : id(i), equipment_id(ei), user_id(u_i), grade(g), date(d) {
}

Test::~Test() {

}

void Test::SetId(unsigned int a) {
    id = a;
}

void Test::SetUser_id(unsigned int a) {
    user_id = a;
}

void Test::SetUser(User a) {
    object_user = a;
}

void Test::SetGrade(QString a) {
    grade = a;
}

void Test::SetDate(QString a) {
    date = a;
}

void Test::SetEquipment(unsigned int a) {
    equipment_id = a;
}


unsigned int Test::GetId() {
    return id;
}

unsigned int Test::GetUser_id() {
    return user_id;
}

User Test::GetUser() {
    return object_user;
}

QString Test::GetGrade() {
    return grade;
}

QString Test::GetDate() {
    return date;
}

unsigned int Test::GetEquipment() {
    return equipment_id;
}

