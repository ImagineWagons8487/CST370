/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw3_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw3_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Decimal, Binary, and The Items In A List
 * Abstract: Takes in an int, which is the size of the list of strings. Then takes in as many strings as the previous int provided. Then it outputs a list of strings
 in the format: decimal:binary:items. The decimal number is normal, the binary number to equal to the decimal number after conversion and the length is the same as the
 input size. The items are the index of the list where 1s are present in the binary number. When the decimal number is 0, the items section is "EMPTY".
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/19/2025
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

std::string decimalToBinary(int num, int length)
{
    if(length == 0)
        length = 1;
    std::string binary = "";
    while(num > 0)
    {
        char c = std::to_string(num%2)[0];
        binary.insert(0, 1, c); // binary.push_front(c)
        num /= 2;
    }
    while(binary.length() < length)
    {
        binary.insert(0, 1, '0'); // binary.push_front('0')
    }
    return binary;
}

int main() 
{
    int size, outputLength=0;
    std::cin >> size;
    std::vector<std::string> elementSet;
    for(int i = 0; i<size; ++i)
    {
        std::string s;
        std::cin >> s;
        elementSet.push_back(s);

        outputLength += std::pow(2, i);
    }
    std::cout << "0:" << decimalToBinary(0, size) << ":EMPTY\n";
    for(int i=1; i<=outputLength; ++i)
    {
        std::string binary = decimalToBinary(i, size);
        std::cout << i << ":" << binary << ":";
        for(int j=0; j<binary.length(); ++j)
        {
            if(binary[j] == '1')
            {
                std::cout << elementSet[j] << " ";
            }
        }
        std::cout << std::endl;
    }
    

    return 0;
}

