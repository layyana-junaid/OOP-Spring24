/*
 *Programmer: Layyana Junaid 
 *Date: 9th February 2024
 *Description: Making a Water bottle class
 */

#include <iostream>
#include <string>
using namespace std;

// creating a water bottle class to store its attributes
class WaterBottle
{
private:
	string company;
	string colour;
	int capacityLiters;
	int capacityMilli;
public:
	// using getter and setter methods to set values 
	string getCompany() {
        return company;
    }
    
    void setCompany(string company) {
        this->company = company;
    }
    
    string getColour() {
        return colour;
    }
    
    void setColor(string colour) {
        this->colour = colour;
    }
    
    int getCapacityLiters() {
        return capacityLiters;
    }
    
    void setCapacityLiters(int capacityLiters) {
        this->capacityLiters = capacityLiters;
    }
    
    int getCapacityMilliliters() {
        return capacityMilli;
    }

    void setCapacityMilliliters(int capacityMilli) {
        this->capacityMilli = capacityMilli;
    }

    // function to update the water capacity after the user has used it
    void WaterConsumed(int consumedMilli) {
        int totalMilli = capacityLiters * 1000 + capacityMilli;
        totalMilli -= consumedMilli;

        if (totalMilli < 0) {
            cout << "You have consumed the entire water!" << endl;
        } else {
            capacityLiters = totalMilli / 1000;
            capacityMilli = totalMilli % 1000;
            cout << "Water consumed. Remaining capacity: " << capacityLiters << " liters and " << capacityMilli << " milliliters" << endl;
        }
    }
}; // end of class

int main() {
    // Creating a WaterBottle object and setting attributes
    WaterBottle bottle;
    bottle.setCompany("XYZ Company");
    bottle.setColor("Blue");
    bottle.setCapacityLiters(1);
    bottle.setCapacityMilliliters(500);

    // printing initial information
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColour() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << " liters and " << bottle.getCapacityMilliliters() << " milliliters" << endl;

    // calling water consumption function
    int consumedMilli;
    cout << "Enter amount of water consumed (in milliliters): ";
    cin >> consumedMilli;

    // updating water capacity
    bottle.WaterConsumed(consumedMilli);

    return 0;
} // end main

	


