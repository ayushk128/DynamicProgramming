#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only for CoinChange Ways Memoization approach
//1. Basic approach to find Coin Change Ways by Recursion.
int CoinChangeWaysRecursive(int coins[], int sum, int n)
{
	if (sum == 0 || sum < 0)
		return 1;
	if (n == 0)
		return 0;
	if (n == 0 && sum != 0)
		return 0;
	else if (coins[n - 1] <= sum)
		return CoinChangeWaysRecursive(coins, sum - coins[n - 1], n) + CoinChangeWaysRecursive(coins, sum, n - 1);
	else
		return CoinChangeWaysRecursive(coins, sum, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of Coin Change Ways by Memoization.
int CoinChangeWaysMemoization(int coins[], int sum, int n)
{
	if (sum == 0 || sum < 0)
		return 1;
	if (n == 0)
		return 0;
	if (n == 0 && sum != 0)
		return 0;
	if (dp[n][sum] != -1)
		return dp[n][sum];
	else if (coins[n - 1] <= sum)
		return dp[n][sum] = CoinChangeWaysMemoization(coins, sum - coins[n - 1], n) + CoinChangeWaysMemoization(coins, sum, n - 1);
	else
		return dp[n][sum] = CoinChangeWaysMemoization(coins, sum, n - 1);
}
//3. Dynamic Programming approach 2 to find solution of Coin Change Ways by Top Down approach.
int CoinChangeWaysTopDown(int coins[], int sum, int n)
{
	int t[n + 1][sum + 1];
	for (int i = 0; i < n + 1; i++)
		t[i][0] = 1;
	for (int i = 0; i < sum + 1; i++)
		t[0][i] = 0;
	t[0][0] = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (coins[i - 1] <= j)
				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum];
}
int main()
{
	memset(dp, -1, sizeof(dp));	//Consider it for CoinChangeWaysMemoization only, not for recursive.
	int coins[] = {1, 2, 3};
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;
	cout << "Using Recursion: " << endl;
	cout << CoinChangeWaysRecursive(coins, sum, n) << endl;

	cout << "Using Memoization: " << endl;
	cout << CoinChangeWaysMemoization(coins, sum, n) << endl;

	cout << "Using TopDown: " << endl;
	cout << CoinChangeWaysMemoization(coins, sum, n) << endl;
}
