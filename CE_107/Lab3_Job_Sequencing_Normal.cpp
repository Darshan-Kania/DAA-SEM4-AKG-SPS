#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

void jobSequencing(vector<Job> arr, int n)
{
    sort(arr.begin(), arr.end(), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].dead > maxDeadline)
        {
            maxDeadline = arr[i].dead;
        }
    }

    vector<int> slot(maxDeadline + 1, -1);

    int jobCount = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                jobCount++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Number of jobs done: " << jobCount << endl;
    cout << "Total profit: " << totalProfit << endl;
}

int main()
{
    int noJobs;
    cin >> noJobs;
    vector<Job> v(noJobs);
    for (int i = 0; i < noJobs; i++)
    {
        cin >> v[i].id >> v[i].dead >> v[i].profit;
    }

    jobSequencing(v, noJobs);

    return 0;
}