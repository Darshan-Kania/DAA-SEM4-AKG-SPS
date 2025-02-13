#include <bits/stdc++.h>
using namespace std;

void DFS(int src, stack<int> &st, vector<bool> &vis, vector<vector<int>> &G)
{
    vis[src] = true;
    for (int i = 1; i < G.size(); i++)
    {
        if (G[src][i] == 1 && !vis[i])
        {
            DFS(i, st, vis, G);
        }
    }
    st.push(src);
}

void DFSN(int src, vector<bool> &vis, vector<vector<int>> &G)
{
    vis[src] = true;
    cout << src << " ";
    for (int i = 1; i < G.size(); i++)
    {
        if (G[src][i] == 1 && !vis[i])
        {
            DFSN(i, vis, G);
        }
    }
}

void Transpose(vector<vector<int>> &G)
{
    vector<vector<int>> temp(G.size(), vector<int>(G.size(), 0));
    for (int i = 1; i < G.size(); i++)
    {
        for (int j = 1; j < G.size(); j++)
        {
            if (G[i][j] == 1)
            {
                temp[j][i] = 1;
            }
        }
    }
    G = temp;
}

int main()
{
    int noVertice, noEdge;
    cin >> noVertice >> noEdge;

    vector<vector<int>> G(noVertice + 1, vector<int>(noVertice + 1, 0));
    for (int i = 0; i < noEdge; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
    }

    stack<int> ans;
    vector<bool> vis(noVertice + 1, false);

    for (int i = 1; i <= noVertice; i++)
    {
        if (!vis[i])
        {
            DFS(i, ans, vis, G);
        }
    }

    Transpose(G);
    fill(vis.begin(), vis.end(), false);

    while (!ans.empty())
    {
        int node = ans.top();
        ans.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            DFSN(node, vis, G);
            cout << endl;
        }
    }

    return 0;
}
