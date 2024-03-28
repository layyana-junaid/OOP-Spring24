/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 28th March 2024
 *Description: Lab 09 Q2
 */

#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14

class Shape
{
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual void DisplayProperties() const = 0;
};

class Circle : public Shape
{
private:
    double radius; // circle
public:
    Circle(double r) : radius(r) {}

    // area function
    virtual double Area() const override
    {
        double area = 0;
        area = PI * radius * radius;
        return area;
    }

    // perimeter function
    virtual double Perimeter() const override
    {
        double perimeter = 0;
        perimeter = 2 * PI * radius;
        return perimeter;
    }

    double Diameter() const
    {
        double diameter = 0;
        diameter = radius + radius;
        return diameter;
    }

    virtual void DisplayProperties() const override
    {
        std::cout << "-Properties of the Circle: " << std::endl;
        std::cout << "-Area: " << Area() << std::endl;
        std::cout << "-Perimeter: " << Perimeter() << std::endl;
        std::cout << "-Diameter: " << Diameter() << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    double length, width; // square
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // area function
    virtual double Area() const override
    {
        double area = 0;
        area = length * width;
        return area;
    }

    // perimeter function
    virtual double Perimeter() const override
    {
        double perimeter = 0;
        perimeter = length + length + width + width;
        return perimeter;
    }

    double Diagonal() const
    {
        double diagonal = 0;
        diagonal = sqrt((length * length) + (width * width));
        return diagonal;
    }

    virtual void DisplayProperties() const override
    {
        std::cout << "-Properties of the Rectangle: " << std::endl;
        std::cout << "-Area: " << Area() << std::endl;
        std::cout << "-Perimeter: " << Perimeter() << std::endl;
        std::cout << "-Diagonal: " << Diagonal() << std::endl;
    }
};

class Square : public Shape
{
private:
    double length, width;

public:
    Square(double l, double w) : length(l), width(w) {}

    // area function
    virtual double Area() const override
    {
        double area = 0;
        area = length * width;
        return area;
    }

    // perimeter function
    virtual double Perimeter() const override
    {
        double perimeter = 0;
        perimeter = length + length + width + width;
        return perimeter;
    }

    double Diagonal() const
    {
        double diagonal = 0;
        diagonal = sqrt((length * length) + (width * width));
        return diagonal;
    }

    virtual void DisplayProperties() const override
    {
        std::cout << "-Properties of the Square: " << std::endl;
        std::cout << "-Area: " << Area() << std::endl;
        std::cout << "-Perimeter: " << Perimeter() << std::endl;
        std::cout << "-Diagonal: " << Diagonal() << std::endl;
    }
};

class Triangle : public Shape
{
private:
    double base, perpendicular, height, hypo; 
public:
    Triangle(double b, double p, double h, double hypo)
        : base(b), perpendicular(p), height(h), hypo(hypo) {}

    // area function
    virtual double Area() const override
    {
        double area = 0;
        area = 0.5 * base * height;
        return area;
    }

    // perimeter function
    virtual double Perimeter() const override
    {
        double perimeter = 0;
        perimeter = base + perpendicular + hypo;
        return perimeter;
    }

    virtual void DisplayProperties() const override
    {
        std::cout << "-Properties of the Triangle: " << std::endl;
        std::cout << "-Area: " << Area() << std::endl;
        std::cout << "-Perimeter: " << Perimeter() << std::endl;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side, double height) : Triangle(side, side, side, height) {}

    virtual void DisplayProperties() const override
    {
        std::cout << "-Properties of the Equilateral Triangle: " << std::endl;
        std::cout << "-Area: " << Area() << std::endl;
        std::cout << "-Perimeter: " << Perimeter() << std::endl;
    }
};


// in main we will use switch case to call different classes
int main()
{
    std::cout << "Welcome to the Geometry Calculator!" << std::endl;

    std::string option;

    do {

    int choice;

    std::cout << "Please Select the Shape: " << std::endl;
    std::cout << "1. Circle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "3. Square" << std::endl;
    std::cout << "4. Triangle" << std::endl;
    std::cout << "5. Equilateral Triangle" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        double radius;
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;
        Shape *circle = new Circle(radius);
        circle->DisplayProperties();
        delete circle;
        break;
    }
    case 2:
    {
        double length, width;
        std::cout << "Enter the length of the Rectangle: ";
        std::cin >> length;
        std::cout << "Enter the width of the Rectangle: ";
        std::cin >> width;
        Shape *rectangle = new Rectangle(length, width);
        rectangle->DisplayProperties();
        delete rectangle;
        break;
    }
    case 3:
    {
        double length, width;
        std::cout << "Enter the length of the Square: ";
        std::cin >> length;
        width = length;
        Shape *square = new Square(length, width);
        square->DisplayProperties();
        delete square;
        break;
    }
    case 4:
    {
        double base, perpendicular, height;
        std::cout << "Enter the base length of the Triangle: ";
        std::cin >> base;
        std::cout << "Enter the perpendicular length of the Triangle: ";
        std::cin >> perpendicular;
        std::cout << "Enter the height of the Triangle: ";
        std::cin >> height;
        Shape *triangle = new Triangle(base, perpendicular, height, 0);
        triangle->DisplayProperties();
        delete triangle;
        break;
    }
    case 5:
    {
        double side, height;
        std::cout << "Enter the sides length of the Equilateral Triangle: ";
        std::cin >> side;
        std::cout << "Enter the height of the Equilateral Triangle: ";
        std::cin >> height;
        Shape *equilateralTriangle = new EquilateralTriangle(side, height);
        equilateralTriangle->DisplayProperties();
        delete equilateralTriangle;
        break;
    }
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }

    std::cout << "Do you want to calculate properties for another shape? (yes/no): ";
    std::cin >> option;

    } while(option != "no" || option != "No");

    return 0;
}



