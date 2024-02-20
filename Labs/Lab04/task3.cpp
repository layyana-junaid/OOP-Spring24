/*
 *Programmer: Layyana Junaid
 *Date: 15th Feb 2024
 *Description: Lab 4

*/

#include <iostream>
#include <string>

using namespace std;

// creating a class for week days
class WeekDays
{
private:
    string days[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday"} ;
    int currentDay;
public:
//setting up default constructor
WeekDays() {
    currentDay = 0; // 0 means it is sunday because its position is 0 in array
}

//setting up parameterized constructor
WeekDays(int day) {
    currentDay = day % 7;
} 
   
// getter functions
// this will return the value of current day in string format
string getCurrentDay() {
    return days[currentDay];
}

//this will return the value of the next day 
string getNextDay(){
    return days[(currentDay + 1) % 7];
}

// this will return the value of the previous day in string format
string getPrevious() {
    return days[(currentDay + 6) % 7];
}

//this will return the value of the day 'n' days from today
string getnthDay(int n) {
    return days[(currentDay + n) % 7];
}

};
// end of class

int main(int argc, char const *argv[])
{
    WeekDays week(3); // keeping today wednesday

    cout << "Today is " << week.getCurrentDay() << endl;
    cout << "Next day is " << week.getNextDay() << endl;
    cout << "Previous day was " << week.getPrevious() << endl;
    cout << "11 days from today will be " << week.getnthDay(11) << endl;

    return 0;
} // end main

