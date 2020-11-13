#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string a, int start, int end)
{
    bool res = true;
    while (start <= end)
    {
        if (a[start] != a[end])
        {
            res = false;
            return res;
        }
        else
        {
            start++;
            end--;
        }
        
    }
    return res;
}
int PalindromePartitioningRecursive(string a, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(a, i, j))
        return 0;
    int temp;
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + PalindromePartitioningRecursive(a, i, k) + PalindromePartitioningRecursive(a, k + 1, j);
        if(temp < mn)
            mn = temp;
    }
    return mn;
}
int main()
{
    string a = "nitik";
    cout << "Using Recursion: " << endl;
    cout << PalindromePartitioningRecursive(a, 0, a.length() - 1) << endl;
}