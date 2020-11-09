#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only by Memoization
//1. Basic approach to find solution of Unbounded KnapSack by Recursion.
int UnboundedKnapSackRecursive(int wt[], int val[], int W, int n)
{
	if (n == 0 || W == 0)
		return 0;
	else if (wt[n - 1] <= W)
		return max(val[n - 1] + UnboundedKnapSackRecursive(wt, val, W - wt[n - 1], n), UnboundedKnapSackRecursive(wt, val, W, n - 1));
	else
		return UnboundedKnapSackRecursive(wt, val, W, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of Unbounded KnapSack by Memoization.
int UnboundedKnapSackMemoization(int wt[], int val[], int W, int n)
{
	if (n == 0 || W == 0)
		return 0;
	else if (dp[n][W] != -1)
		return dp[n][W];
	else if (wt[n - 1] <= W)
		return dp[n][W] = max(val[n - 1] + UnboundedKnapSackMemoization(wt, val, W - wt[n - 1], n), UnboundedKnapSackMemoization(wt, val, W, n - 1));
	else
		return dp[n][W] = UnboundedKnapSackMemoization(wt, val, W, n - 1);
}
//3. Dynamic Programming approach 2 to find solution of Unbounded KnapSack by Top Down approach.
int UnboundedKnapSackTopDown(int wt[], int val[], int W, int n)
{
	int t[n + 1][W + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < W + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < W + 1; j++)
		{
			if (wt[i - 1] <= j)
				t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][W];
}
int main()
{
	memset(dp, -1, sizeof(dp)); //Consider it for UnboundedKnapSackMemoization only, not for recursive.
	int wt[] = {5, 10, 15};
	int val[] = {10, 30, 20};
	int W = 100;
	int n = sizeof(val) / sizeof(val[0]);
	cout << "Using Recursion: " << endl;
	cout << UnboundedKnapSackRecursive(wt, val, W, n) << endl;

	cout << "Using Memoization: " << endl;
	cout << UnboundedKnapSackRecursive(wt, val, W, n) << endl;

	cout << "Using TopDown: " << endl;
	cout << UnboundedKnapSackRecursive(wt, val, W, n) << endl;
}
