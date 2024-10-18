#include "bfs.cpp"


int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> edgelist;
    int* a = new int[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edgelist.push_back(make_pair(u, v));
    }
    int s;
    cin >> s;
    BFS(edgelist, n,s,a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\n";
    }
}