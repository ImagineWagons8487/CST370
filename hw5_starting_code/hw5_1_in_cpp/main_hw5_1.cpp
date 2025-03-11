/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw5_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw5_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Sorted numbers with ranges
 * Abstract: Takes in a number and then that number of numbers. Sorts them and outputs them. If there are numbers that are directly next to each other,
 * the program will output a range of between those numbers instead.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 03/11/2025
 */

#include <iostream>
#include <set>

int main() 
{
    std::set<int> s;
    int num;
    std::cin >> num;
    while(num--)
    {
        int temp;
        std::cin >> temp;
        s.insert(temp);
    }
    std::set<int>::iterator i = s.begin();
    std::cout << *i;
    int prev = *i;
    i++;
    while(i != s.end())
    {
        if(*i - prev == 1)
        {
            std::cout << "-";
            while(*i-prev == 1 && i != s.end())
            {
                prev = *i;
                i++;
            }
            std::cout << prev << " ";
        }
        else
        {
            std::cout << " ";
        }
        if(i != s.end())
        {
            std::cout << *i;
            prev = *i;
            i++;
        }
    }
    return 0;
}

