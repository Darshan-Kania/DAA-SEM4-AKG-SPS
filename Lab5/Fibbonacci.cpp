#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> dp;
int fibbo(int n)
{
    if (n == 0 || n == 1)
        return n;
    else if (dp[n] != -1)
        return dp[n];
    else
        return dp[n] = fibbo(n - 1) + fibbo(n - 2);
}
int fibbo2(int n)
{
    dp.resize(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    /*Darshan Kania*/
    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << fibbo(n) << endl;
    cout << fibbo2(n) << endl;
    return 0;
}