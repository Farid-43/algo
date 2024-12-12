#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void floydWarshall(int dist[][V])
{

    int i, j, k;

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // printSolution(dist);
}

int main()
{
    int graph[V][V];
    // Initialize graph with INF
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v w format):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph);
    return 0;
}
