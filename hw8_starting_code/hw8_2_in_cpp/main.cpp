/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw8_2.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw8_2.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Kahn's Algorithm
 * Abstract: Performs Kahn's algorithm on input and outputs in degree and topological order
 * ID: 9908
 * Name: Jackie Luc
 * Date: 04/25/2025
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>


void kahn(std::vector<std::vector<int>> adjMatrix, std::vector<int> inDegrees)
{
    std::queue<int> q;
    for(int i=0; i<inDegrees.size(); ++i)
    {
        if(inDegrees[i] == 0)
        {
            q.push(i);
        }
    }
    std::vector<int> result;
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        //push when popped
        result.push_back(currNode);

        //decrease indegree of current node's neighbors, get neighbors by going through row at current node
        for(int i : adjMatrix[currNode])
        {
            --inDegrees[i];

            //if inDegree[i] gets to 0, push to q
            if(inDegrees[i] == 0)
            {
                q.push(i);
            }
        }
    }

    for(int i = 0; i<result.size()-1; ++i)
    {
        std::cout << result[i] << "->";
    }
    std::cout << result[result.size()-1];
}

int main() 
{
    int vertices, edges;
    std::cin >> vertices >> edges;
    std::vector<int> v(vertices);
    std::vector<std::vector<int>> adjMatrix(vertices);
    for(int i=0; i<edges; ++i)
    {
        int start, destination;
        std::cin >> start >> destination;
        ++v[destination];
        adjMatrix[start].push_back(destination);
    }
    bool valid = false;
    for(int i=0; i<v.size(); ++i)
    {
        std::cout << "In-degree[" << i << "]:" << v[i] << std::endl;
        if(v[i] == 0)
        {
            valid = true;
        }
    }

    if(!valid)
    {
        std::cout << "No Order:";
    }
    else
    {
        std::cout << "Order:";
        kahn(adjMatrix, v);
    }


    return 0;
}


