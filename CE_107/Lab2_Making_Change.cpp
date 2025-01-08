#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*Darshan Kania*/
    int no_denomination;
    cin >> no_denomination;
    vector<pair<int, pair<int, int>>> denomination(no_denomination); // Denomination Value as first and No of Coins as second
    bool InfiniteSupply = true;
    cout << "Is there Infinite Supply: ";
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