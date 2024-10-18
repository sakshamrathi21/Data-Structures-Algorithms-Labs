#include "scotland_yard.cpp"
#include <iostream>
#include <fstream>

// Function to output graph in DOT format
void outputDotFile(const std::vector<std::vector<int>>& graph) {
    const std::string& filename = "graph.dot";
    std::ofstream dotFile(filename);

    if (dotFile.is_open()) {
        dotFile << "graph G {" << std::endl;
        
        // Iterate through the adjacency lists and output edges
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                dotFile << "  " << i << " -- " << graph[i][j] << ";" << std::endl;
            }
        }
        
        dotFile << "}" << std::endl;
        dotFile.close();
        std::cout << "Graph data written to " << filename << std::endl;
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> graph;
    int num_vertices;
    std::cin >> num_vertices;
    for (int j = 0; j < num_vertices; j++)
    {
        std::vector<int> adjList;
        int num_edges;
        std::cin >> num_edges;
        for (int k = 0; k < num_edges; k++)
        {
            int adjVertex;
            std::cin >> adjVertex;
            adjList.push_back(adjVertex);
        }
        graph.push_back(adjList);
    }
    std::cout << ScotlandYard(graph) << std::endl; // Write a function mincost which takes the graph and returns the integer solution
    // outputDotFile(graph);
	return 0;
}