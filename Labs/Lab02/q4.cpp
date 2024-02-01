/*
 *Programmer: Layyana Junaid
 *Date: 1st Feb 2023
 *Description: Student Data Management System
 */


#include<iostream>
#include<string>

using namespace std;

// defining structure for register
struct Register {
	int courseId;
	string courseName;
};

// defining structure for students
struct Student : Register {
	int studentId;
	string firstName;
	string lastName;
	int cellNo;
	string email;		
};






int main() {
	
	// creating an array to store the data of 5 students 
	Student students[5];
	
	//loop for storing data for 5 students
	for(int i = 0; i < 5; i++) {
		cout << "Enter the Student Data" << i + 1 << ":" << endl;
		
		cout << "Course ID: ";
		cin >> students[i].courseId;
		
		cout << "Course Name: ";
		getline(cin, students[i].courseName);
		
		cout << "First Name: ";
		cin >> students[i].firstName;
		
		cout << "Last Name: ";
		cin >> students[i].lastName;
		
		cout << "Cell Number: ";
		cin >> students[i].cellNo;
		
		cout << "Email: ";
		cin >> students[i].email;
		
		cout << "\n"; 
							
	} // end of for loop
	
	// displaying data fot the students 
	for(int i = 0; i < 5; i++) {
		cout << "Student" << i + 1 << ":" << endl;
		
		cout << "Course ID: " << students[i].courseId << endl;
		
		cout << "Course Name: " << students[i].courseName << endl;
		
		cout << "First Name: " << students[i].firstName << endl;
		
		cout << "Last Name: " << students[i].lastName << endl;
		
		cout << "Cell Number: " << students[i].cellNo << endl;
		
		cout << "Email: " << students[i].email << endl; 
							
	} // end of for loop
	
	return 0;	
}