/*
 *Programmer: Layyana Junaid
 *Date: 10th Feb 2024
 *Description: Creating a Calender class
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// creating a struct to store the task maintaining stuff
struct Task
{
    string taskDescription;
    int date;
    int month;
};

// defining the calendar class
class Calendar
{
    int year; // not using the private parameter as class is by default private

    vector<Task> tasks; // vector to store tasks

public:
    Calendar(int currentYear) : year(currentYear) {} // Constructor

    // function to add task in the calendar
    void addTask(int day, int month, const string &description)
    {
        Task newTask = {description, day, month};
        tasks.push_back(newTask); // this function adds new element to the end of the vector
    }

    // function to remove the tasks
    void removeTask(int day, int month)
    {
        for (auto it = tasks.begin(); it != tasks.end(); it++)
        {
            if (it->date == day && it->month == month)
            {
                tasks.erase(it);
                break; // stop searching
            }
        }
    }

    // function to display tasks
    void displayTasks()
    {
        cout << "Tasks for the year " << year << ":" << endl;
        for (int i = 1; i <= 12; i++)
        {
            cout << "Task for " << getMonthName(i) << ":" << endl;
            for (const auto &task : tasks)
            {
                if (task.month == i)
                {
                    cout << "  Day " << task.date << ": " << task.taskDescription << endl;
                }
            }
        }
    }

    // function to add or remove tasks based on user choice
    void manageTasks()
    {
        int choice;
        cout << "Select operation:\n1. Add Task\n2. Remove Task\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int day, month;
            string description;
            cout << "Enter task details:\n";
            cout << "Day: ";
            cin >> day;
            cout << "Month: ";
            cin >> month;
            cout << "Description: ";
            cin.ignore();
            getline(cin, description);
            addTask(day, month, description);
            cout << "Task added successfully!\n";
            break;
        }
        case 2:
        {
            int day, month;
            cout << "Enter task details to remove:\n";
            cout << "Day: ";
            cin >> day;
            cout << "Month: ";
            cin >> month;
            removeTask(day, month);
            cout << "Task removed successfully!\n";
            break;
        }
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }

private:
    // creating a function to get access to months by their numbers (e.g., 1 = Jan)
    string getMonthName(int month)
    {
        switch (month)
        {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
        }
    }
};

// end of class

int main(int argc, char const *argv[])
{
    // creating a calendar object for the current year
    Calendar calendar(2024);


    // using switch case so that the user can edit and delete tasks
    int choice;
    do
    {   
    	cout << "Calendar Maintaining System: " << endl;
        cout << "1.Add Task\n2.Remove Task\n3.Display Tasks\n4.Exit" << endl;
        cout << "Select your option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            calendar.manageTasks();
            break;
        case 2:
            calendar.manageTasks();
            break;
        case 3:
            calendar.displayTasks();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
