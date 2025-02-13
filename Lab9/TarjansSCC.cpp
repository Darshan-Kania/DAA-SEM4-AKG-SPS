#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int v;
int min(int a, int b)
{
  return (a < b) ? a : b;
}

void findComponent(int u, int disc[], int lowLink[], stack<int> &stk, bool stkItem[])
{
  static int time = 0;
  disc[u] = lowLink[u] = ++time;
  stk.push(u);
  stkItem[u] = true;

  for (int i = 1; i < v; i++)
  {
    if (graph[u][i])
    {
      if (disc[i] == -1)
      {
        findComponent(i, disc, lowLink, stk, stkItem);
        lowLink[u] = min(lowLink[u], lowLink[i]);
      }
      else if (stkItem[i])
        lowLink[u] = min(lowLink[u], disc[i]);
    }
  }

  int poppedItem = 0;
  if (lowLink[u] == disc[u])
  {
    while (stk.top() != u)
    {
      poppedItem = stk.top();
      cout << poppedItem << " ";
      stkItem[poppedItem] = false;
      stk.pop();
    }
    poppedItem = stk.top();
    cout << poppedItem << endl;
    stkItem[poppedItem] = false;
    stk.pop();
  }
}

void strongConComponent()
{
  int disc[v], lowLink[v];
  bool stkItem[v];
  stack<int> stk;

  for (int i = 1; i < v; i++)
  {
    disc[i] = lowLink[i] = -1;
    stkItem[i] = false;
  }

  for (int i = 1; i < v; i++)
    if (disc[i] == -1)
      findComponent(i, disc, lowLink, stk, stkItem);
}

int main()
{
  int noV;
  cin >> noV;
  v = noV + 1;
  int noEdge;
  cin >> noEdge;
  graph.resize(noV + 1, vector<int>(noV + 1, 0));
  for (int i = 0; i < noEdge; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
  }
  strongConComponent();
}