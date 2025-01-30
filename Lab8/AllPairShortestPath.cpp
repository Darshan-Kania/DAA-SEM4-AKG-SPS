#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    /*Darshan Kania*/
    int noVertice;
    cin >> noVertice;
    int noEdge;
    cin >> noEdge;
    vector<vector<ll>> cost(noVertice + 1, vector<ll>(noVertice + 1, INT16_MAX));
    for (int i = 0; i < noEdge; i++)
    {
        int u, v;
        cin >> u >> v;
        int wt;
        cin >> wt;
        cost[u][v] = wt;
    }
    for (int i = 0; i <= noVertice; i++)
    {
        cost[i][i] = 0;
    }
    for (int k = 1; k <= noVertice; k++)
    {
        for (int i = 1; i <= noVertice; i++)
        {
            for (int j = 1; j <= noVertice; j++)
            {
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
            }
        }
    }
    for (auto row : cost)
    {
        for (auto val : row)
        {
            if (val == INT16_MAX)
                val = -1;
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}