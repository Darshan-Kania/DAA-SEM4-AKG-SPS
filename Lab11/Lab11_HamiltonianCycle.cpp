#include <bits/stdc++.h>

using namespace std;
vector<int> Sol;
bool AnySol = false;

void Print() {
    for (auto it = next(Sol.begin(), 1); it != Sol.end(); ++it)
        cout << *it << " ";
    cout << Sol[1] << endl; // To complete the cycle
    AnySol = true;
}

void NextValue(int k, vector<vector<int>> &G, int noVertex) {
    do {
        Sol[k] = (Sol[k] + 1) % (noVertex + 1);
        if (Sol[k] == 0)
            return;
        bool isValid = true;
        if (G[Sol[k - 1]][Sol[k]] == 1) {
            for (int j = 1; j < k; j++) {
                if (Sol[j] == Sol[k]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid && (k < noVertex || (k == noVertex && G[Sol[k]][Sol[1]] == 1)))
                return;
        }
    } while (true);
}

void HC(int k, vector<vector<int>> &G, int noVertex) {
    while (true) {
        NextValue(k, G, noVertex);
        if (Sol[k] == 0)
            return;
        if (k == noVertex) {
            Print();
        } else {
            HC(k + 1, G, noVertex);
        }
    }
}

int main() {
    int noNode;
    cin >> noNode;
    int noEdge;
    cin >> noEdge;
    vector<vector<int>> G(noNode + 1, vector<int>(noNode + 1, 0));
    for (int i = 0; i < noEdge; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    Sol.resize(noNode + 1, 0);
    Sol[1] = 1; // Start from vertex 1
    HC(2, G, noNode);

    if (!AnySol)
        cout << "No Hamiltonian Cycle found" << endl;

    return 0;
}