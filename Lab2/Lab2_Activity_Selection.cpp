#include <bits/stdc++.h>

using namespace std;
bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second < b.second.second;
}
int main()
{
    /*Darshan Kania*/
    int no_activity;
    cin >> no_activity;
    vector<pair<int, pair<int, int>>> activity(no_activity);
    int i = 1;
    for (auto &it : activity)
    {
        cin >> it.second.first >> it.second.second;
        it.first = i;
        i++;
    }
    sort(activity.begin(), activity.end(), comp);
    for (auto it : activity)
    {
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }
    // To Print Sorted List
    vector<int> ans;
    ans.push_back(activity[0].first);
    int curr = 0;
    for (i = 17
2 4
1 9
2 8
4 6
6 8
5 6
5 12; i < activity.size(); i++)
    {
        if (activity[curr].second.second <= activity[i].second.first)
        {
            ans.push_back(activity[i].first);
            curr = i;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
// TC => O(n+nlogn+n+n)  => O(nlogn)