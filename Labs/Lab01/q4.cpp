/*
 *Programmer: Layyana Junaid
 *Date: 31st January 2024
 *Description: Question 4 of Lab 01
 */


#include <iostream>
#include <vector>

using namespace std;

int MaxArea(vector<int>& height) {
	int MaxWater = 0;
	int left = 0;
	int right = height.size() - 1;

	while (left < right) {
		int h = height[left] < height[right] ? height[left] : height[right];
		int w = right - left;

		int CurrentWater = h * w;
		MaxWater = CurrentWater > MaxWater ? CurrentWater : MaxWater;

		if( height[left] < height[right]) {
			left++;
		}
		else {
			right--;
		}
	}

	return MaxWater;

} // end of MaxArea

int main(int argc, char const *argv[])
{
	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

	int result = MaxArea(height);

	cout<<"Output: " << result <<endl;

	return 0;
}
