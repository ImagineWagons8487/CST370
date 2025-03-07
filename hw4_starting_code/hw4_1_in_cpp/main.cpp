/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw4_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw4_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Anagram Identifier
 * Abstract: Given two strings, check if they are an anagram. If they are, say that they are and output the characters and number of them.
 If they aren't, then say they aren't an anagram.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 03/04/2025
 */

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() 
{
    std::map<char, int> m1, m2;
    std::stringstream ss;
    ss << "ANAGRAM\n";
    std::string s1, s2;
    std::getline(cin, s1);
    std::getline(cin, s2);
    s1.erase(std::remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), ' '), s2.end());
    if(s1.length() != s2.length())
    {
        std::cout << "NO ANAGRAM\n";
        return 0;
    }
    for(int i=0; i<s1.length(); ++i)
    {
        m1[std::toupper(s1[i])]++;
        m2[std::toupper(s2[i])]++;
    } 
    for(std::map<char, int>::iterator iter = m1.begin(); iter != m1.end(); ++iter)
    {
        ss << iter->first << ":" << iter->second << "\n";
        if(iter->second != m2[iter->first])
        {
            std::cout << "NO ANAGRAM\n";
            return 0;
        }
    }
    std::cout << ss.str();
    return 0;
}

