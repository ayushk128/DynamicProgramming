#include <bits/stdc++.h>
using namespace std;
string LCSPrint(string x, string y, int m, int n)
{
    int t[m + 1][n + 1];
    string s;
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    cout << LCSPrint(x, y, x.length(), y.length()) << endl;
}