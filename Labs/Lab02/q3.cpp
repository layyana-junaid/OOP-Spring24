/*
 *Programmer: Layyana Junaid
 *Date: 7th Feb 2023
 *Description: Recursive function that checks whether the subset of the array sums to the target
 */

#include <iostream>
using namespace std;

// Recursive function to check if there's a subset with the specified sum
bool hasSubsetSum(int arr[], int size, int targetSum) {
    // Base cases
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;

    // If the last element is greater than the target sum, exclude it
    if (arr[size - 1] > targetSum)
        return hasSubsetSum(arr, size - 1, targetSum);

    // Recur with two possibilities: include the last element or exclude it
    return hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]) || 
           hasSubsetSum(arr, size - 1, targetSum);
}

int main() {
    int arr[] = {3, 5, 2, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 8;

    if (hasSubsetSum(arr, size, targetSum)) {
        cout << "Subset with the sum exists." << endl;
        cout << "TRUE!" << endl;
    }
    else {
        cout << "No subset with the sum exists." << endl;
        cout << "FALSE!" << endl;
    }
    return 0;
}
