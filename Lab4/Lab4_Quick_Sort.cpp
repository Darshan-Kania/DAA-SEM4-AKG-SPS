#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisonCount = 0;
int swapCount = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    swapCount++;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisonCount++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

pair<int, int> Sorted(int n)
{
    swapCount = 0;
    comparisonCount = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    quickSort(v, 0, n - 1);
    return {comparisonCount, swapCount};
}

pair<int, int> ReverseSorted(int n)
{
    swapCount = 0;
    comparisonCount = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    quickSort(v, 0, n - 1);
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
    quickSort(v, 0, n - 1);
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