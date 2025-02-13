#include <bits/stdc++.h>

using namespace std;
vector<int> dfn, low;
vector<bool> vis;
set<int> st;
int timeGl = 0;
void Art(int src, int par, vector<vector<int>> &graph)
{
    dfn[src] = low[src] = timeGl++;
    vis[src] = true;
    int noChild = 0;
    for (auto neigh : graph[src])
    {
        if (vis[neigh] == false)
        {
            noChild++;
            Art(neigh, src, graph);
            low[src] = min(low[src], low[neigh]);
            if (par == -1 && noChild >= 2)
            {
                st.insert(src);
            }
            if (par != -1 && low[neigh] >= dfn[src])
            {
                st.insert(src);
            }
        }
        else if (neigh != par)
        {
            low[src] = min(low[src], dfn[neigh]);
        }
    }
}
int main()
{
    /*Darshan Kania*/
    int noVertex, noEdges;
    cin >> noVertex >> noEdges;
    vector<vector<int>> graph(noVertex + 1);
    for (int i = 0; i < noEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfn.resize(noVertex + 1, -1);
    low.resize(noVertex + 1, -1);
    vis.resize(noVertex + 1, false);
    Art(1, -1, graph);
    cout << "Articulation Point Are: " << endl;
    for (auto it : st)
    {
        cout << it << " ";
    }
    return 0;
}