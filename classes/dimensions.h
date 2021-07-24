#ifndef DIMENSIONS_H
#define DIMENSIONS_H

class Dimensions {
    double thickness;
    double width;
    double length;

public:
    Dimensions();
    Dimensions(double t, double w, double l);
    Dimensions(const Dimensions &other);

    double GetThickness();
    double GetWidth();
    double GetLength();

    Dimensions& operator=(Dimensions &other);
};

#endif // DIMENSIONS_H
