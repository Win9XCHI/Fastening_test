#ifndef DIMENSIONS_H
#define DIMENSIONS_H

class Dimensions {
    double thickness;
    double width;
    double length;

public:
    Dimensions();
    Dimensions(double, double, double);
    explicit Dimensions(const Dimensions &);

    double GetThickness();
    double GetWidth();
    double GetLength();
};

#endif // DIMENSIONS_H
