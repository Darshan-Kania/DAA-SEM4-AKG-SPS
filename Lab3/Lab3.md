# Lab3

---

# Greedy Algorithms Part 2

---

## Q1. Vertex Cover Problem

- **Input**: A graph G = (V, E)
- **Output**: A subset of vertices V' ⊆ V such that each edge in E is incident to at least one vertex in V'

```text
1. Soln=∅;
2. while(E is not empty)
   {
   u=find vertex with maximum degree;
   Soln=Soln∪{u};
   Remove all edges from E incident on u;
   (Update E)
   }
3. return Soln;
```

---

## Q2. Job Sequencing Problem with Deadlines

- **Input**: A set of n jobs, where each job i has a deadline di and profit pi.
- **Output**: A sequence of jobs such that each job is done within its deadline and the profit is maximized.
- Using Normal

```cpp
#include <bits/stdc++.h>

using namespace std;
// Normal Way
int main()
{
    /*Darshan Kania*/
    int noJobs;
    cin >> noJobs;
    vector<pair<pair<int, int>, int>> Job(noJobs); // Job Deadline Profit
    // cout << "Enter Job No\tEnter Deadline\tEnter Profit\n";
    int maxDeadline = 0;
    for (auto &it : Job)
    {
        cin >> it.first.first >> it.first.second >> it.second;
        it.first.second--;
        maxDeadline = max(maxDeadline, it.first.second);
    }
    sort(Job.begin(), Job.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
         { return a.second > b.second; });
    // for (auto it : Job)
    // {
    //     cout << it.first.first << " " << it.first.second << " " << it.second << endl;
    // }
    int noSlots = min(noJobs, maxDeadline);
    // cout << noSlots << endl;
    vector<bool> result(noSlots, false);
    vector<int> ans;
    int profit = 0;
    for (auto it : Job)
    {
        int maxChance = min(noSlots, it.first.second);
        while (maxChance >= 0)
        {
            if (result[maxChance] == false)
            {
                result[maxChance] = true;
                ans.push_back(it.first.first);
                profit += it.second;
                break;
            }
            maxChance--;
        }
    }
    cout << profit << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
```

- Using Disjoint Set Data Structure.
```cppp
```