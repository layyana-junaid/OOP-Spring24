/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 21 March 23
 *Description: Lab 8 Task 3
 */
#include <iostream>
#include <string>

// base classes
class Position
{
private:
    float x, y, z; // coordinates of the object
public:
    Position(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    void Display() {
        std::cout << "Position at x: " << x << " y: " << y << " z: " << z << std::endl;
    }

};

class Health
{
private:
    int health;

public:
    Health(int h) : health(h) {}

    void Display() {
        std::cout << "Health Status: " << health << std::endl;
    }
};

class Character : public Position, public Health
{
private:
    std::string characterName;
    std::string characterStrength;

public:
    Character(std::string name, std::string strength, float _x, float _y, float _z, int h)
        : characterName(name), characterStrength(strength), Position(_x, _y, _z), Health(h) {}

    void Display() {
        std::cout << "Character Name: " << characterName << std::endl;
        std::cout << "Character's Strength: " << characterStrength << std::endl;
        Position::Display();
        Health::Display();
    }
};

int main(int argc, char const *argv[])
{
    Character char1("Luna Lovegood", "Magical Spells", 3.4, 5.5, 4.3, 5);
    char1.Display();

    return 0;
}
