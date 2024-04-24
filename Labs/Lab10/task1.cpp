/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 18th April 2023
 *Description: Lab10 task 1
 */

#include <iostream>
#include <string>

class Platform; // Forward declaration

class Logo {
private:
    std::string logo;
public:
    Logo(std::string l) : logo(l) {}

    friend class Platform;
};

class Platform {
private:
    std::string name;
    Logo logo;
    std::string serverType;
public:
    Platform(std::string n, Logo l, std::string s) : name(n), logo(l), serverType(s) {}

    void display() {
        std::cout << "Platform: " << name << std::endl;
        std::cout << "Logo: " << logo.logo << std::endl;
        std::cout << "Server Type: " << serverType << std::endl;
    }

    void changeLogo(std::string newLogo) {
        logo.logo = newLogo;
    }
};

int main() {
    Logo twitterLogo("Blue Bird");
    Platform twitter("Twitter", twitterLogo, "Cloud");

    // Display original logo
    std::cout << "Original Logo:" << std::endl;
    twitter.display();

    // Change logo to Dogecoin
    twitter.changeLogo("Doge Coin");

    // Display modified logo
    std::cout << "\nModified Logo:" << std::endl;
    twitter.display();

    return 0;
}
