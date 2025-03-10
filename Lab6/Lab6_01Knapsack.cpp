#include <bits/stdc++.h>

using namespace std;
vector<int> printSolution(vector<vector<int>> dp, vector<pair<int, int>> items)
{
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    vector<int> ans;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            ans.push_back(i);
            j = j - items[i].first;
            i--;
        }
        else
        {
            i--;
        }
    }
    return ans;
}
int main()
{
    /*Darshan Kania*/
    int noItems;
    cin >> noItems;
    vector<pair<int, int>> items(noItems + 1); // Weight Profit
    for (int i = 1; i <= noItems; i++)
    {
        cin >> items[i].first >> items[i].second;
    }
    int capacity;
    cin >> capacity;
    vector<vector<int>> dp(noItems + 1, vector<int>(capacity + 1));
    for (int i = 0; i <= noItems; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (items[i].first <= j)
                dp[i][j] = max(items[i].second + dp[i - 1][j - items[i].first], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (auto &it : dp)
    {
        for (auto &it2 : it)
            cout << it2 << " ";
        cout << endl;
    }
    cout << dp[noItems][capacity] << endl;
    vector<int> ans = printSolution(dp, items);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}