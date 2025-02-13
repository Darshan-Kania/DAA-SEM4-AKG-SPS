#include <bits/stdc++.h>

using namespace std;
vector<bool> vis;
void Topo(int src, const vector<vector<int>> &G, stack<int> &st)
{
    vis[src] = true;
    for (auto neigh : G[src])
    {
        if (vis[neigh] == false)
        {
            Topo(neigh, G, st);
        }
    }
    st.push(src);
}
int main()
{
    /*Darshan Kania*/
    int noVertice;
    cin >> noVertice;
    vis.resize(noVertice, false);
    vector<vector<int>> G(noVertice);
    int noEdge;
    cin >> noEdge;
    for (int i = 0; i < noEdge; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (auto it : G)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    stack<int> ans;
    for (int i = 0; i < noVertice; i++)
    {
        if (vis[i] == false)
            Topo(i, G, ans);
    }
    cout << "Topo Order: ";
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}