#include "graph.h"

bool dfsrec ( std::map<int, GraphNode *> nodes, std::map<int, bool> &visited, std::map<int, int> &parent, int v) {
    visited[v] = true;
    for (auto r : nodes[v]->adj) {
        if ( r != parent[v] ) {
            // cout<<r<<endl;
            if (visited[r] == false) {
                // cout<<"CHECK"<<v<<endl;
                parent[r] = v;
                if (dfsrec(nodes, visited, parent, r)) return true;
            }
            else {
                return true;
            }
        }
    }
    return false;
}

// Implement this function to check if there is a cycle present in the graph
bool Graph::isCyclePresent(){
    std::map<int, bool> visited;
    std::map<int, int> parent;
    for (auto p: nodes) {
        visited[p.first] = false;
        parent[p.first] = -1;
    }
    // dfsrec(nodes, visited, parent, 0);
    // cout<<"BFH"<<endl;
    for (auto q: nodes) {
        if (visited[q.first] == false) {
            // cout<<q.first<<endl;
            if (dfsrec(nodes, visited, parent, q.first)) return true;
        }
    }

   
    // dummy return
    return false;
}