/*
 * File Name: rectangle.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y, double a, double b, const char* name)
    : Shape(x, y, name), Square(x, y, a, name), side_b(b) {}


double Rectangle::area() const {
    return get_side_a() * side_b;
}

double Rectangle::perimeter() const {
    return 2 * (get_side_a() + side_b);
}


void Rectangle::display() const {
    std::cout << "Rectangle Name: " << getName() << std::endl;
    
    std::cout << "X-coordinate: " << getOrigin().getX() << std::endl;
    std::cout << "Y-coordinate: " << getOrigin().getY() << std::endl;
    
    std::cout << "Side a: " << get_side_a() << std::endl;
    std::cout << "Side b: " << side_b << std::endl;
    
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
}
