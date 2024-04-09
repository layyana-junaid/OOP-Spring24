/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 9th April 24
 *Description: Lab 09 Q3
 */


#include <iostream>
#include <string>

class Employee {
protected:
    int employeeID;
    std::string employeeName;

public:
    Employee(int id, const std::string& name)
        : employeeID(id), employeeName(name) {}

    virtual ~Employee() {}

    virtual double calculatePay() const {
        return 0.0; // Default implementation
    }

    virtual void displayDetails() const {
        std::cout << "Employee ID: " << employeeID << ", Name: " << employeeName << std::endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(int id, const std::string& name, double salary)
        : Employee(id, name), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << "Type: Full-time, Monthly Salary: " << monthlySalary << std::endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyWage;
    int hoursWorked;

public:
    PartTimeEmployee(int id, const std::string& name, double wage, int hours)
        : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyWage * hoursWorked;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        std::cout << "Type: Part-time, Hourly Wage: " << hourlyWage << ", Hours Worked: " << hoursWorked << std::endl;
    }
};

int main() {
    FullTimeEmployee fullTimeEmployee(101, "Layyana", 5000);
    PartTimeEmployee partTimeEmployee(102, "Junaid", 15, 40);

    std::cout << "Displaying Details:" << std::endl;
    fullTimeEmployee.displayDetails();
    partTimeEmployee.displayDetails();

    std::cout << "\nCalculating Pay:" << std::endl;
    std::cout << "Full-time Employee Pay: $" << fullTimeEmployee.calculatePay() << std::endl;
    std::cout << "Part-time Employee Pay: $" << partTimeEmployee.calculatePay() << std::endl;

    // Using base class pointer to demonstrate polymorphic behavior
    Employee* empPtr = &fullTimeEmployee;
    std::cout << "\nUsing base class pointer to calculate Full-time Employee Pay: $" << empPtr->calculatePay() << std::endl;

    return 0;
}
