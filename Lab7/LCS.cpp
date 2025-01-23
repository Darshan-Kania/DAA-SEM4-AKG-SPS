#include <bits/stdc++.h>

using namespace std;
void Print(const vector<vector<int>> &L,string str1,string str2)
{
    int i = str1.length();
    int j = str2.length();
    string lcs = "";
    
    while(i > 0 && j > 0)
    {
        if(str1[i-1] == str2[j-1])
        {
            lcs = str1[i-1] + lcs;
            i--;
            j--;
        }
        else if(L[i-1][j] >= L[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << "Longest Common Subsequence: " << lcs << endl;
}
int main()
{
    /*Darshan Kania*/
    string str1, str2;
    cout << "Enter String 1: ";
    cin >> str1;
    cout << "Enter String 2: ";
    cin >> str2;
    vector<vector<int>> L(str1.length() + 1, vector<int>(str2.length() + 1));
    for (int i = 0; i <= str1.length(); i++)
    {
        for (int j = 0; j <= str2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    cout << "Max Length SubSequence: " << L[str1.length()][str2.length()] << endl;
    Print(L,str1,str2);
    return 0;
}