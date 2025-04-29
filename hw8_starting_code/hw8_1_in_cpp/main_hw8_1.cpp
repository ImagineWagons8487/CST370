/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw8_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw8_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Partitioning Arrays
 * Abstract: Does 2 different 2 pointer methods to move all negative numbers to the left of the array with all the positive to the right.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 4/24/2025
 */

#include <iostream>
#include <vector>

int main() 
{
    int inputLength;
    std::cin >> inputLength;
    std::vector<int> v1, v2;
    while(inputLength--)
    {
        int n;
        std::cin >> n;
        v1.push_back(n);
    }
    v2 = v1;
    int i1=0, j1=v1.size()-1;
    while(i1 < j1)
    {
        while(v1[i1] <= 0)
            ++i1;
        while(v1[j1] > 0)
            --j1;
        // std::cout << v1[i1] << ", " << v1[j1] << std::endl;
        // for(int iter:v1)
        // {
        //     std::cout << iter << " ";
        // }
        // std::cout << std::endl;
        // if(v1[i1] > 0 && v1[j1] <= 0)
        if(i1<j1)
            std::swap(v1[i1], v1[j1]);
    }
    int i2=0, j2=0;
    while(i2 < v2.size() - 1 && j2 < v2.size() - 1)
    {
        //while v2[i2] is negative or 0
        while(v2[i2] <= 0 && i2 < v2.size()-1)
        {
            if(i2 == j2)
            {
                ++j2;
            }
            ++i2;
        }
        //j2 passes through
        while(v2[j2] > 0 && j2 < v2.size()-1)
            ++j2;
        if(v2[i2] > 0 && v2[j2] <= 0)
            std::swap(v2[i2], v2[j2]);
    }
    for(int iter:v1)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
    for(int iter:v2)
    {
        std::cout << iter << " ";
    }
    return 0;
}

