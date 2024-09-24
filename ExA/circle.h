/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
private:
    double radius; // Circular Radius

public:
    Circle(double x, double y, double r, const char *name);

    double area() const;
    double perimeter() const;

    double get_radius() const { return radius; }
    void set_radius(double r) { radius = r; }

    void display() const;
};

#endif