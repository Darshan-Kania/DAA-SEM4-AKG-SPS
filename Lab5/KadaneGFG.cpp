#include <bits/stdc++.h>
using namespace std;
void KadaneGFG(vector<int> &v)
{
    int maxsoFar = INT_MIN;
    int maxending = 0;
    int sidx = 0, eidx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        maxending = maxending + v[i];

        if (maxsoFar < maxending)
        {
            maxsoFar = maxending;
            eidx = i;
        }
        if (maxsoFar == v[i])
        {
            sidx = eidx = i;
        }
        if (maxending < 0)
        {
            maxending = 0;
        }
    }
    cout << maxsoFar << " " << sidx << " " << eidx;
}
int main()
{
    /*Darshan Kania*/
    int size;
    // cout << "Enter Size of Array: ";
    cin >> size;
    vector<int> v(size);
    for (auto &it : v)
        cin >> it;
    KadaneGFG(v);
    return 0;
}