#include "user.h"

User::User() : id(0), name(""), platoon("") {

}

User::User(unsigned int i, QString n, QString p) : id(i), name(n), platoon(p) {

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
