#include "matrix.cpp"
#include <vector>
#include <utility>


void BFS(vector <pair<int,int> > edgelist, int n, int s,int *a)
{
    Matrix m(n);
    m.set_false();
    for (int l = 0 ; l < edgelist.size() ; l ++ ) {
        m.set(edgelist[l].first, edgelist[l].second, true);
        m.set(edgelist[l].second, edgelist[l].first, true);
    }
    bool* checked = new bool[n];
    for (int i = 0 ; i < n ; i ++) {
        checked[i] = false;
    }
    checked[s] = true;
    a[s] = 0;
    Matrix m1(n);
    m1 = m;

    for (int i = 1; i < edgelist.size() ; i ++) {
        for ( int j = 0 ; j < n ; j ++) {
            if (m.get_value(j, s) && !checked[j]) {
                checked[j] = true;
                a[j] = i;
            }
        }
        Matrix m2(n);
        m2 = m.Multiply(m1, m1);
        m = m2;
    }

    for (int i = 0 ; i < n ; i ++) {
        if (checked[i] == false) {
            a[i] = -1;
        }
    }

}
