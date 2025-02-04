/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw0_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw0_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Min-Max and Median
 * Abstract: Outputs the minimum, the maximum, and the median of 5 numbers input
 * ID: 9908
 * Name: Jackie Luc
 * Date: 1/26/2025
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int num;
    std::vector<int> v;
    for(int i=0; i<5; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }

    std::sort(v.begin(), v.end());

    std::cout << "MIN: " << v[0] << "\nMAX: " << v[4] << "\nMEDIAN: " << v[2];

    return 0;
}

