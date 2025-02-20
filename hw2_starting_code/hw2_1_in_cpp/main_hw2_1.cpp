/*
 * INSTRUCTIONS:
 *     This is the starting C++ code for hw2_1.
 *     Note that the current filename is "main.cpp". 
 *     When you finish your development, copy the file.
 *     Then, rename the copied file to "main_hw2_1.cpp".
 *     After that, upload the renamed file to Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: Directed Weighted Graphs
 * Abstract: Takes in a number of vertices and edges, then takes in a source, destination, and weight to assign weights to each node of the graph.
 Then it outputs the directed weighted graph in adjacency list format. Outputs "Invalid graph." if the graph as duplicate edges, empty vertex sets,
 or invalid edges.
 * ID: 9908
 * Name: Jackie Luc
 * Date: 02/10/2025
 */

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int vertices, edges;
    std::cin >> vertices >> edges;
    if(vertices <= 0)
    {
        std::cout << "Invalid graph.";
        return 0;
    }
    std::vector<std::vector<int>> adjacencyList(vertices, std::vector<int>(vertices, -1));
    while(edges--)
    {
        int src, destination, weight;
        std::cin >> src >> destination >> weight;
        if(src >= vertices || destination >= vertices || adjacencyList[src][destination] != -1)
        {
            std::cout << "Invalid graph.";
            return 0;
        }
        adjacencyList[src][destination] = weight;
    }
    for(int i=0; i<adjacencyList.size(); i++)
    {
        std::cout << i;
        for(int j=0; j<adjacencyList[i].size(); j++)
        {
            if(adjacencyList[i][j] != -1)
            {
                std::cout << "->" << j << "," << adjacencyList[i][j];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

