#include "user.h"

User::User() : id(0), name(""), platoon("") {

}

User::User(QString n, QString p, unsigned int i) : id(i), name(n), platoon(p) {

}

User::User(const User &other) {
    id = other.id;
    name = other.name;
    platoon = other.platoon;
}

User::~User() {

}

void User::SetId(unsigned int a) {
    id = a;
}

void User::SetName(QString a) {
    name = a;
}

void User::SetPlatoon(QString a) {
    platoon = a;
}

unsigned int User::GetId() {
    return id;
}

QString User::GetName() {
    return name;
}

QString User::GetPlatoon() {
    return platoon;
}

User& User::operator=(User &other) {
    id = other.GetId();
    name = other.GetName();
    platoon = other.GetPlatoon();
    return *this;
}

QString User::operator [](int i) {
   switch (i) {
       case 0: {
         return name;
       }
       case 1: {
         return platoon;
       }
       case 2: {
         return QString::number(id);
       }
   }
   return "";
}
