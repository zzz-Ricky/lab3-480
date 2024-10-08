/*
 * File Name: square.h
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape {
protected:
    double side_a;

public:
    Square(double x, double y, double a, const char* name);
    
    double get_side_a() const { return side_a; }
    void set_side_a(double a) { side_a = a; }
    
    double area() const;
    double perimeter() const;
    
    void display() const;
};

#endif
