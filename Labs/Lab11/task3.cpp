/*
*Programmer: Layyana Junaid (23k0056)
*Date: 6th May 2024
*Description: managing different type of vehicles
*/
#include <iostream>
#include <string>

class Vehicle
{
private:
    std::string make;
    std::string model;
    int speed;
public:
    Vehicle(std::string ma, std::string mo, int s) : make(ma), model(mo), speed(s) {}

    // pure virtual functions
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;

    //getters and setters

    std::string getMake() { return make; }
    void setMake(std::string ma) { make = ma; }

    std::string getModel() { return model; }
    void setModel(std::string mo) { model = mo; }

    int getSpeed() { return speed; }
    void setSpeed(int s) { speed = s; }

};

class Car : public Vehicle
{
private:
    double fuelCapacity;
public:
    Car(std::string ma, std::string mo, int s, double f) 
    : fuelCapacity(f), Vehicle(ma, mo, s) {}
    
    void accelerate() override
    {
        std::cout << "acceleration" << std::endl;
    }

    void brake() override
    {
        std::cout << "Hydro brakes" << std::endl;
    }

    void calculateFuelEfficiency() override
    {
        std::cout << "Fuel Efficiency: " << fuelCapacity/getSpeed() << std::endl;
    }
};

class Truck : public Vehicle
{
private:
    int cargoCapacity;
public:
    Truck(std::string ma, std::string mo, int s, int c)
    : cargoCapacity(c), Vehicle(ma, mo, s) {}

    void accelerate() override
    {
        std::cout << "The truck is accelerating" << std::endl;
    }

    void brake() override
    {
        std::cout << "Hydraulic brakes" << std::endl;
    }

    void calculateFuelEfficiency() override
    {
        std::cout << "Fuel Efficiency: " << cargoCapacity/getSpeed() << std::endl;
    }
};


int main() 
{
    Car myCar("Toyota", "Camry", 60, 1750);
    Truck myTruck("Ford", "F150", 50, 3500);

    std::cout << "Car: " << myCar.getMake() << " " << myCar.getModel() << std::endl;
    myCar.accelerate();
    std::cout << "Speed after acceleration: " << myCar.getSpeed() << std::endl;
    myCar.calculateFuelEfficiency();

    std::cout << "Truck: " << myTruck.getMake() << " " << myTruck.getModel() << std::endl;
    myTruck.brake();
    std::cout << "Speed after braking: " << myTruck.getSpeed() << std::endl;
    myTruck.calculateFuelEfficiency();

    return 0;
}
