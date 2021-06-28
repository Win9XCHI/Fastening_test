#include "stretching.h"

Stretching::Stretching() : count(0), thread(0) {

}

Stretching::Stretching(unsigned int c, unsigned int t) : count(c), thread(t) {

}

Stretching::Stretching(unsigned int c) : count(c), thread(0) {

}

unsigned int Stretching::GetCount() {
    return count;
}

unsigned int Stretching::GetThread() {
    return thread;
}

void Stretching::SetCount(unsigned int a) {
    count = a;
}

void Stretching::SetThread(unsigned int a) {
    thread = a;
}
