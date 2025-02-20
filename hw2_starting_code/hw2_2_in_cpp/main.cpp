/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw2_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw2_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Palindrome Verifier
 * Abstract: Takes in a string, verifies if it is a palindrome. If it isn't, outputs the first mismatching letter.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/10/2025
 */

#include <iostream>
#include <cctype>
using namespace std;

int main() 
{
    std::string s;
    std::cin >> s;
    int low = 0, high = s.length()-1;
    while(low <= high)
    {
        while(!std::isalnum(s[low]))
            low++;
        while(!std::isalnum(s[high]))
            high--;
        if(std::tolower(s[low]) != std::tolower(s[high]))
        {
            std::cout << "NO:" << (char)std::toupper(s[low]);
            return 0;
        }
        low++;
        high--;
    }
    std::cout << "PALINDROME";
    return 0;
}

