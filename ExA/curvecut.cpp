#include "curvecut.h"
#include <iostream>

CurveCut::CurveCut(double x, double y, double width, double length, double radius, const char *name)
    : Shape(x, y, name), Rectangle(x, y, width, length, name), Circle(x, y, radius, name)
{
    if (radius > width || radius > length)
    {
        std::cerr << "Error: Radius cannot be greater than width or length of the rectangle." << std::endl;
        exit(1);
    }
}

double CurveCut::area() const
{
    return Rectangle::area() - (M_PI * get_radius() * get_radius() / 4.0);
}

double CurveCut::perimeter() const
{
    return Rectangle::perimeter() - 2 * get_side_a() + (M_PI * get_radius() / 2.0);
}

void CurveCut::display() const
{
    std::cout << "CurveCut Name: " << Shape::getName() << "\n"
              << "X-coordinate: " << Shape::get_x() << "\n"
              << "Y-coordinate: " << Shape::get_y() << "\n"
              << "Width: " << Rectangle::get_side_a() << "\n"
              << "Length: " << Rectangle::get_side_b() << "\n"
              << "Radius of the cut: " << Circle::get_radius() << "\n";
}
