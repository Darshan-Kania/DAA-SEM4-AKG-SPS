#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noVertex, noEdge, type;
    cin >> noVertex >> noEdge >> type;

    vector<vector<int>> adj(noVertex + 1); // Adjacency list
    vector<int> degree(noVertex + 1, 0);   // Degree of each vertex

    // Input edges
    for (int i = 0; i < noEdge; i++)
    {
        int source, dest;
        cin >> source >> dest;
        adj[source].push_back(dest);
        adj[dest].push_back(source); // Always add both directions for undirected graph
        degree[source]++;
        degree[dest]++;
    }

    vector<bool> included(noVertex + 1, false);      // Track if a vertex is in the vertex cover
    set<pair<int, int>, greater<pair<int, int>>> st; // {degree, vertex}

    // Initialize the set with degrees
    for (int i = 1; i <= noVertex; i++)
    {
        if (degree[i] > 0)
        {
            st.insert({degree[i], i});
        }
    }

    vector<int> vertexCover;

    // Greedy algorithm for vertex cover
    while (!st.empty())
    {
        auto top = *st.begin(); // Get the vertex with the highest degree
        st.erase(st.begin());

        int vertex = top.second;
        if (included[vertex])
            continue;

        // Include this vertex in the cover
        included[vertex] = true;
        vertexCover.push_back(vertex);

        // Remove all edges incident to this vertex
        for (int neighbor : adj[vertex])
        {
            if (!included[neighbor])
            {
                st.erase({degree[neighbor], neighbor});
                degree[neighbor]--; // Decrease the degree
                if (degree[neighbor] > 0)
                {
                    st.insert({degree[neighbor], neighbor});
                }
            }
        }
    }

    // Sort and output the vertex cover
    sort(vertexCover.begin(), vertexCover.end());
    for (int vertex : vertexCover)
    {
        cout << vertex << " ";
    }

    return 0;
}
