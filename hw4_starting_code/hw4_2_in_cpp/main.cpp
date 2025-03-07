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
 * Title: main.cpp
 * Abstract: Write the main purpose of the program.
 * ID: Write your 4-digit ID
 * Name: Write your name
 * Date: MM/DD/YYYY
 */

#include <iostream>
#include <vector>

int dfs(std::vector<std::pair<int, int>> input, int iter, int& max, int capacity, std::vector<std::pair<int, int>>& workingVector, std::vector<std::pair<int, int>>& best)
{
    //return int is amount of solutions, outside of call will check for multiple solutions
    //base case
    if(iter >= input.size())
    {
        return 0;
    }
    //get input[iter]
    std::pair<int, int> p = input[iter];
    //check adding with every possibility, need to keep a max value
    //perform operation before recursive calls?
    //if workingVector with current pair total capacity is under capacity, push_back it
    //else return 0
    //if workingVector total value > max
        //max = workingVector total value
        //best = workingVector
    //check somewhere, if a total value == max, return dfs() + 1?
    for(int i=1; iter+i<input.size(); ++i)
    {
        //calls dfs on next item in input
        dfs(input, iter+i, max, capacity, workingVector, best);
    }
}

int main() 
{
    int itemCount, capacity;
    std::cin >> itemCount >> capacity;
    std::vector<std::pair<int, int>> inputItems, workingVector, outputItems;
    for(int i=0; i<itemCount; ++i)
    {
        int weight, value;
        std::cin >> weight >> value;
        std::pair<int, int> p = {weight, value};
        inputItems.push_back(p);
    }
    int max = 0;
    int amount = dfs(inputItems, 0, max, capacity, workingVector, outputItems);

    if(amount > 1)
    {
        //multiple solutions
    }
    //look at all the pairs, get the ratio of them.
    //if the ratio is better than ratio of any of the vector pairs, replace
    
    //DFS, multiple subsets, will be slow? complete search?

    return 0;
}


