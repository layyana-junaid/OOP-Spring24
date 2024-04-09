/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 28th March 2024
 *Description: Lab 09 Q2
 */

#include <iostream>
#include <cmath>

const double PI = 3.14; // global const for PI

class Shape
{
public:
    // area of circle
    double Area(double radius) const
    {

        return PI * radius * radius;
    }

    // perimeter of circle
    double Perimeter(double radius) const
    {
        return 2 * PI * radius;
    }

    // area of rectangle
    double AreaRectangle(double length, double width) const
    {

        return length * width;
    }

    // perimeter of rectangle
    double PerimeterRectangle(double length, double width) const
    {
        return length + width + length + width;
    }

    // area of triangle
    double AreaTriangle(double base, double height) const
    {
        return 0.5 * base * height;
    }

    // perimeter of triangle
    double PerimeterTriangle(double side1, double side2, double side3) const
    {
        return side1 + side2 + side3;
    }
};

int main()
{
    Shape shapes;

    double radius = 4.5;
    std::cout << "->Circle: " << std::endl;
    std::cout << "-Area: " << shapes.Area(radius) << std::endl;
    std::cout << "-Perimeter(Circumference): " << shapes.Perimeter(radius) << std::endl;

    double length = 5;
    double width = 6;
    std::cout << "->Rectangle: " << std::endl;
    std::cout << "-Area: " << shapes.AreaRectangle(length, width) << std::endl;
    std::cout << "-Perimeter: " << shapes.PerimeterRectangle(length, width) << std::endl;

    double base = 5, height = 10;
    double side1 = 6, side2 = 7, side3 = 5;
    std::cout << "->Triangle: " << std::endl;
    std::cout << "-Area: " << shapes.AreaTriangle(base, height) << std::endl;
    std::cout << "-Perimeter: " << shapes.PerimeterTriangle(side1, side2, side3) << std::endl;

    return 0;
}
