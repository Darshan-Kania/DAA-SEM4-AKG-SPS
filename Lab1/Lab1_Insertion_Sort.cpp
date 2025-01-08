#include <bits/stdc++.h>

using namespace std;
int CountCase(vector<int> arr)
{
    int count = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && ++count && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
    return count;
}
int main()
{
    /*Darshan Kania*/
    int size;
    cin >> size;
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
    cout << CountCase(Sorted) << endl;
    cout << CountCase(ReverseSorted) << endl;
    cout << CountCase(Random) << endl;
    return 0;
}
// Algorithm
// 1. {
// 2. int i, key, j;
// 3. for (i = 1; i < n; i++) {
// 4. key = arr[i];
// 5. j = i - 1;
// 6. /* Move elements of arr[0..i-1], that are greater than key, to one position ahead
// 7. of their current position */
// 8. while (j >= 0 && arr[j] > key) {
// 9. arr[j + 1] = arr[j];
// 10. j = j - 1;
// 11. }
// 12. arr[j + 1] = key;
// 13. }
// 14. }