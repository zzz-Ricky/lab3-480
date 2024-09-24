/*
 * File Name: curvecut.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "curvecut.h"
#include <iostream>

CurveCut::CurveCut(double x, double y, double a, double b, double r, const char *name)
    : rectangle(x, y, a, b, name), circle(x, y, r, name) {}

double CurveCut::area() const
{
    return (rectangle.area() - (circle.area() / 4));
}
double CurveCut::perimeter() const
{
    return ((rectangle.perimeter() - (2 * circle.get_radius())) + (circle.perimeter() / 4));
}
void CurveCut::display() const
{
    Shape::display();
    std::cout << "\nWidth: " << rectangle.get_side_a() << "\nHeight: " << rectangle.get_side_b() << "\nRadius: " << circle.get_radius() << std::endl;
}