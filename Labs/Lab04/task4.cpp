/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 20th Feb 2024
 *Description: Writing a program to make a office class and implement parameterized constructors to  
 * add values and then display them for multiple instances 
 */

#include <iostream>
#include <string>

using namespace std;

// creating the office class
class Office
{
private:
   string Location;
   int SeatingCapacity;
   string Furniture[3];
public:
// assigning default values to parameterized constructors
    Office(string location = "" , int seatingCapacity = 0 , string furniture[3] = {}) : Location(location) , SeatingCapacity(seatingCapacity)
    {
        for(int i = 0; i < 3; i++) {
            Furniture[i] = furniture[i];
        }
    } // end of parameterized Constructor

    // creating a function to display the details of the office class 
    void DisplayOffice() {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furnitures present: ";
        for(int i = 0; i < 3; i++) {
            cout << Furniture[i] << ",";
        }
        cout << endl;
    }
    ~Office(){}
}; // end of office class

int main(int argc, char const *argv[])
{
    // creating objects to display different offices data 
    string furniture1[3] = {"Desk", "PCs", "Chairs"};
    string furniture2[3] = {"Stationery", "Desk", "Chairs"};
    
    Office office1("Clifton", 65, furniture1);
    Office office2("Gulshan", 45, furniture2);

    cout << "Office 1 Details: " << endl;
    office1.DisplayOffice();

    cout << "Office 2 Details: " << endl;
    office2.DisplayOffice();

    return 0;
} // end main
