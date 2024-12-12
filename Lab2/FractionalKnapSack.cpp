#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*Darshan Kania*/
    int noItems;
    cin >> noItems;
    vector<pair<double, pair<int, int>>> items(noItems);
    for (auto &it : items)
    {
        cout << "Enter Item Profit: ";
        cin >> it.second.first;
        cout << "Enter Item Weight: ";
        cin >> it.second.second;
        it.first = ((it.second.first) / (double(it.second.second)));
    }
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    int curWt = 0;
    int capacity;
    cout << "Capacity is: ";
    cin >> capacity;
    int i = 0;
    int totalProfit = 0;
    while (i < noItems && curWt < capacity)
    {
        if (curWt + items[i].second.second <= capacity)
        {
            curWt += items[i].second.second;
            totalProfit += items[i].second.first;
        }
        else
        {
            double ratio = ((capacity - curWt) / (double(items[i].second.second)));
            curWt += ratio * items[i].second.second;
            totalProfit += ratio * items[i].second.first;
        }
        i++;
    }
    cout << totalProfit << endl;
    return 0;
}