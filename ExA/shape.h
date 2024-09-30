/*
 * File Name: shape.h
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"
#include <cstring>

class Shape {
private:
    Point origin;
    char* shapeName;

public:
    Shape(double x, double y, const char* name);
    virtual ~Shape();

    const Point& getOrigin() const;
    const char* getName() const;
    
    double get_x() const { return origin.getX(); }
    double get_y() const { return origin.getY(); }

    void display() const;
    
    double distance(const Shape& other) const;
    static double distance(const Shape& the_shape, const Shape& other);

    void move(double dx, double dy);

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

#endif
