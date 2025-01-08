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
        ++cnt;
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
        cnt++;
        B.push_back(a[i]);
    }
    for (; j <= high; j++)
    {
        cnt++;
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
    if (low < high) // && ++cnt)
    {
        int mid = (low + high) / 2;
        MergeSort(v, low, mid);
        MergeSort(v, mid + 1, high);
        Merge(v, low, mid, high);
    }
}
int Sorted(int n)
{
    cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    MergeSort(v, 0, n - 1);
    return cnt;
}
int ReverseSorted(int n)
{
    cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    MergeSort(v, 0, n - 1);
    return cnt;
}
int RandomOrder(int n)
{
    cnt = 0;
    vector<int> v(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;
    MergeSort(v, 0, n - 1);
    return cnt;
}
int main()
{
    /*Darshan Kania*/
    int size;
    cin >> size;
    cout << Sorted(size) << endl;
    cout << ReverseSorted(size) << endl;
    cout << RandomOrder(size) << endl;
    return 0;
}