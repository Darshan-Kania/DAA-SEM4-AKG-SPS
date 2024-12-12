# Lab2

# `Greedy Algorithms`

## Activity Selection

- Input: A set of activities S = {a1,..., an}
- Each activity has start time and a finish time – ai=(s<sub>i</sub>, f<sub>i</sub>)
- Two activities are compatible if and only if their interval does not overlap
- Output: a maximum-size subset of mutually compatible activities

```cpp
#include <bits/stdc++.h>
/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/
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
    // for (auto it : activity)
    // {
    //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    // }To Print Sorted List
    vector<int> ans;
    ans.push_back(activity[0].first);
    int curr = 0;
    for (i = 2; i < activity.size(); i++)
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
```

---

## Making Change

- There are 2 Scenerio
  - Infinite Supply of All Denomination
  - Limited Supply of All Denomination

### Infinite Supply of All Denomination

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*Darshan Kania*/
    int no_denomination;
    cin >> no_denomination;
    vector<pair<int, pair<int, int>>> denomination(no_denomination); // Denomination Value as first and No of Coins as second
    bool InfiniteSupply = true;
    cout << "Is there Infinite Supply 1 for True and 0 for False: ";
    cin >> InfiniteSupply;
    for (auto &it : denomination)
    {
        cin >> it.first;
        if (!InfiniteSupply)
            cin >> it.second.first;
        else
            it.second.first = INT_MAX;
    }
    sort(denomination.begin(), denomination.end());
    reverse(denomination.begin(), denomination.end());
    int amtReq;
    cout << "Amount Require: ";
    cin >> amtReq;
    int cntCoin = 0;
    for (auto &it : denomination)
    {
        it.second.second = amtReq / it.first;
        amtReq = amtReq % it.first;
        cntCoin += it.second.second;
    }
    if (amtReq == 0)
    {
        cout << "Yes It Can be:";
        cout << cntCoin << endl;
        for (auto it : denomination)
        {
            cout << it.first << " " << it.second.second << endl;
        }
    }
    else
        cout << "Not Possible" << endl;
    return 0;
}
/*
9
Is there Infinite Supply: 1
10
20
50
2
1
5
100
200
500
Amount Require: 3437
Yes It Can be:12
500 6
200 2
100 0
50 0
20 1
10 1
5 1
2 1
1 0
*/
```
