#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void POP(vector<vector<ll>> K, ll i, ll j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        POP(K, i, K[i][j]);
        POP(K, K[i][j] + 1, j);
        cout << ")";
    }
}
void MCM(ll n, vector<vector<ll>> c, vector<vector<ll>> K, vector<ll> p)
{
    for (ll i = 1; i <= n; i++)
    {
        c[i][i] = 0;
    }
    for (ll len = 2; len <= n; len++)
    {
        for (ll i = 1; i <= n - len + 1; i++)
        {
            ll j = i + len - 1;
            c[i][j] = INT_MAX;
            for (ll k = i; k < j; k++)
            {
                ll q = c[i][k] + c[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < c[i][j])
                {
                    c[i][j] = q;
                    K[i][j] = k;
                }
            }
        }
    }
    cout << "Cost Matrix" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Solution Mat" << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Cost: ";
    cout << c[1][n] << endl;
    cout << "Optimal Parenthesis Order" << endl;
    POP(K, 1, n);
}
int main()
{
    /*Darshan Kania*/
    ll n;
    cin >> n;
    vector<ll> p(n + 1);
    for (auto &it : p)
        cin >> it;
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1, -1));
    vector<vector<ll>> K(n + 1, vector<ll>(n + 1, -1));
    MCM(n, c, K, p);
    return 0;
}