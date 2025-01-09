#include <bits/stdc++.h>

using namespace std;
void Kadane(const vector<int> &v)
{
    vector<int> localMax(v.size());
    localMax[0] = v[0];
    int globalMax = v[0];
    int startidx = 0, endidx = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i] + localMax[i - 1])
        {
            localMax[i] = v[i];
            if (v[i] > v[startidx])
                startidx = i;
        }
        else
        {
            localMax[i] = v[i] + localMax[i - 1];
        }
        if (localMax[i] > globalMax)
        {
            globalMax = localMax[i];
            endidx = i;
        }
    }
    cout << globalMax << " " << startidx << " " << endidx << endl;
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
    Kadane(v);
    return 0;
}