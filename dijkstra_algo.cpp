#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define inf 1e7

void dijkstra(const vector<vector<pair<int, int>>> &adj, vector<int> &dist, int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, e, u, v, w;
    cin >> n >> e;
    vector<int> distance(n, inf);
    vector<vector<pair<int, int>>> adj_list(n);
    for (int i = 0; i < e; ++i)
    {
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    cout << "Enter source : ";
    int source;
    cin >> source;
    distance[source] = 0;
    dijkstra(adj_list, distance, source);

    return 0;
}