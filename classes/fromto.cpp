#include "fromto.h"

FromTo::FromTo() : from(0), to(0) {

}

FromTo::FromTo(double f, double t) : from(f), to(t) {

}

FromTo::FromTo(const FromTo &other) : from(other.from), to(other.to) {
}

double FromTo::GetFrom() {
    return from;
}

double FromTo::GetTo() {
    return to;
}
