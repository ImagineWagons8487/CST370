/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw1_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw1_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Non-intersecting Lists
 * Abstract: Given two groups of numbers, outputs all the numbers that are not common between the two groups
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/04/2025
 */

#include <iostream>
#include <set>
using namespace std;


void populateSet(std::set<int> &s)
{
    int lines;
    std::cin >> lines;
    for(int i=0; i<lines; i++)
    {
        int num;
        std::cin >> num;
        s.insert(num);
    }
}

int main() 
{
    std::set<int> s1, s2;
    populateSet(s1); populateSet(s2);
    for(std::set<int>::iterator iter = s2.begin(); iter != s2.end(); iter++)
    {
        if(s1.find(*iter) != s1.end())
            s1.erase(*iter);
        else
            s1.insert(*iter);
    }
    std::cout << "Answer:";
    if(s1.empty())
        std::cout << "NONE";
    else
    {
        for(std::set<int>::reverse_iterator riter = s1.rbegin(); riter != s1.rend(); riter++)
        {
            std::cout << *riter << " ";
        }
    }
    return 0;
}

