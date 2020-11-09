#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only for Rod Cutting Problem Memoization approach
//1. Basic approach to find Rod Cutting Problem by Recursion.
int RodCuttingProblemRecursive(int len[], int price[], int N, int n)
{
	if (n == 0 || N == 0)
		return 0;
	else if (len[n - 1] <= N)
		return max(price[n - 1] + RodCuttingProblemRecursive(len, price, N - len[n - 1], n), RodCuttingProblemRecursive(len, price, N, n - 1));
	else
		return RodCuttingProblemRecursive(len, price, N, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of Rod Cutting Problem by Memoization.
int RodCuttingProblemMemoization(int len[], int price[], int N, int n)
{
	if (n == 0 || N == 0)
		return 0;
	else if (dp[n][N] != -1)
		return dp[n][N];
	else if (len[n - 1] <= N)
		return dp[n][N] = max(price[n - 1] + RodCuttingProblemMemoization(len, price, N - len[n - 1], n), RodCuttingProblemMemoization(len, price, N, n - 1));
	else
		return dp[n][N] = RodCuttingProblemMemoization(len, price, N, n - 1);
}
//3. Dynamic Programming approach 2 to find solution of RodCutting Problem by Top Down approach.
int RodCuttingProblemTopDown(int len[], int price[], int N, int n)
{
	int t[n + 1][N + 1];
	for (int i = 0; i < n + 1; i++)
		t[i][0] = 0;
	for (int i = 0; i < N + 1; i++)
		t[0][i] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (len[i - 1] <= j)
				t[i][j] = max(price[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][N];
}
int main()
{
	memset(dp, -1, sizeof(dp)); //Consider it for Rod Cutting Problem Memoization only, not for recursive.
	int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(len) / sizeof(len[0]);
	int N = 8;
	cout << "By Recursion: " << endl;
	cout << RodCuttingProblemRecursive(len, price, N, n) << endl;

	cout << "By Memoization: " << endl;
	cout << RodCuttingProblemMemoization(len, price, N, n) << endl;

	cout << "By Top Down: " << endl;
	cout << RodCuttingProblemTopDown(len, price, N, n) << endl;
}
