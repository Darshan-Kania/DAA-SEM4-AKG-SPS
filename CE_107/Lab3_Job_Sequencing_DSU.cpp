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

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int u, int v)
{
    parent[v] = u;
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

    int parent[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
    {
        parent[i] = i;
    }

    int jobCount = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int availableSlot = find(parent, arr[i].dead);

        if (availableSlot > 0)
        {
            unionSets(parent, find(parent, availableSlot - 1), availableSlot);

            jobCount++;
            totalProfit += arr[i].profit;
        }
    }

    cout << "Number of jobs done: " << jobCount << endl;
    cout << "Total profit: " << totalProfit << endl;
}

int main()
{
    int noJobs;
    cin >> noJobs;
    vector<Job> v;
    for (auto &it : v)
    {
        cin >> it.id >> it.dead >> it.profit;
    }

    jobSequencing(v, noJobs);

    return 0;
}