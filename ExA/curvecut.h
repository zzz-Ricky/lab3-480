/*
 * File Name: curvecut.h
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#ifndef CURVECUT_H
#define CURVECUT_H

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle {
    
public:
    CurveCut(double x, double y, double width, double length, double radius, const char* name);
    
    double area() const;
    double perimeter() const;
    
    void display() const;
};

#endif
