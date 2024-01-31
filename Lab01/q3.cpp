/*
 *Programmer: Layyana Junaid
 *Date: 31st January 2024
 *Description: Writing a program in c++ to find the target number using the numbers present in an array
 */


#include<iostream>
#include<vector>

using namespace std;

    vector<int> Sum(vector<int>& num, int target) {
    for(size_t i = 0; i < num.size() - 1 ; i++) {
        for(size_t j = i + 1; j < num.size(); j++) {
            if(num[i] + num[j] == target) {
                return { (int)i , (int)j };
            }
        }
    }
    return {}; // no solution found
} // end of sum 

int main () {
    vector<int> num = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = Sum(num, target);

    if(result.size() == 2) {
        cout<< "Output: [" << result[0] << "," << result[1] << "] "<<endl;
    }
    else {
        cout<< "No Solution Found!"<<endl;
    }

    return 0;

} // end main 