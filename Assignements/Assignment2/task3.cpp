/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 31st March 2024
 *Description: creating daraz loyality program
*/

#include <iostream>
#include <string>

class DarazPersonData {
private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;

public:
    DarazPersonData() {}

    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getAddress() const { return address; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    std::string getZip() const { return zip; }
    std::string getPhone() const { return phone; }

    void setLastName(std::string last) { lastName = last; }
    void setFirstName(std::string first) { firstName = first; }
    void setAddress(std::string add) { address = add; }
    void setCity(std::string c) { city = c; }
    void setState(std::string s) { state = s; }
    void setZip(std::string z) { zip = z; }
    void setPhone(std::string ph) { phone = ph; }
};

class DarazCustomerData : public DarazPersonData {
private:
    int customerNumber;
    int loyaltyPoints;

public:
    DarazCustomerData() {}

    int getCustomerNumber() const { return customerNumber; }
    int getLoyaltyPoints() const { return loyaltyPoints; }

    void setCustomerNumber(int num) { customerNumber = num; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }
};

class DarazLoyaltyProgram {
public:
    static void addLoyaltyPoints(DarazCustomerData& customer, int points) {
        if (points > 0) {
            int currentPoints = customer.getLoyaltyPoints();
            customer.setLoyaltyPoints(currentPoints + points);
        }
    }

    static void redeemLoyaltyPoints(DarazCustomerData& customer, int points) {
        int currentPoints = customer.getLoyaltyPoints();
        if (points <= currentPoints && points > 0) {
            customer.setLoyaltyPoints(currentPoints - points);
            std::cout << "Redeemed " << points << " points successfully.\n";
        } else {
            std::cout << "Invalid loyalty points or not enough points to redeem.\n";
        }
    }

    static void displayTotalLoyaltyPoints(const DarazCustomerData& customer) {
        std::cout << "Total loyalty points for customer " << customer.getCustomerNumber() << ": "
                  << customer.getLoyaltyPoints() << std::endl;
    }
};

int main() {

    std::cout << "Layyana Junaid [23k0056]" << std::endl;
    DarazCustomerData customer;
    customer.setCustomerNumber(12345);
    customer.setFirstName("Layyana");
    customer.setLastName("Junaid");
    customer.setLoyaltyPoints(200);

    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

    DarazLoyaltyProgram::addLoyaltyPoints(customer, 70);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

    DarazLoyaltyProgram::redeemLoyaltyPoints(customer, 85);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

    return 0;
}
