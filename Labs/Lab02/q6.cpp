/*
 *Programmer: Layyana Junaid
 *Date: 7th Feb 2023
 *Description: Program to calculate LCM and GCD
 */

#include <iostream>
using namespace std;

// function to calculate GCD 
int calculateGCD(int n1, int n2) {
	if(n2 == 0) 
		return n1;
		return calculateGCD(n2, n1 % n2);
	
} // end of function 

// function to calculate LCM
int calculateLCM(int n1, int n2) {
	return(n1 * n2) / calculateGCD(n1, n2);
}// end of function

int main(int argc, char const *argv[])
{
	int num1, num2; // input from the user 

	cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    // display GCD and LCM
    cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << calculateLCM(num1, num2) << endl;

    return 0;

} // end main 