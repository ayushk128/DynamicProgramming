#include<bits/stdc++.h>
using namespace std;
int LCSubstring(string x, string y, int m, int n, int count)
{
    if(m == 0 || n == 0)
        return count;
    if(x[m-1] == y[n-1])
    {
        count = LCSubstring(x, y, m-1, n-1, count+1);
    }
    else
    {
        count = max(LCSubstring(x, y, m, n-1, 0), LCSubstring(x, y, m-1, n, 0));
    }
    return count;
    
}
int LCSubstringTopDown(string x, string y, int m, int n)
{
    int res = 0;
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
                t[i][j] = t[i-1][j-1] + 1;
            else
                t[i][j] = 0;
        }
    }
    for(int i = 0; i<m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            if(t[i][j] > res)
                res = t[i][j];
        }
    }
    return res;
}
int main()
{
    string x = "abcdxyzaaaaaa";
    string y = "xyzaaaaaabcd";
    cout<<"Using Recursion"<<endl;
    cout<<LCSubstring(x, y, x.length(), y.length(), 0)<<endl;
    
    cout<<"Using Top Down"<<endl;
    cout<<LCSubstringTopDown(x, y, x.length(), y.length())<<endl;
}