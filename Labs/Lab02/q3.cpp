/*
 *Programmer: Layyana Junaid
 *Date: 6th Feb 2023
 *Description: Recursive function that checks whether the subset of the array sums to the target
 */

#include <iostream>
using namespace std;

// Function declaration
bool hasSubsetSum(int arr[], int size, int targetSum);

// Recursive function to check if there's a subset with the specified sum
bool hasSubsetSumHelper(int arr[], int size, int targetSum, int currentIndex) {
    // Base cases
    if (targetSum == 0)
        return true;
    if (currentIndex >= size)
        return false;

    // If the current element is greater than the target sum, we skip it
    if (arr[currentIndex] > targetSum)
        return hasSubsetSumHelper(arr, size, targetSum, currentIndex + 1);

    // Recur with two possibilities: include the current element or exclude it
    return hasSubsetSumHelper(arr, size, targetSum - arr[currentIndex], currentIndex + 1) || 
           hasSubsetSumHelper(arr, size, targetSum, currentIndex + 1);
}

// Wrapper function
bool hasSubsetSum(int arr[], int size, int targetSum) {
    return hasSubsetSumHelper(arr, size, targetSum, 0);
}

int main() {
    int arr[] = {3, 5, 2, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 9;

    if (hasSubsetSum(arr, size, targetSum))
        cout << "Subset with the sum exists." << endl;
    else
        cout << "No subset with the sum exists." << endl;

    return 0;
}
