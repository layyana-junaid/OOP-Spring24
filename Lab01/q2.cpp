/*
 *Programmer: Layyana Junaid
 *Date: 25th January 2024
 *Description: Writing a program in c++ to calculate the total marks of the students 
 */


#include <iostream>

using namespace std;

int main () {

int students;
int i;
int maths;
int eng;
int sci;
int sum = 0;
int avg = 0;

// asking user the number of students so the loop can work for that many times
cout << "Enter the number of students you entering data for: ";
cin >> students;

for (i = 0; i < students; i++) {
cout << "Enter the marks for English: ";
cin >> eng;
cout << "Enter the marks for Maths: ";
cin >> maths;
cout << "Enter the marks for Science: ";
cin >> sci;

sum = eng + maths + sci;

avg = sum / 3;

if ( avg < 60) {
cout << "Grade F" << endl;
}
else if ( avg > 60 && avg < 70) {
cout << "Grade D" << endl;
}
else if ( avg > 70 && avg < 80) {
cout << "Grade C" << endl;
}
else if ( avg > 80 && avg < 90) {
cout << "Grade B" << endl;
}
else if ( avg > 90 && avg < 101 ) {
cout << "Grade A" << endl;
}

cout << "Total Marks: " <<sum << endl;
cout << "Avg Marks: "  <<avg << endl;

} // end of for loop

} // end main


