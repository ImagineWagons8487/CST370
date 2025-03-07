/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw4_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw4_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: The Knapsack
 * Abstract: Given a number of items and a max capacity and then that number of items. Find the best combination of items given to get maximum value while staying under capacity given
 * ID: 9908
 * Name: Jackie Luc
 * Date: 03/07/2025
 */

#include <iostream>
#include <vector>

//max val and max capacity make into global
//make best vector of pairs global too?
//global int for amount of solutions
    //reset when new best is found

int maxVal = 0, maxCapacity, solutionsAmt = 0;
std::vector<std::pair<int, int>> best;

void dfs(std::vector<std::pair<int, int>> input, int iter, int& max, std::vector<std::pair<int, int>>& workingVector)
{
    //base case
    if(iter >= input.size())
    {
        return;
    }
    //get input[iter]
    std::pair<int, int> p = input[iter];
    //check adding with every possibility, need to keep a max value
    //perform operation before recursive calls?
    //if workingVector with current pair total capacity is under capacity, push_back it
    workingVector.push_back(p);
    int workingCapacity=0, workingVal=0;
    for(int i=0; i<workingVector.size(); ++i)
    {
        workingCapacity += workingVector[i].first;
        workingVal += workingVector[i].second;
    }
    if(workingCapacity > maxCapacity)
    {
        workingVector.pop_back();
        return;
    }
    else
    {
        if(workingVal > maxVal)
        {
            maxVal = workingVal;
            best = workingVector;
            solutionsAmt = 1;
        }
        else if(workingVal == maxVal)
        {
            ++solutionsAmt;
        }
    }
    //else return
    //if workingVector total value > max
        //max = workingVector total value
        //best = workingVector
    //check somewhere, if a total value == max, return dfs() + 1?
    std::vector<std::pair<int, int>> currentV = workingVector;
    for(int i=1; iter+i<input.size(); ++i)
    {
        workingVector = currentV;
        //calls dfs on next item in input
        dfs(input, iter+i, max, workingVector);
    }
}

int main() 
{
    int itemCount;
    std::cin >> itemCount >> maxCapacity;
    std::vector<std::pair<int, int>> inputItems, workingVector;
    for(int i=0; i<itemCount; ++i)
    {
        int weight, value;
        std::cin >> weight >> value;
        std::pair<int, int> p = {weight, value};
        inputItems.push_back(p);
    }
    int max = 0;
    for(int i=0; i<inputItems.size(); ++i)
    {
        workingVector = {};
        dfs(inputItems, i, maxVal, workingVector);
    }
    std::cout << "Item:";
    if(solutionsAmt > 1)
    {
        std::cout << "Multiple solutions";
    }
    else
    {
        std::vector<int> outputIndices;
        for(int i=0; i<inputItems.size(); ++i)
        {
            for(int j=0; j<best.size(); ++j)
            {
                if(inputItems[i].first == best[j].first && inputItems[i].second == best[j].second)
                {
                    outputIndices.push_back(i);
                }
            }
        }
        for(int i=0; i<outputIndices.size(); ++i)
        {
            std::cout << outputIndices[i]+1 << " ";
        }
    }
    int outputCapacity=0;
    for(int i=0; i<best.size(); ++i)
    {
        outputCapacity += best[i].first;
    }
    std::cout << std::endl << "Capacity:" << outputCapacity << std::endl << "Value:" << maxVal;
    
    //DFS, multiple subsets, will be slow? complete search?

    return 0;
}


