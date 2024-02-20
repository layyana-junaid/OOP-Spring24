/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 20th Feb 2024
 *Description: Writing a program to make a office class and replacing the furniture array with the pointer
 */

#include <iostream>
#include <string>

using namespace std;

// creating office class by replacing the furniture array to furniture pointer
class Office
{
private:
    string Location;
    int SeatingCapacity;
    string *Furniture;

public:
    // in parameterized constructer , furniture pointer will accept the size of furniture array instead of array itself
    Office(string location = "", int seatingCapacity = 0, int furnitureSize = 3) : Location(location), SeatingCapacity(seatingCapacity)
    {
        Furniture = new string[furnitureSize]; // allocating memory
        for (int i = 0; i < furnitureSize; i++)
        {
            Furniture[i] = "";
        }
    }

    // creating a set furniture function
    void setFurniture(int index, string item)
    {
        if (index >= 0 && index < 3)
        {
            Furniture[index] = item;
        }
    }

    // creating a function to display the details of the office class
    void DisplayOffice()
    {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furnitures present: ";
        for (int i = 0; i < 3; i++)
        {
            cout << Furniture[i] << ",";
        }
        cout << endl;
    }

    // creating a destructor
    ~Office() {
        delete[] Furniture; // deallocating memory
    }
};

int main(int argc, char const *argv[])
{
    Office *office = new Office("Clifton", 65);
    
    // using arrows as we are alloacting memory and dealing with pointers
    office->setFurniture(0, "Desk");
    office->setFurniture(1,"PCs");
    office->setFurniture(2, "Chairs");

    office->DisplayOffice();
    
    //calling destructor
    delete office;

    return 0;
}
