/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 18th April 2023
 *Description: Lab10 task 4
 */

#include <iostream>

class printClass; // Forward declaration

class perimeter {
private:
    int length;
    int breadth;
public:
    perimeter(int l, int b) : length(l), breadth(b) {}

    // Declare printClass as a friend class
    friend class printClass;

    int calculatePerimeter() {
        return 2 * (length + breadth);
    }
};

class printClass {
public:
    void displayPerimeter(perimeter obj) {
        std::cout << "Perimeter: " << obj.calculatePerimeter() << std::endl;
    }
};

int main() {
    int length, breadth;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter breadth: ";
    std::cin >> breadth;

    perimeter p(length, breadth);
    printClass printer;
    printer.displayPerimeter(p);

    return 0;
}
