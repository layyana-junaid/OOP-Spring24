/*
 *Programmer: Layyana Junaid 
 *Date: 9th February 2024
 *Description: Making a board marker class and storing its subsequent charactersticts
 */

#include <iostream>
#include <string>
using namespace std;


// creating a boardmarker class
class BoardMarker
{
private:
	string Brand;
	string Shade;
	bool Refillable;
	bool InkStatus;

public:
    // using getter and setter method we will directly set values
    string getBrand() {
        return Brand;
    }
    
    void setBrand(string Brand) {
        this->Brand = Brand;
    }
    
    string getShade() {
        return Shade;
    }
    
    void setShade(string Shade) {
        this->Shade = Shade;
    }
    
    bool isRefillable() {
        return Refillable;
    }
    
    void setRefillable(bool Refillable) {
        this->Refillable = Refillable;
    }
    
    bool isInkDepleted() {
        return !InkStatus;
    }
    
    void setInkStatus(bool InkStatus) {
        this->InkStatus = InkStatus;
    }

    // writing method to check if the ink has run out or not
    void write() {
        if (isInkDepleted()) {
            cout << "The ink has run out. Please refill the marker." << endl;
        } else {
            cout << "Sufficent amount of ink is present." << endl;
        }
    }

    // refill method to check if the marker is refillable or not 
    void refill() {
        if (isRefillable()) {
            cout << "Refilling the board marker." << endl;
            setInkStatus(true); // Refill the ink
        } else {
            cout << "This marker cannot be refilled." << endl;
        }
    }
	
}; // end of class


int main() {
    // creating an object and setting values in it directly
    BoardMarker marker;
    marker.setBrand("Dollar");
    marker.setShade("black");
    marker.setRefillable(true);
    marker.setInkStatus(true);

    // using the getter method
    cout << "Brand: " << marker.getBrand() << endl;
    cout << "Shade: " << marker.getShade() << endl;
    cout << "Refillable: " << (marker.isRefillable() ? "Yes" : "No") << endl;
    cout << "Ink Status: " << (marker.isInkDepleted() ? "Depleted" : "Not Depleted") << endl;

    // calling the writing marker function
    marker.write();

    // calling the refilling marker function
    marker.refill();
    marker.write();

    return 0;
}