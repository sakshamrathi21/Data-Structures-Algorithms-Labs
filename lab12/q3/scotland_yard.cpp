#include <vector>
#include <queue>
#include <ranges>
#include<iostream>
using namespace std;

void cover_all(std::vector<std::vector<int>>& graph, std::vector<int> &thief_positions, std::vector<int> &police_positions, int thief, int police, std::vector<int> &results) {
    // std::cout<<"HELLO"<<endl;
    
    
    for (int i = 0 ; i < thief_positions.size(); i ++) {
        if (thief_positions[i] == thief && police_positions[i] == police) {
            results.push_back(0);
            return;
        }
    }
    if (graph[thief].size() == 1 && graph[thief][0] == police) {
        results.push_back(2);
        return;
    }
    thief_positions.push_back(thief);
    police_positions.push_back(police);
    if (thief == police) {
        results.push_back(2);
        return;
    }
    if (thief == 0) {
        results.push_back(1);
        return;
    }
    int size = thief_positions.size();
    // cout<<size<<"START"<<endl;
    for (int i = 0 ; i < graph[thief].size() ; i ++) {
        for (int j = 0 ; j < graph[police].size() ; j ++) {
            if (results.size() > 11250) return;
            // cout<<graph[thief][i]<<" "<<graph[police][j]<<endl;
            cover_all(graph, thief_positions, police_positions, graph[thief][i], graph[police][j], results);
            // cout<<"OVER"<<endl;
            int current_size = thief_positions.size();
            // cout<<thief_positions.size()<<police_positions.size()<<endl;
            for (int k = 0 ; k < current_size - size; k ++ ) {
                thief_positions.pop_back();
                // cout<<"DID IT"<<endl;
                police_positions.pop_back();
            }
            // cout<<thief_positions.size()<<police_positions.size()<<endl;
            
        }
    }
    return;
}

int ScotlandYard(std::vector<std::vector<int>>& graph) 
{
    int thief = 1;
    int police = 2;
    std::vector<int> thief_positions;
    std::vector<int> police_positions;
    // thief_positions.push_back(thief);
    // police_positions.push_back(thief);

    for (int i = 0 ; i < graph[thief].size() ; i ++) {
        if (graph[thief][i] == 0) return 1;
    }

    std::vector<int> result;
    cover_all(graph, thief_positions, police_positions, thief, police, result);
    // cout<<"HELLO"<<result.size()<<endl;
    for (int i = 0 ; i < result.size() ; i ++) {
        if (result[i] == 0) return 0;
    }
    cout<<result.size()<<" HELLO "<<endl;
    return result[0];
    return -1;
}
