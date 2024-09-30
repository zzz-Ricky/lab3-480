/*
 * File Name: shape.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "square.h"
#include <iostream>

Square::Square(double x, double y, double side, const char* name)
    : Shape(x, y, name), side_a(side) {}

double Square::area() const {
    return side_a * side_a;
}

double Square::perimeter() const {
    return 4 * side_a;
}

void Square::display() const {
    Shape::display();
    std::cout << "Side a: " << side_a << "\nArea: " << area() << "\nPerimeter: " << perimeter() << std::endl;
}
