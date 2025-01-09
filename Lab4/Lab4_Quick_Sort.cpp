#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisonCount = 0;
int swapCount = 0;

#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int Partition(vector<int> &A, int p, int r)
{
    int x = A[r]; // Pivot element
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (++comparisonCount && A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
            swapCount++;
        }
    }
    swap(A[i + 1], A[r]);
    swapCount++;
    return i + 1;
}

void QuickSort(vector<int> &A, int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

pair<int, int> Sorted(int n)
{
    swapCount = 0;
    comparisonCount = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    QuickSort(v, 0, n - 1);
    return {comparisonCount, swapCount};
}

pair<int, int> ReverseSorted(int n)
{
    swapCount = 0;
    comparisonCount = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    QuickSort(v, 0, n - 1);
    return {comparisonCount, swapCount};
}

pair<int, int> RandomOrder(int n)
{
    swapCount = 0;
    comparisonCount = 0;
    vector<int> v(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100;
    QuickSort(v, 0, n - 1);
    return {comparisonCount, swapCount};
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    auto sorted = Sorted(size);
    auto revSorted = ReverseSorted(size);
    auto random = RandomOrder(size);
    cout << sorted.first << " " << sorted.second << endl;
    cout << revSorted.first << " " << revSorted.second << endl;
    cout << random.first << " " << random.second << endl;
    return 0;
}