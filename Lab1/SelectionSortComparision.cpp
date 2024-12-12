#include <bits/stdc++.h>

using namespace std;
int CountCase(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            count++;
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[min_ind], arr[i]);
    }
    return count;
}
int main()
{
    /*Darshan Kania*/
    for (int i = 10; i <= 100; i += 10)
    {
        int size = i;
        srand(time(0));
        vector<int> Sorted(size);
        vector<int> ReverseSorted(size);
        vector<int> Random(size);
        for (int i = 0; i < size; i++)
        {
            Sorted[i] = i;
            ReverseSorted[i] = size - i;
            Random[i] = rand() % 500;
        }
        {
            cout << CountCase(Sorted) << " ";
            cout << CountCase(ReverseSorted) << " ";
            cout << CountCase(Random) << endl;
        }
    }
    return 0;
}
