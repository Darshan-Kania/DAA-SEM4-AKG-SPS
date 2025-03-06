#include <bits/stdc++.h>

using namespace std;

vector<int> Color;
bool AnySol = false;
void Print()
{
    for (auto it = next(Color.begin(), 1); it != Color.end(); ++it)
        cout << *it << " ";
    AnySol = true;
}
void NextValue(int k, vector<vector<int>> &G, int noColor)
{
    do
    {
        Color[k] = (Color[k] + 1) % (noColor + 1);
        if (Color[k] == 0)
            return;
        bool isValid = true;
        for (auto neigh : G[k])
        {
            if (Color[neigh] == Color[k])
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
            return;
    } while (true);
}
void MC(int k, vector<vector<int>> &G, int noColor)
{
    while (true)
    {
        NextValue(k, G, noColor);
        if (Color[k] == 0)
            return;
        if (k == G.size() - 1)
        {
            Print();
            cout << endl;
        }
        else
            MC(k + 1, G, noColor);
    }
}

int main()
{
    /*Darshan Kania*/
    int n, e;
    // cout << "Enter the number of vertices: ";
    cin >> n;
    // cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>> adj(n + 1);
    // cout << "Enter the edges: \n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m;
    // cout << "Enter the number of colors: ";
    cin >> m;
    Color.resize(n + 1, 0);
    MC(1, adj, m);
    if (!AnySol)
        cout << "No solution exists";
    return 0;
}