/*Created at:	2025-03-27 09:06:52 (Thursday)*/

#include <bits/stdc++.h>

using namespace std;

// Structure to represent a state in the priority queue
struct State
{
    int level;              // Current job level
    int currentCost;        // Current cost
    vector<int> assignment; // Job assignment
    vector<bool> assigned;  // Assigned workers

    // Custom comparator for priority queue (min-heap)
    bool operator<(const State &other) const
    {
        return currentCost > other.currentCost; // Min-heap based on cost
    }
};

// Function to calculate the minimum cost using Branch and Bound with Priority Queue
int solveJobAssignment(int n, int m, vector<vector<int>> &cost)
{
    priority_queue<State> pq; // Min-heap to store states
    int minCost = INT_MAX;

    // Initial state
    pq.push({0, 0, vector<int>(n, -1), vector<bool>(m, false)});

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        // If all jobs are assigned, update the minimum cost
        if (current.level == n)
        {
            minCost = min(minCost, current.currentCost);
            continue;
        }

        // Try assigning each worker to the current job
        for (int j = 0; j < m; j++)
        {
            if (!current.assigned[j])
            { // If worker j is not already assigned
                State next = current;
                next.level++;
                next.currentCost += cost[current.level][j];
                next.assignment[current.level] = j;
                next.assigned[j] = true;

                // Push the new state into the priority queue
                pq.push(next);
            }
        }
    }

    return minCost;
}

int main()
{
    /*Darshan Kania*/
    // Job Assignment
    // Input number of jobs and workers
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(m));
    // Input cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cost[i][j];

    // Solve the problem using Priority Queue
    int minCost = solveJobAssignment(n, m, cost);

    // Output the minimum cost
    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}