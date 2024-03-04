/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: creating a class called Square with the following attributes encapsulating the
 details mentioned in the question.
 */

#include <iostream>
#include <string>

class Square
{
private:
    float Sidelength;
    float Area;
    static float allareas;
public:
// default constructor
    Square() : Sidelength(0), Area(0) {}

    // parameterized constructor
    Square(float len) : Sidelength(len) {
        calculateArea();
    }

    // calculate area function
    void calculateArea() {
        Area = Sidelength * Sidelength;
        allareas += Area;
    }

    // creating getters and setters 
    float getSideLength() {
        return Sidelength;
    }

    void setSideLength(float len) {
        Sidelength = len;
        calculateArea();
    }

    float getArea() {
        return Area;
    }

    //static function 
    static float getAllAreas() {
        return allareas;
    }

};

// acessing stati data member in main 
float Square :: allareas;

int main() {
    Square sq1(4.0);
    std::cout << "The value of each side of Square 1 is : " << sq1.getSideLength() << ". The Area of this Square is : " << Square::getAllAreas() << "." << std::endl;
    Square sq2(12.0);
    std::cout << "The value of each side of Square 2 is : " << sq2.getSideLength() << ". The Area of this Square is : " << Square::getAllAreas() << "." << std::endl;
    Square sq3(7.5);
    std::cout << "The value of each side of Square 3 is : " << sq3.getSideLength() << ". The Area of this Square is : " << Square::getAllAreas() << "." << std::endl;
}

