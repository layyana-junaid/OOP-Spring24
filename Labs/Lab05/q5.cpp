/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: Task 5
 */
#include <iostream>
#include <string>
#include <vector>

//engine class
class Engine {
private:
    std::string engineCC;
public:
    //constructor
    Engine(std::string CC) : engineCC(CC) {}

    std::string getEngineCC() {
        return engineCC;
    }
};

//wheel class
class Wheels {
private:
    int wheels;
public:
    //constructor
    Wheels(int num) : wheels(num) {}

    int getWheels() {
        return wheels;
    }
};

//headlights class
class HeadLights {
private:
    std::string headLights;
public:
    //constructor
    HeadLights(std::string lights) : headLights(lights) {}

    std::string getHeadLights() {
        return headLights;
    }
};

//steering wheel
class Steering {
private:
    std::string steeringType;
public:
    //constructor
    Steering(std::string type) : steeringType(type) {}

    std::string getSteering() {
        return steeringType;
    }
};

//creating the combined class of Car
class Car {
private:
    Engine* engine;
    std::vector<Wheels*> wheels;
    std::vector<HeadLights*> headlights;
    Steering* steering;

public:
    Car(Engine* eng, std::vector<Wheels*> whls, std::vector<HeadLights*> hdlts, Steering* str) : engine(eng), wheels(whls), headlights(hdlts), steering(str) {}

    Engine* getEngine() const {
        return engine;
    }

    const std::vector<Wheels*>& getWheels() const {
        return wheels;
    }

    const std::vector<HeadLights*>& getHeadlights() const {
        return headlights;
    }

    Steering* getSteering() const {
        return steering;
    }
};

int main() {
    Engine engine("V8");
    std::vector<Wheels*> wheels = { new Wheels(18), new Wheels(18), new Wheels(18), new Wheels(18) };
    std::vector<HeadLights*> headlights = { new HeadLights("LED"), new HeadLights("LED") };
    Steering steering("Power");

    Car car(&engine, wheels, headlights, &steering);

    std::cout << "Engine Type: " << car.getEngine()->getEngineCC() << std::endl;
    std::cout << "Wheel Size: " << car.getWheels()[0]->getWheels() << std::endl;
    std::cout << "Headlight Type: " << car.getHeadlights()[0]->getHeadLights() << std::endl;
    std::cout << "Steering Type: " << car.getSteering()->getSteering() << std::endl;

    // Clean up dynamically allocated wheels
    for (Wheels* wheel : wheels) {
        delete wheel;
    }

    // Clean up dynamically allocated headlights
    for (HeadLights* headlight : headlights) {
        delete headlight;
    }

    return 0;
}
