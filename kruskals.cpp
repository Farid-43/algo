/*#include <bits/stdc++.h>
using namespace std;
class Disjoint {
    vector<int> rank;
    vector<int> parent;

    public:
        Disjoint(int N) {
            for(int i=0; i<N; ++i) {
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        int findParent(int node) {
            if(parent[node] == node) {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else {
                parent[pv] = pu;
                ++rank[pu];
            }
        }
};

int main() {
    int n, e, u, v, w;
    cin >> n >> e;
    vector<tuple<int,int,int>> edges;
    for(int i=0; i<e; ++i) {
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    Disjoint ds(n);
    int mst = 0;

    for(auto [w,u,v]:edges) {
        if(ds.findParent(u) != ds.findParent(v)) {
            mst += w;
            ds.unionByRank(u,v);
        }
    }
    cout << mst << endl;


    return 0;
}
*/

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int N = 1000;
vector<int> par(N), sz(N);
void make_set()
{
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
int find_set(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
void mst(vector<vector<int>> g, int n, int m)
{
    int c = 0, u, v, w, x, y, p, e = 0;
    for (auto it : g)
    {
        w = it[0];
        u = it[1];
        v = it[2];
        x = find_set(u);
        y = find_set(v);
        if (x != y)
        {
            c += w;
            union_set(u, v);
            e++;
        }
    }
    if (e != (n - 1))
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << c << endl;
    }
}

int main()
{
    int n, m, i, j, u, v, w, k;
    cin >> n >> m;
    vector<vector<int>> g, gr;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({w, u, v});
    }
    cin >> k;
    ll vec[k];
    for (i = 0; i < k; i++)
    {
        cin >> vec[i];
    }
    int p = 0;
    j = vec[p];
    i = 0;
    for (auto it : g)
    {
        if (i == j)
        {
            i++;
            p++;
            j = vec[p];
            continue;
        }
        w = it[0];
        u = it[1];
        v = it[2];
        gr.push_back({w, u, v});
        i++;
    }
    make_set();
    // for (auto it : gr)
    // {
    //     w = it[0];
    //     u = it[1];
    //     v = it[2];
    //     cout << u << " " << v << " " << w << endl;
    // }
    sort(gr.begin(), gr.end());
    mst(gr, n, m);

    return 0;
}
/*
6 9
1 2 2
1 3 3
2 3 1
3 4 4
4 5 5
3 5 6
2 5 8
5 6 6
4 6 7
3
0 2 3

*/