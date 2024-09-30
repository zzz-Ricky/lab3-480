/*
 * File Name: shape.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "shape.h"
#include <iostream>

Shape::Shape(double x, double y, const char* name)
    : origin(x, y) {
    shapeName = new char[strlen(name) + 1];
    strcpy(shapeName, name);
}

Shape::~Shape() {
    delete[] shapeName;
}

const Point& Shape::getOrigin() const {
    return origin;
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::display() const {
    std::cout << "Shape Name: " << shapeName << std::endl;
    origin.display();
}

double Shape::distance(const Shape& other) const {
    return origin.distance(other.origin);
}

double Shape::distance(const Shape& the_shape, const Shape& other) {
    return the_shape.distance(other);
}

void Shape::move(double dx, double dy) {
    origin.setX(origin.getX() + dx);
    origin.setY(origin.getY() + dy);
}
