/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 18th April 2023
 *Description: Lab10 task 2
 */

#include <iostream>
#include <string>

class Decrement
{
private:
    int numb;
public:
    Decrement(int n) : numb(n) {}

    // overloading prefix
    Decrement operator--()
    {
        numb *= 4;
        return *this;
    }

    // overloading postfex
    Decrement operator--(int)
    {
       Decrement temp = *this;
        numb /= 4;
        return temp;
    }

    // Function to display the value
    void display() {
        std::cout << "Value: " << numb << std::endl;
    }
};

int main() {
    Decrement num(4);

    std::cout << "Before prefix decrement: ";
    num.display();
    --num;
    std::cout << "After prefix decrement: ";
    num.display();

    std::cout << "Before postfix decrement: ";
    num.display();
    num--;
    std::cout << "After postfix decrement: ";
    num.display();

    return 0;
}
