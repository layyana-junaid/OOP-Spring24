/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 18th April 2023
 *Description: Lab10 task 3
 */
#include <iostream>

class Shape {
private:
    double area;
public:
    Shape(double a = 0) : area(a) {}

    void Area() {
        area = 40; 
    }

    Shape operator+(Shape obj) {
        Shape shape;
        shape.area = area + obj.area;
        return shape;
    }

    double getArea() {
        return area;
    }
};

int main() {
    Shape shape1, shape2, shape3;

    shape1.Area();
    shape2.Area();

    shape3 = shape1 + shape2;

    std::cout << "Combined area: " << shape3.getArea() << std::endl;

    return 0;
}

