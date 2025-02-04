/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw1_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw1_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Highest Frequency Number
 * Abstract: Outputs the number or numbers with the highest frequency within a given list of numbers.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/04/2025
 */

#include <iostream>
#include <map>
using namespace std;

int main() 
{
    int lines, maxFrequency = 1;
    std::map<int, int> m;
    std::cin >> lines;
    while(lines--)
    {
        int num;
        std::cin >> num;
        m[num]++;
        if(m[num] > maxFrequency)
            maxFrequency = m[num];
    }
    std::cout << "Frequency:" << maxFrequency << "\nNumber:";
    for(std::map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        if(iter->second == maxFrequency)
            std::cout << iter->first << " ";
    }
    return 0;
}

