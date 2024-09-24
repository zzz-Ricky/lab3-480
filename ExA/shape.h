/*
 * File Name: shape.h
 * Assignment: Lab 2 Exercise B
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 20th 2024
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
    ~Shape();
    
    const Point& getOrigin() const;
    const char* getName() const;
    
    void display() const;
    
    double distance(const Shape& other) const;
    static double distance(const Shape& the_shape, const Shape& other);
    
    void move(double dx, double dy);
};

#endif
