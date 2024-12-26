#include <bits/stdc++.h>

using namespace std;
// global Count
int cnt = 0;
void Merge(vector<int> &a, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<int> B;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B.push_back(a[i]);
            i++;
        }
        else
        {
            B.push_back(a[j]);
            j++;
        }
    }
    for (; i <= mid; i++)
    {
        B.push_back(a[i]);
    }
    for (; j <= high; j++)
    {
        B.push_back(a[j]);
    }
    int x = 0;
    for (int ele = low; ele <= high; ele++)
    {
        a[ele] = B[x];
        x++;
    }
}
void MergeSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(v, low, mid);
        MergeSort(v, mid + 1, high);
        Merge(v, low, mid, high);
    }
}
int main()
{
    /*Darshan Kania*/
    int size;
    cin >> size;
    vector<int> v(size);
    for (auto &it : v)
        cin >> it;
    MergeSort(v, 0, v.size() - 1);
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return 0;
}