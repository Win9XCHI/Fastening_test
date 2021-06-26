#include "dimensions.h"

Dimensions::Dimensions() : thickness(0), width(0), length(0) {

}

Dimensions::Dimensions(double a, double b, double c) : thickness(a), width(b), length(c) {

}

Dimensions::Dimensions(const Dimensions &other) : thickness(other.thickness), width(other.width), length(other.length) {
}

double Dimensions::GetThickness() {
    return thickness;
}

double Dimensions::GetWidth() {
    return width;
}

double Dimensions::GetLength() {
    return length;
}

