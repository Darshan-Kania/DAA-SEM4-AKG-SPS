#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return arr[left];
    }

    int mid = left + (right - left) / 2;
    int leftMax = solve(arr, left, mid);
    int rightMax = solve(arr, mid + 1, right);

    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return max(leftMax, max(rightMax, leftSum + rightSum));
}

int maxSubarraySum(const vector<int> &arr)
{
    return solve(arr, 0, arr.size() - 1);
}

int main()
{
    /*Darshan Kania*/
    int size;
    cin >> size;
    vector<int> v(size);
    for (auto &it : v)
        cin >> it;
    cout << "Maximum subarray sum is " << maxSubarraySum(v) << endl;
    return 0;
}