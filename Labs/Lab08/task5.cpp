/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 21 March 23
 *Description: Lab 8 Task 5
 */

#include <iostream>
#include <string>

class Vehicle
{
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(const std::string& _make, const std::string& _model, int _year)
        : make(_make), model(_model), year(_year) {}

    void Display() const
    {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
    }
};

class Car : public Vehicle
{
protected:
    int numDoors;
    double fuelEfficiency;

public:
    Car(const std::string& _make, const std::string& _model, int _year, int _numDoors, double _fuelEfficiency)
        : Vehicle(_make, _model, _year), numDoors(_numDoors), fuelEfficiency(_fuelEfficiency) {}

    void Display() const
    {
        Vehicle::Display();
        std::cout << "Number of Doors: " << numDoors << std::endl;
        std::cout << "Fuel Efficiency: " << fuelEfficiency << " mpg" << std::endl;
    }
};

class ElectricCar : public Car
{
private:
    double batteryLife;

public:
    ElectricCar(const std::string& _make, const std::string& _model, int _year, int _numDoors, double _fuelEfficiency, double _batteryLife)
        : Car(_make, _model, _year, _numDoors, _fuelEfficiency), batteryLife(_batteryLife) {}

    void Display() const
    {
        Car::Display();
        std::cout << "Battery Life: " << batteryLife << " kWh" << std::endl;
    }
};

int main()
{
    ElectricCar electricCar("Toyota", "Yaris", 2022, 4, 90.0, 300.0);
    electricCar.Display();

    return 0;
}
