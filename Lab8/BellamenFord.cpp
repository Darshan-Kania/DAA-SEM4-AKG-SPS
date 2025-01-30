#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noVertice, noEdge;
    cin >> noVertice >> noEdge;

    vector<int> dist(noVertice + 1, INT_MAX), parent(noVertice + 1, -1);
    vector<pair<int, pair<int, int>>> edges;

    dist[0] = 0;

    for (int i = 0; i < noEdge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, {v, wt}});
    }

    for (int i = 0; i < noVertice; i++)
    {
        for (auto it : edges)
        {
            int u = it.first;
            int v = it.second.first;
            int wt = it.second.second;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second.first;
        int wt = edge.second.second;
        if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
        {
            cout << "Presence of -ve Weight Cycle" << endl;
            return 0;
        }
    }

    for (int i = 0; i <= noVertice; i++)
    {
        cout << "Node " << i << ": Distance = " << (dist[i] == INT_MAX ? -1 : dist[i])
             << ", Parent = " << parent[i] << endl;
    }

    return 0;
}
