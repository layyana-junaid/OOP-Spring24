/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 21 March 23
 *Description: Lab 8 Task 4
*/
#include <iostream>
#include <string>

// Creating base class 'person'
class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    void Display() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

// Derived class student
class Student : public Person {
private:
    std::string studentID;
    int gradeLevel;
public:
    Student(std::string id, int level, std::string n, int a)
        : studentID(id), gradeLevel(level), Person(n, a) {}

    void Display() {
        Person::Display(); // using scope resolution operator to call the base class function
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Grade Level: " << gradeLevel << std::endl;
    }
};

class Teacher : public Person {
private:
    std::string subject;
    int room;
public:
    Teacher(std::string sub, int r, std::string n, int a)
        : subject(sub), room(r), Person(n, a) {}

    void Display() {
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Room: " << room << std::endl;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(std::string name, int age, std::string id, int level, std::string sub, int r)
        : Student(id, level, name, age), Teacher(sub, r, name, age) {}

    void Display() {
        std::cout << "Graduate Student Details: " << std::endl;
        Student::Display();
        Teacher::Display();
    }

};

int main() {
    GraduateStudent grad("Layyana Junaid", 20, "23k0056", 2, "Object-Oriented", 1);

    grad.Display();

    return 0;
}
