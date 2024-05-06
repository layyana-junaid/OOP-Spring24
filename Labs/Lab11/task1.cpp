/*
*Programmer: Layyana Junaid (23k0056)
*Date: 5th May 2024
*Description: unit conversion program 
*/

#include <iostream>
#include <string>

class Convert
{
protected:
        double val1;
        double val2;  
public:
    Convert(double v1) : val1(v1), val2(0) {}

    double getVal1() { return val1; }
    void setVal1(double v1) { val1 = v1; }

    double getVal2() const { return val2; }
    void setVal2(double v2) { val2 = v2; }
    
    
    virtual void Compute() = 0;
};

class l_to_g : public Convert
{
public:
    l_to_g(double v1) : Convert(v1) {}
    
    void Compute() override
    {
        setVal2(getVal1() * 0.264172);
    }
};

class f_to_c : public Convert
{
public:
    f_to_c(double v1) : Convert(v1) {}
    
    void Compute() override
    {
       setVal2((getVal1() - 32) * 5 / 9);
    }
};

int main() 
{
    Convert* converter;

    l_to_g cap1(4);
    converter = &cap1;
    converter->Compute();
    std::cout << "4 Liters is equals to '" << cap1.getVal2() << "' Gallons" << std::endl;

    f_to_c cap2(70);
    converter = &cap2;
    converter->Compute();
    std::cout << "70 Fahrenheit is equals to '" << cap2.getVal2() << "' Celcius" << std::endl;
}
