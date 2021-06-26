#include "stretching.h"

Stretching::Stretching() : count(0), thread(0) {

}

Stretching::Stretching(unsigned int a, unsigned int b) : count(a), thread(b) {

}

unsigned int Stretching::GetCount() {
    return count;
}

unsigned int Stretching::GetThread() {
    return thread;
}
