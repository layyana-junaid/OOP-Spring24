/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 17th March 2024
 *Description: Lab06 Task 5
 */

#include <iostream>
#include <string>

class Course
{
private:
    std::string courseCode;
    std::string courseName;
    int creditHours;

public:
    Course(const std::string& code, const std::string& name, int hours)
        : courseCode(code), courseName(name), creditHours(hours) {}

    const std::string& getCourseCode() const { return courseCode; }
    const std::string& getCourseName() const { return courseName; }
    int getCreditHours() const { return creditHours; }
};

class Student
{
private:
    std::string studentID;
    std::string studentName;
    Course** enrolledCourses;
    int numEnrolledCourses;
    static const int MAX_COURSES = 5; // Maximum number of courses a student can enroll in

public:
    Student(const std::string& id, const std::string& name)
        : studentID(id), studentName(name), numEnrolledCourses(0)
    {
        enrolledCourses = new Course*[MAX_COURSES];
    }

    ~Student()
    {
        for (int i = 0; i < numEnrolledCourses; ++i)
        {
            delete enrolledCourses[i];
        }
        delete[] enrolledCourses;
    }

    void enroll(Course* course)
    {
        if (numEnrolledCourses < MAX_COURSES)
        {
            enrolledCourses[numEnrolledCourses++] = course;
        }
        else
        {
            std::cout << "Cannot enroll in more courses." << std::endl;
        }
    }

    void drop(Course* course)
    {
        for (int i = 0; i < numEnrolledCourses; ++i)
        {
            if (enrolledCourses[i] == course)
            {
                delete enrolledCourses[i];
                for (int j = i; j < numEnrolledCourses - 1; ++j)
                {
                    enrolledCourses[j] = enrolledCourses[j + 1];
                }
                enrolledCourses[--numEnrolledCourses] = nullptr;
                return;
            }
        }
        std::cout << "Course not found in enrolled courses." << std::endl;
    }

    int getTotalCreditHours() const
    {
        int total = 0;
        for (int i = 0; i < numEnrolledCourses; ++i)
        {
            total += enrolledCourses[i]->getCreditHours();
        }
        return total;
    }

    void printEnrolledCourses() const
    {
        for (int i = 0; i < numEnrolledCourses; ++i)
        {
            std::cout << "Course Code: " << enrolledCourses[i]->getCourseCode() << std::endl;
            std::cout << "Course Name: " << enrolledCourses[i]->getCourseName() << std::endl;
            std::cout << "Credit Hours: " << enrolledCourses[i]->getCreditHours() << std::endl;
            std::cout << std::endl;
        }
    }
};

int main()
{
    Course* course1 = new Course("CL1004", "Object Oriented Programming", 3);
    Course* course2 = new Course("CL0042", "OOP-Theory", 3);

    Student student("230056", "Layyana");
    student.enroll(course1);
    student.enroll(course2);

    std::cout << "Total Credit Hours: " << student.getTotalCreditHours() << std::endl;
    student.printEnrolledCourses();

    student.drop(course1);

    std::cout << "Total Credit Hours after dropping course1: " << student.getTotalCreditHours() << std::endl;
    student.printEnrolledCourses();

    delete course1;
    delete course2;

    return 0;
}
