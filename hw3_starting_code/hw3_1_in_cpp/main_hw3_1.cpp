/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw3_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw3_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Difference in Times
 * Abstract: Takes in two times that have hours, minutes, seconds, and am or pm. Always assumes the second time is the later time. 
    Outputs the difference in time.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/18/2025
 */

#include <iostream>

int main() 
{
    int firstHour, firstMinute, firstSecond, secondHour, secondMinute, secondSecond;
    char colon;
    std::string firstAmPm, secondAmPm;
    std::cin >> firstHour >> colon >> firstMinute >> colon >> firstSecond >> colon >> firstAmPm;
    std::cin >> secondHour >> colon >> secondMinute >> colon >> secondSecond >> colon >> secondAmPm;
    if(firstAmPm == "PM" && firstHour < 12)
        firstHour += 12;
    if(secondAmPm == "PM" && secondHour < 12)
        secondHour += 12;
    if(firstAmPm == "PM" && secondAmPm == "AM")
    {
        secondHour += 24;
    }
    if(secondMinute < firstMinute)
    {
        secondMinute += 60;
        ++firstHour;
    }
    if(secondSecond < firstSecond)
    {
        secondSecond += 60;
        ++firstMinute;
    }
    int resultHour = abs(firstHour - secondHour), resultMinute = abs(firstMinute - secondMinute), resultSecond = abs(firstSecond - secondSecond);
    if(resultHour == 0 && resultMinute == 0 && resultSecond == 0)
    {
        resultHour = 24;
    }
    if(resultHour < 10)
        std::cout << "0";
    std::cout << resultHour << ":";
    if(resultMinute < 10)
        std::cout << "0";
    std::cout << resultMinute << ":";
    if(resultSecond < 10)
        std::cout << "0";
    std::cout << resultSecond;
    return 0;
}
