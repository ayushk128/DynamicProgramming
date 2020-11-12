// Minimum number of Insertion to make a string palindrome
#include <bits/stdc++.h>
using namespace std;
int LCS(string x, string y, int m)
{
    int t[m + 1][m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[m][m];
}
int MinimumNoOfInsertionToMakePalindrome(string y)
{
    string x = y;
    reverse(y.begin(), y.end());
    int len = x.length();
    int longestPalindromicSubstring = LCS(x, y, len);
    return len - longestPalindromicSubstring;
}
int main()
{
    string x = "aebcbda";
    cout << MinimumNoOfInsertionToMakePalindrome(x) << endl;
}