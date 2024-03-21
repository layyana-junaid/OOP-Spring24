/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 17th March 2024
 *Description: Lab06 Task 3
*/

#include <iostream>
#include <cstring>

// creating an appointment class
class Appointment
{
private:
std::string customerName;
float priceofServices;
public:
static int totalAppointments;
static float totalEarning;

//creating constructor
    Appointment(std::string name, float price) : customerName(name), priceofServices(price) {
        totalAppointments++;
        totalEarning += price;
    }
    
    // getters
    std::string getCustomerName() const {
        return customerName;
    }

    float getPriceOfServices() const {
        return priceofServices;
    }

    float getServiceCost() const {
        return priceofServices;
    }
//static function 
    static float getAverageCost() {
        return totalEarning / totalAppointments;
    }
};

int Appointment::totalAppointments = 0;
float Appointment::totalEarning = 0.0f;

int main() {
    // Create several instances of the Appointment class with different details
    Appointment appointment1("Layyana", 50.0f);
    Appointment appointment2("Alisha", 40.0f);
    Appointment appointment3("Emma", 60.0f);

    // Calculate the average cost of all appointments made
    float averageCost = Appointment::getAverageCost();

    // Display the average cost
    std::cout << "Average cost per appointment: $" << averageCost << std::endl;

    return 0;
}


