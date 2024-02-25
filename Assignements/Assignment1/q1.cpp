/*
*Programmer: Layyana Junaid (23k0056)
*Date: 20th Feb 2024
*Description: Creating a pet and adopter class and representing the information of pets along with the pets that
get adopted, and adopters information
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::find

// creating the pet class
class Pet
{
private:
    std::string healthStatus;
    int hungerLevel;
    int happinessLevel;
    std::vector<std::string> specialSkills;

public:
    Pet(std::string healthStatus, int hungerLevel, int happinessLevel, std::vector<std::string> specialSkills)
    {
        this->healthStatus = healthStatus;
        this->hungerLevel = hungerLevel;
        this->happinessLevel = happinessLevel;
        this->specialSkills = specialSkills;
    }

    std::vector<std::string> getSpecialSkills() const
    {
        return specialSkills;
    }

    int getHappinessLevel() const
    {
        return happinessLevel;
    }

    int getHungerLevel() const
    {
        return hungerLevel;
    }

    std::string getHealthStatus() const
    {
        return healthStatus;
    }

    void displayPetDetails() const
    {
        std::cout << "Health Status: " << healthStatus << std::endl;
        std::cout << "Hunger Level: " << hungerLevel << std::endl;
        std::cout << "Happiness Level: " << happinessLevel << std::endl;
        std::cout << "Special Skills: ";
        for (const std::string &skill : specialSkills)
        {
            std::cout << skill << ", ";
        }
        std::cout << std::endl;
    }

    void updateHappiness()
    {
        if (hungerLevel > 0)
        {
            happinessLevel--;
        }
        else if (happinessLevel < 10)
        {
            happinessLevel++;
        }
    }

    void updateHealth()
    {
        if (healthStatus == "Healthy")
        {
            if (happinessLevel < 5 || hungerLevel > 5)
            {
                healthStatus = "Sick";
            }
        }
        else
        {
            if (happinessLevel > 5 && hungerLevel < 5)
            {
                healthStatus = "Healthy";
            }
        }
    }

    void updateHunger()
    {
        if (hungerLevel > 0)
        {
            hungerLevel--;
        }
        else
        {
            hungerLevel++;
        }
        updateHappiness();
        updateHealth();
    }
};

// creating an adopter class
class Adopter
{
private:
    std::string adopterName;
    std::string adopterMobileNum;
    std::vector<Pet *> adoptedPetRecords;

public:
    Adopter(std::string adopterName, std::string adopterMobileNum)
    {
        this->adopterName = adopterName;
        this->adopterMobileNum = adopterMobileNum;
    }

    void adoptPet(Pet *pet)
    {
        adoptedPetRecords.push_back(pet);
    }

    void returnPet(Pet *pet)
    {
        auto it = std::find(adoptedPetRecords.begin(), adoptedPetRecords.end(), pet);
        if (it != adoptedPetRecords.end())
        {
            adoptedPetRecords.erase(it);
        }
    }

    void displayAdoptersinfo()
    {
        std::cout << "Adopted by: " << adopterName << std::endl;
        std::cout << "Adopter's Phone number: " << adopterMobileNum << std::endl;
    }

    void displayAdoptedPets() const
    {
        std::cout << "Adopted Pets:" << std::endl;
        for (Pet *pet : adoptedPetRecords)
        {
            pet->displayPetDetails();
        }
    }
};

int main()
{
    // creating objects and assiging values in it
    Pet cat("Healthy", 5, 8, {"Jumping", "Purring"});
    Pet dog("Healthy", 6, 7, {"Fetching", "Barking"});

    Adopter adopter1("Habib Ur Rehman", "1234567890");
    Adopter adopter2("Layyana Junaid", "0987654321");

    adopter1.adoptPet(&cat);
    adopter2.adoptPet(&dog);
    // printing the information of the adopted pets
    adopter1.displayAdoptedPets();
    adopter1.displayAdoptersinfo();
    adopter2.displayAdoptedPets();
    adopter2.displayAdoptersinfo();

    return 0;
}
