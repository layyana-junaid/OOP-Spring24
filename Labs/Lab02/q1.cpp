/*
 *Programmer: Layyana Junaid
 *Date: 6th Feb 2023
 *Description: Swapping numbers using recursion
 */

#include <iostream>

using namespace std;

void recursiveSwap(int &n1, int &n2) {
	if(&n1 == &n2) 
		return;
	// swapping the values using recursive calls 
	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;
} // end of recursiveSwap 

int main(int argc, char const *argv[])
{
	int n1 = 5;
	int n2 = 10;

	cout << "Before Swapping: 1st Number = " << n1 << " 2nd Number = " << n2 << endl;

	swap(n1, n2);

	cout << "After Swapping: 1st Number = " << n1 << " 2nd Number = " << n2 << endl;

    return 0;
}