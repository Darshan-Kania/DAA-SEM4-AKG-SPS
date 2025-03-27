#include <bits/stdc++.h>
using namespace std;
vector<int> Color; // Global vector to store colors of vertices
bool AnySol = false; // Global boolean to check if a solution exists

void MC(int node, const vector<vector<int>>& adj, int m) {
    if (node == adj.size()) {
        AnySol = true;
        return;
    }
    for (int c = 1; c <= m; c++) {
        bool canColor = true;
        for (int neighbor : adj[node]) {
            if (Color[neighbor] == c) {
                canColor = false;
                break;
            }
        }
        if (canColor) {
            Color[node] = c;
            MC(node + 1, adj, m);
            if (AnySol) return;
            Color[node] = 0;
        }
    }
}

int main()
{
    /*Darshan Kania*/
    int n, e;
    // Input number of vertices and edges
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    // Input edges
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int chromaticNumber = 0;
    for (int m = 1; m <= n; m++) // Start with 1 color and increase
    {
        Color.assign(n + 1, 0);
        AnySol = false;
        MC(1, adj, m);
        if (AnySol)
        {
            chromaticNumber = m;
            break; // Stop as soon as a valid coloring is found
        }
    }

    if (chromaticNumber > 0)
        cout << "Chromatic Number: " << chromaticNumber << endl;
    else
        cout << "No solution exists" << endl;

    return 0;
}
