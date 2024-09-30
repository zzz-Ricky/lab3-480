/*
 * File Name: GraphicsWorld.cpp
 * Assignment: Lab 3 Exercise A
 * Lab section: B01
 * Completed by: Ricky Huynh, Akaash Aujla
 * Development Date: September 24th 2024
 */

#include <iostream>
#include "GraphicsWorld.h"
#include "point.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "curvecut.h"

void GraphicsWorld::run() {
    std::cout << "Authors: Ricky Huynh, Akaash Aujla";
    
    #if 0 // Change 0 to 1 to test Point
    Point m (6, 8);
    Point n (6,8);
    n.setX(9);
    std::cout << "\nExpected to display the distance between m and n is: 3";
    std::cout << "\nThe distance between m and n is: " << m.distance(n);
    std::cout << "\nExpected second version of the distance function also print: 3";
    std::cout << "\nThe distance between m and n is again: " << Point::distance(m, n);
    #endif // end of block to test Point

    #if 1 // Change 0 to 1 to test Square
    std::cout << "\n\nTesting Functions in class Square:" << std::endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
    #endif // end of block to test Square

    #if 1 // Change 0 to 1 to test Rectangle
    std::cout << "\nTesting Functions in class Rectangle:";
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16, 7, 8, 9, "RECTANGLE B");
    b.display();
    double d = a.distance(b);
    std::cout << "\nDistance between square a, and b is: " << d << std::endl;
    Rectangle rec1 = a;
    rec1.display();
    std::cout << "\nTesting assignment operator in class Rectangle:" << std::endl;
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    std::cout << "\nExpected to display the following values for object rec2: " << std::endl;
    std::cout << "Rectangle Name: RECTANGLE A\n"
              << "X-coordinate: 5\n"
              << "Y-coordinate: 7\n"
              << "Side a: 12\n"
              << "Side b: 15\n"
              << "Area: 180\n"
              << "Perimeter: 54\n";
    std::cout << "\nIf it doesn't, there is a problem with your assignment operator.\n" << std::endl;
    rec2.display();
    std::cout << "\nTesting copy constructor in class Rectangle:" << std::endl;
    Rectangle rec3 (a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);
    std::cout << "\nExpected to display the following values for object rec3: " << std::endl;
    std::cout << "Rectangle Name: RECTANGLE A\n"
              << "X-coordinate: 5\n"
              << "Y-coordinate: 7\n"
              << "Side a: 100\n"
              << "Side b: 200\n"
              << "Area: 20000\n"
              << "Perimeter: 600\n";
    std::cout << "\nIf it doesn't, there is a problem with your assignment operator.\n" << std::endl;
    rec3.display();
    #endif // end of block to test Rectangle

    #if 0 // Change 0 to 1 to test using array of pointer and polymorphism
    std::cout << "\nTesting array of pointers and polymorphism:" << std::endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh[2] = &rec1;
    sh[3] = &rec3;
    sh[0]->display();
    sh[1]->display();
    sh[2]->display();
    sh[3]->display();
    #endif // end of block to test array of pointer and polymorphism
    
    #if 1 // Change 0 to 1 to test Circle
    std::cout << "\nTesting Functions in class Circle:" << std::endl;
    Circle c(3, 5, 9, "CIRCLE C");
    c.display();
    std::cout << "The area of " << c.getName() << " is: " << c.area() << std::endl;
    std::cout << "The perimeter of " << c.getName() << " is: " << c.perimeter() << std::endl;
    d = a.distance(c);
    std::cout << "\nThe distance between rectangle a and circle c is: " << d << std::endl;
    
    CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
    std::cout << "The area of " << rc.getName() << " is: " << rc.area() << std::endl;
    std::cout << "The perimeter of " << rc.getName() << " is: " << rc.perimeter() << std::endl;
    d = rc.distance(c);
    std::cout << "\nThe distance between rc and c is: " << d << std::endl;
    
    // Using array of Shape pointers:
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &a;
    sh[2] = &c;
    sh[3] = &rc;
    
    sh[0]->display();
    std::cout << "\nThe area of " << sh[0]->getName() << " is: " << sh[0]->area() << std::endl;
    std::cout << "\nThe perimeter of " << sh[0]->getName() << " is: " << sh[0]->perimeter() << std::endl;
    
    sh[1]->display();
    std::cout << "\nThe area of " << sh[1]->getName() << " is: " << sh[1]->area() << std::endl;
    std::cout << "\nThe perimeter of " << sh[1]->getName() << " is: " << sh[1]->perimeter() << std::endl;
    
    sh[2]->display();
    std::cout << "\nThe area of " << sh[2]->getName() << " is: " << sh[2]->area() << std::endl;
    std::cout << "\nThe circumference of " << sh[2]->getName() << " is: " << sh[2]->perimeter() << std::endl;
    
    sh[3]->display();
    std::cout << "\nThe area of " << sh[3]->getName() << " is: " << sh[3]->area() << std::endl;
    std::cout << "\nThe perimeter of " << sh[3]->getName() << " is: " << sh[3]->perimeter() << std::endl;
    
    std::cout << "\nTesting copy constructor in class CurveCut:" << std::endl;
    CurveCut cc = rc;
    cc.display();
    
    std::cout << "\nTesting assignment operator in class CurveCut:" << std::endl;
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    cc2.display();
    cc2 = cc;
    cc2.display();
    #endif
} // END OF FUNCTION run
