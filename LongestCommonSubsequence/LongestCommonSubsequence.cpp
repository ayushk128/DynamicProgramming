//Longest Common subsequence
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int LCSRecursive(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (x[m - 1] == y[n - 1])
        return 1 + LCSRecursive(x, y, m - 1, n - 1);
    else 
        return max(LCSRecursive(x, y, m, n - 1), LCSRecursive(x, y, m - 1, n));
}
int LCSMemoization(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if(dp[m][n] != -1)
        return dp[m][n];
    else if (x[m - 1] == y[n - 1])
        return dp[m][n] = 1 + LCSRecursive(x, y, m - 1, n - 1);
    else 
        return dp[m][n] = max(LCSRecursive(x, y, m, n - 1), LCSRecursive(x, y, m - 1, n));
}
int LCSMemoizationTopDown(string x, string y, int m, int n)
{
    int t[m+1][n+1];
    for(int i = 0; i<m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for(int i = 1; i<m+1; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }

    // for(int i = 0; i<m+1; i++)
    // {
    //     for(int j = 0; j<n+1; j++)
    //     {
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return t[m][n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string x = "AGGTAB";
    string y = "GXTXAYB";

    cout<<"With Recursion: "<<endl;
    cout<<LCSRecursive(x, y, x.length(), y.length())<<endl;;

    cout<<"With Memoization: "<<endl;
    cout<<LCSMemoization(x, y, x.length(), y.length())<<endl;

    cout<<"With Top Down: "<<endl;
    cout<<LCSMemoizationTopDown(x, y, x.length(), y.length())<<endl;
}