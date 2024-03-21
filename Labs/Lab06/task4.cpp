/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 17th March 2024
 *Description: Lab06 Task 4
 */

#include <iostream>
#include <string>

// creating inline function to calculate the batting average
inline float battingAverage(int totalRuns, int totalDismissals)
{
    if (totalDismissals == 0)
    {
        return 0.0;
    }
    else
    {
        return static_cast<double>(totalRuns) / totalDismissals;
    }
}

//creating inline function to calculate the strike rate
inline float strikeRate(int totalRuns, int ballsFaced)
{
    float temp = totalRuns / ballsFaced;
    float strikeRate = temp * 100;

    return strikeRate;
}

int main(int argc, char const *argv[])
{
    int totalRuns, totalDismissals, ballsFaced;

    //taking the input from the user
    std::cout << "Enter the total number of runs scored: " << std::endl;
    std::cin >> totalRuns;
    std::cout << "Enter the number of balls faced: " << std::endl;
    std::cin >> ballsFaced;
    std::cout << "Enter total number of dismissals:  " << std::endl;
    std::cin >> totalDismissals;

    float BatAvg = battingAverage(totalRuns, totalDismissals);
    float StrikeR = strikeRate(totalRuns, ballsFaced);

    std::cout << "Batting Average: " << BatAvg << std::endl;
    std::cout << "Strike Rate: " << StrikeR << std::endl;

    return 0;
}
