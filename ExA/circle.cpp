/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "circle.h"
#include <iostream>

Circle::Circle(double x, double y, double r, const char *name)
    : Shape(x, y, name), radius(r) {}

double Circle::area() const
{
    // area = pi*radius^2
    return (radius * radius * 3.14159);
}
double Circle::perimeter() const
{
    return (2 * 3.14159 * radius);
}

void Circle::display() const
{
    Shape::display();
    std::cout << "Radius: " << radius << "\nArea: " << area() << "\nPerimeter: " << perimeter() << std::endl;
}