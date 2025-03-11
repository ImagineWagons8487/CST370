/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw5_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw5_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Depth First Search Mark Array
 * Abstract: Performs depth first search on a list of given edges and amount of vertices, returns a formatted version of the mark array
 * ID: 9908
 * Name: Jackie Luc
 * Date: 03/11/2025
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <set>

std::map<int, int> output;

void dfs(int current, std::vector<std::set<int>>& adjacencyList, int& markCount, std::unordered_set<int>& visited)
{
    if(current > adjacencyList.size() || visited.find(current) != visited.end())
        return;

    visited.insert(current);
    output[current] = markCount;
    if(current)
    {
        // std::cout << current << ":" << output[current] << std::endl;
    }
    // std::cout << "Mark[" << current << "]:" << markCount << std::endl;
    markCount += 1;
    for(std::set<int>::iterator iter = adjacencyList[current].begin(); iter != adjacencyList[current].end(); iter++)
    {
        dfs(*iter, adjacencyList, markCount, visited);
    }
    // for(int i=0; i<adjacencyList[current].size(); i++)
    // {
    //     dfs(adjacencyList[current][i], adjacencyList, markCount, visited);
    // }
}

int main() 
{
    int vertices, edges;
    std::vector<std::set<int>> adjacencyList(vertices);
    std::unordered_set<int> visited;
    std::cin >> vertices >> edges;
    for(int i=0; i<edges; i++)
    {
        int start, dest;
        std::cin >> start >> dest;
        adjacencyList[start].insert(dest);
    }
    int mCount = 1;
    for(int i=0; i<vertices; i++)
    {
        dfs(i, adjacencyList, mCount, visited);
    }
    for(std::map<int, int>::iterator iter = output.begin(); iter != output.end(); iter++)
    {
        std::cout << "Mark[" << iter->first << "]:" << iter->second << std::endl;
    }
    return 0;
}

// 6 5 0 2 0 1 3 4 4 5 2 1