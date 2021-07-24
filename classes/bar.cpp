#include "bar.h"

Bar::Bar() : count(0), nails(0), length_nail(0), staple(0) {

}

Bar::Bar(unsigned int c, unsigned int n, unsigned int l, unsigned int s) : count(c), nails(n), length_nail(l), staple(s) {

}

Bar::Bar(unsigned int c, Dimensions o, unsigned int n, unsigned int l, unsigned int s) : count(c), nails(n), length_nail(l), staple(s), object(o) {

}

unsigned int Bar::GetCount() {
    return count;
}

unsigned int Bar::GetNails() {
    return nails;
}

Dimensions Bar::GetDimensions() {
    return object;
}

unsigned int Bar::GetLengthNail() {
    return length_nail;
}

unsigned int Bar::GetStaple() {
    return staple;
}

void Bar::SetCount(unsigned int a) {
    count = a;
}

void Bar::SetNails(unsigned int a) {
    nails = a;
}

void Bar::SetDimensions(Dimensions a) {
    object = a;
}

void Bar::SetLengthNail(unsigned int a) {
    length_nail = a;
}

void Bar::SetStaple(unsigned int a) {
    staple = a;
}

