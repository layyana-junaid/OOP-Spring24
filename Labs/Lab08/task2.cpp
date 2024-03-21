/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 21 March 23
 *Description: Lab 8 Task 2
*/

#include <iostream>
#include <string>

// Base class Character
class Character
{
protected:
    int health;
    int damage;

public:
    // Constructor
    Character(int _health, int _damage) : health(_health), damage(_damage) {}

    // Display function
    void display() const
    {
        std::cout << "Health: " << health << std::endl;
        std::cout << "Damage: " << damage << std::endl;
    }
};

// Derived class Enemy
class Enemy : public Character
{
public:
    // Constructor
    Enemy(int _health, int _damage) : Character(_health, _damage) {}

    // Display function
    void display() const
    {
        std::cout << "Enemy Details:" << std::endl;
        Character::display();
    }
};

// Derived class Player
class Player : public Character
{
public:
    // Constructor
    Player(int _health, int _damage) : Character(_health, _damage) {}

    // Display function
    void display() const
    {
        std::cout << "Player Details:" << std::endl;
        Character::display();
    }
};

// Derived class Wizard
class Wizard : public Player
{
private:
    int magicPower;
    std::string spells;

public:
    // Constructor
    Wizard(int _health, int _damage, int _magicPower, const std::string& _spells)
        : Player(_health, _damage), magicPower(_magicPower), spells(_spells) {}

    // Display function
    void display() const
    {
        std::cout << "Wizard Details:" << std::endl;
        Player::display();
        std::cout << "Magic Power: " << magicPower << std::endl;
        std::cout << "Spells: " << spells << std::endl;
    }
};

int main()
{
    // Create an object of Wizard and display its details
    Wizard wizard(100, 20, 50, "Fireball, Eyes flashing");
    wizard.display();

    return 0;
}









