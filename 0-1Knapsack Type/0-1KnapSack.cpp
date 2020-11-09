#include <bits/stdc++.h>
using namespace std;
static int t[1001][1001]; //Used only for KnapSack Memoization approach
//Function to find maximum of two numbers
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
//1. Basic approach to find KnapSack by Recursion.
int KnapSackRecursive(int wt[], int val[], int W, int n)
{
	if (n == 0 || W == 0)
		return 0;
	else if (wt[n - 1] <= W)
		return max(val[n - 1] + KnapSackRecursive(wt, val, W - wt[n - 1], n - 1), KnapSackRecursive(wt, val, W, n - 1));
	else
		return KnapSackRecursive(wt, val, W, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of KnapSack by Memoization.
int KnapSackMemoization(int wt[], int val[], int W, int n)
{
	if (n == 0 || W == 0)
		return 0;
	else if (t[n][W] != -1)
		return t[n][W];

	else if (wt[n - 1] <= W)
		return t[n][W] = max(val[n - 1] + KnapSackMemoization(wt, val, W - wt[n - 1], n - 1), KnapSackMemoization(wt, val, W, n - 1));
	else
		return t[n][W] = KnapSackMemoization(wt, val, W, n - 1);
}
//3. Dynamic Programming approach 2 to find solution of KnapSack by Top Down approach.
int KnapSackTopDown(int wt[], int val[], int W, int n)
{
	int t[n + 1][W + 1];
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < W + 1; j++)
			if (i == 0 || j == 0)
				t[i][j] = 0;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (wt[i - 1] <= j)
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][W];
}
int main()
{
	memset(t, -1, sizeof(t)); //Consider it for KnapSackMemoization only, not for recursive.
	int wt[] = {10, 20, 30, 40};
	int val[] = {50, 30, 45, 60};
	int n = sizeof(val) / sizeof(val[0]);
	int W = 50;
	cout << "By Recursive: " << endl;
	cout << KnapSackRecursive(wt, val, W, n) << endl;
	cout << "By Memoization" << endl;
	cout << KnapSackMemoization(wt, val, W, n) << endl;
	cout << "By Top Down" << endl;
	cout << KnapSackTopDown(wt, val, W, n) << endl;
	return 0;
}

//Problems Related to 0-1 KnapSack
/*
1. Subset Sum
2. Equal Sum Partition
3. Count of subset Sum
4. Minimum Subset Sum Difference
5. Target sum
6. Number of subset with given difference
*/
