#include<bits/stdc++.h>
using namespace std;
long long CoinChange(int coins[], long long sum, int n)
{
    long long t[n+1][sum+1];
    for(long long i = 0; i<n+1; i++)
    {
        for(long long j = 0; j<sum+1; j++)
        {
            t[i][j] = 0;
        }
    }
    for(long long i = 0; i<n+1; i++)
        t[i][0] = 0;
    for(long long i = 0; i<sum+1; i++)
        t[0][i] = LONG_LONG_MAX - 1;
    t[0][0] = 0;

    for (long long i = 1; i < sum + 1; i++)
    {
            t[1][i] = i / coins[0];
    }
    for(long long i = 2; i<n+1; i++)
    {
        for(long long j = 1; j<sum+1; j++)
        {
            if(coins[i-1] <= j)
                t[i][j] = min(1 + t[i-1][j-coins[j-1]], t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int coins[] = {1, 5, 10, 20, 100};
    int n = sizeof(coins)/sizeof(coins[0]);
    long long sum;
    cin>>sum;
    cout<<CoinChange(coins, sum, n);
}