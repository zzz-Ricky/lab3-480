/*
 * File Name: point.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include "point.h"
#include <cmath>
#include <iostream>

int Point::count = 0;

Point::Point(double x, double y) : x(x), y(y), id(1001 + count) {
    count++;
}

void Point::display() const {
    std::cout << "X-coordinate: " << x << "\nY-coordinate: " << y << std::endl;
}

int Point::counter() {
    return count;
}

double Point::distance(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

double Point::distance(const Point& p1, const Point& p2) {
    return p1.distance(p2);
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }
