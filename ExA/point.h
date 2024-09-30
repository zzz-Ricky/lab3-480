/*
 * File Name: point.h
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x;
    double y;
    static int count;
    int id;

public:
    Point(double x, double y);
    void display() const;
    
    static int counter();
    
    double distance(const Point& other) const;
    static double distance(const Point& p1, const Point& p2);
    
    double getX() const;
    double getY() const;
    
    void setX(double x);
    void setY(double y);
};

#endif

