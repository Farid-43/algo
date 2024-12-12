#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

void johnson(vector<vector<int>> &edges, int n) {
    vector<vector<pair<int,int>>> adj_list(n);
    vector<int>h(n,0);
    vector<vector<int>> dist(n+1,vector<int>(n+1,inf));
    for(auto edge : edges) {
        adj_list[edge[0]].push_back({edge[1],edge[2]});
    }
    int m = n+1;
    for(int i=0; i<n; ++i) {
        edges.push_back({n,i,0});
    }
    dist[n][n] = 0;
    for(int i=0; i<m-1; ++i) {
        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if(dist[n][u]!= inf && dist[n][u] + w < dist[n][v]) {
                h[v] = dist[n][v] = dist[n][u] + w;
            }
        }
    }
    for(auto &edge:edges) {
        int u=edge[0], v = edge[1], w=edge[2];
        w = w+h[u]-h[v];
    }
    
    //dijkstra part
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            auto [node_dis, node] = pq.top();
            pq.pop();
            for (auto [neighbour, weight] : adj_list[node]) {
                int new_dis = node_dis + weight;
                if (new_dis < dist[i][neighbour]) {
                    pq.push({new_dis, neighbour});
                    dist[i][neighbour] = new_dis;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] < inf) {
                dist[i][j] += h[j] - h[i];
            }
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if (dist[i][j] == inf) {
                cout << "inf ";
            } 
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    int n, e;
    cin >> n >> e;
    int u,v,w;
    vector<vector<int>> edges;
    for(int i=0; i<e; ++i) {
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    cout << endl;
    johnson(edges, n);

    return 0;
}