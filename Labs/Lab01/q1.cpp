/*
 *Programmer: Layyana Junaid
 *Date: 25th January 2024
 *Description: Writing a program in c++ to evaluate prime numbers 
 */

#include <iostream>

using namespace std;
int main()
{
int ans = 0;
    int x = 0;
    int i;
    cout<< "Enter an integer: ";
    cin >> x;
    for ( i = 2; i*i <= x; i++ ) {
   
    if(x == 1 || x == 0 ) {
    cout<< "Not a prime number!";
}
else if(x % 1 == 0 ) {
ans++;
}

}
    if ( ans > 2) {
cout << "is not prime";
}
else {
cout << "is a prime";
}

} // end main 

