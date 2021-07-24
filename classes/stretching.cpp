#include "stretching.h"

Stretching::Stretching() : count(0), thread(0), wire_diameter(0) {

}

Stretching::Stretching(unsigned int c, unsigned int t, unsigned int wd) : count(c), thread(t), wire_diameter(wd) {

}

Stretching::Stretching(unsigned int c) : count(c), thread(0) {

}

unsigned int Stretching::GetCount() {
    return count;
}

unsigned int Stretching::GetThread() {
    return thread;
}

unsigned int Stretching::GetWireDiameter() {
    return wire_diameter;
}


void Stretching::SetCount(unsigned int a) {
    count = a;
}

void Stretching::SetThread(unsigned int a) {
    thread = a;
}

void Stretching::SetWireDiameter(unsigned int a) {
    wire_diameter = a;
}
