/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 30th March 2024
 *Description: creating an inheritance hierachy for gaming enviroment
 */

#include <iostream>
#include <string>

class Player
{
public:
    int playerId;
    std::string playerName;
    int health;

    Player(int id, std::string name, int h = 100) : playerId(id), playerName(name), health(h) {}

    int getHealth()
    {
        return health;
    }
};

class Weapon
{
private:
    std::string weaponList[5];

public:
    Weapon()
    {
        weaponList[0] = "Shotgun";
        weaponList[1] = "Knives";
        weaponList[2] = "Balloon Bombs";
        weaponList[3] = "Fire balls";
        weaponList[4] = "Lazer gun";
    }

    void Use() const
    {
        std::cout << "List of Weapons: " << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << i + 1 << ". " << weaponList[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Character : public Player
{
private:
    int level;
    std::string experience;
    int points;

public:
    Character(int id, std::string name)
        : Player(id, name), level(0), experience("Beginner"), points(0) {}

    void LevelUp()
    {
        points += 10;

        if (points >= 10 && experience == "Beginner")
        {
            experience = "Intermediate";
            std::cout << "You are now an Intermediate player." << std::endl;
        }

        else if (points >= 20 && experience == "Intermediate")
        {
            experience = "Advanced";
            std::cout << "You are now an Advanced player." << std::endl;
        }

        else if (points >= 30 && experience == "Advanced")
        {
            experience = "Expert";
            std::cout << "You are now an Expert player." << std::endl;
        }
    }

    void playGame()
    {
        std::cout << "Game in process...." << std::endl;
        Weapon weapon; // Create an instance of the Weapon class
        weapon.Use();  // Use the weapon list

        // Creating a logic which will decrement the health point
        health -= 10;

        std::cout << "Updated Health: " << health << std::endl;
    }
};

class Enemy
{
private:
    int damage;

public:
    Enemy(int d) : damage(d) {}

    void attack(Character &player)
    {
        std::cout << "Enemy attacks with damage " << damage << std::endl;
        player.health -= damage;
        std::cout << "Player health after attack: " << player.getHealth() << std::endl;
    }
};

int main()
{

    std::cout << "Layyana Junaid [23k0056]" << std::endl;

    Character player1(1, "Layyana");
    Character player2(2, "Habib");
    Character player3(3, "Abdullah");

    player1.playGame();
    Enemy enemy1(5);
    enemy1.attack(player1);
    player1.LevelUp();
    std::cout << std::endl;

    player2.playGame();
    Enemy enemy2(10);
    enemy2.attack(player2);
    player2.LevelUp();
    std::cout << std::endl;

    player3.playGame();
    Enemy enemy3(4);
    enemy3.attack(player3);
    player3.LevelUp();
    std::cout << std::endl;

    return 0;
}
