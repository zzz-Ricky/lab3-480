/*
 * File Name: rectangle.h
 * Assignment: Lab 2 Exercise B
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 20th 2024
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square
{
private:
    double side_b; // Rectangle other side

public:
    Rectangle(double x, double y, double a, double b, const char *name);

    double area() const;
    double perimeter() const;

    double get_side_b() const { return side_b; }
    void set_side_b(double b) { side_b = b; }

    double get_side_a() const { return Square::get_side_a(); }
    void set_side_a(double a) { Square::set_side_a(a); }

    void display() const;
};

#endif
