#include <bits/stdc++.h>

using namespace std;
vector<int> X;
vector<vector<int>> v;
int ans = 0;
bool canPlace(int k, int i)
{
    // can we place kth queen in i th column
    for (int j = 1; j <= k - 1; j++)
    {
        if (X[j] == i || abs(j - k) == abs(X[j] - i))
            return false;
    }
    return true;
}
void NQ(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (canPlace(k, i))
        {
            X[k] = i;
            if(k==n)
            {
                for(int i=1;i<=n;i++)
                {
                    cout<<X[i]<<"";
                }
            }   
            else
                NQ(k + 1, n);
        }
    }
}
int main()
{
    /*Darshan Kania*/
    int n;
    cin >> n;
    X.resize(n + 1);
    NQ(1, n);
    cout << ans << endl;
    return 0;
}