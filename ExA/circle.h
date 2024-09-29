#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape {
private:
    double radius;

public:
    Circle(double x, double y, double r, const char* name);
    
    double get_radius() const { return radius; }
    void set_radius(double r);
    
    double area() const;
    double perimeter() const;
    
    void display() const;
};

#endif
