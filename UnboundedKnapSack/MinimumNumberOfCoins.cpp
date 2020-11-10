//Special Problem, different form others
#include <bits/stdc++.h>
using namespace std;
int MinimumNumberOfCoins(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
            t[i][j] = 0;
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int i = 0; i < sum + 1; i++)
        t[0][i] = INT_MAX - 1;

    t[0][0] = 0;

    for (int i = 1; i < sum + 1; i++)
    {
        if (i % coins[0] == 0)
            t[1][i] = i / coins[0];
        else
            t[1][i] = INT_MAX - 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 11;
    cout << "Using Top Down" << endl;
    cout << MinimumNumberOfCoins(coins, sum, n) << endl;
}