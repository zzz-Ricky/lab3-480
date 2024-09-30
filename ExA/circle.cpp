/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(double x, double y, double r, const char* name) : Shape(x, y, name), radius(r) {}

void Circle::set_radius(double r) {
    radius = r;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::display() const {
    std::cout << "Circle Name: " << getName() << "\n"
              << "X-coordinate: " << get_x() << "\n"
              << "Y-coordinate: " << get_y() << "\n"
              << "Radius: " << radius << "\n";
}
