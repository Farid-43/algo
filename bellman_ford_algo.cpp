#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;

int bellman(int s, int n)
{
    vector<int> d(n, INT_MAX);
    d[s] = 0;
    int i, u, v, w;
    for (i = 0; i < n - 1; i++)
    {
        for (auto it : g)
        {
            u = it[0];
            v = it[1];
            w = it[2];

            if (d[u] != INT_MAX && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }

    for (auto it : g)
    {
        u = it[0];
        v = it[1];
        w = it[2];

        if (d[u] != INT_MAX && d[u] + w < d[v])
        {
            cout << "Negative cycle\n";

            return -1;
        }
    }
    for (i = 0; i < n; i++)
        cout << d[i] << endl;
}

int main()
{
    int m, n;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    int s;
    cin >> s;
    bellman(s, n);
    return 0;
}

/*


8 8
6 7 1
5 6 1
4 5 1
3 4 1
1 3 1
3 2 -5
2 1 -1
0 1 1
0


3 5
0 1 -2
0 2 3
2 3 4
1 3 -2
3 0 4
0

*/

/*
vector<vector<int>>g;
int n,m,i,j,k,u,v,w,s,to;
int x,y,z;
int maxa = INT_MAX, fu,fv;
void bellman(){
    vector<int>d(n+1,INT_MAX);
vector<int>par(n,-1);
    d[s] =0;
    for(i=0;i<n-1;i++){
        for(auto it:g){
            u = it[0];
            v = it[1];
            w = it[2];
            if(d[u] != INT_MAX && d[u] +w <d[v]) {
                d[v] = d[u] +w;
                par[v] =u;

            }
        }
    }
    int x =-1;
    for(auto it:g){
            u = it[0];
            v = it[1];
            w = it[2];
            if(d[u] != INT_MAX && d[u] +w <d[v]){
                par[v] =u;
                x = u;
        }
    }
    //cout<<x<<endl;
    if(x !=-1){
        for(i=0;i<n;i++){
            x = par[x];
        }
        vector<int>path;
        int curr = x;
        do{
            path.push_back(curr);
            curr = par[curr];
        }while(curr != x);
        path.push_back(x);
        reverse(path.begin(),path.end());
        //for(auto it:path) cout<<it<<" ";
        //cout<<endl;

        for(i =0;i<path.size()-1;i++){
            int uuu = path[i];
            int vvv = path[i+1];
            for(auto it:g){
                u = it[0];
                v = it[1];
                w = it[2];
                if(uuu==u && vvv == v ){
                    if(w <maxa){
                        maxa =w;
                        fu = u;
                        fv =v;
                    }
                }
            }
        }
    }
    //for(auto it:d){
        //cout<<it<<" " ;
    //}cout<<endl;

}

*/