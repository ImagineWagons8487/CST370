/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw0_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw0_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Sum and Difference
 * Abstract: Outputs the sum and difference of two numbers from input
 * ID: 9908
 * Name: Jackie Luc
 * Date: 1/26/2025
 */

#include <iostream>
using namespace std;

int main() 
{
    int x, y;
    std::cin >> x >> y;
    std::cout << "SUM: " << x+y << "\nDIFF: ";
    if(x-y > 0)
        std::cout << x-y;
    else
        std::cout << y-x;
    return 0;
}

