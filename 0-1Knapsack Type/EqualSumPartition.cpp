#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only for KnapSack Memoization approach
//1->a. Just a helper function for Recursive approach
bool EqualSumPartitionRecursive_helper(int arr[], int sum, int n)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (arr[n - 1] <= sum)
		return EqualSumPartitionRecursive_helper(arr, sum - arr[n - 1], n - 1) || EqualSumPartitionRecursive_helper(arr, sum, n - 1);
	else
		return EqualSumPartitionRecursive_helper(arr, sum, n - 1);
}
//1. Basic Recursive approach for EqualSumPartition problem.
bool EqualSumPartitionRecursive(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0)
		return false;

	else
		return EqualSumPartitionRecursive_helper(arr, sum / 2, n);
}
//2->a. Just a helper function for Memoization approach
int EqualSumPartitionMemoization_helper(int arr[], int sum, int n)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (dp[n][sum] != -1)
		return dp[n][sum];
	else if (arr[n - 1] <= sum)
		return dp[n][sum] = EqualSumPartitionMemoization_helper(arr, sum - arr[n - 1], n - 1) || EqualSumPartitionMemoization_helper(arr, sum, n - 1);
	else
		return dp[n][sum] = EqualSumPartitionMemoization_helper(arr, sum, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of EqualSumPartition problem by Memoization.
int EqualSumPartitionMemoization(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	else
		return EqualSumPartitionMemoization_helper(arr, sum / 2, n);
}
//2. Dynamic Programming approach 2 to find solution of EqualSumPartition problem by Top Down approach.
bool EqualSumPartition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	bool t[n + 1][sum / 2 + 1];
	for (int i = 0; i < n + 1; i++)
		t[i][0] = true;
	for (int i = 0; i < sum / 2 + 1; i++)
		t[0][i] = false;
	t[0][0] = true;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum / 2 + 1; j++)
		{
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum / 2];
}
int main()
{
	memset(dp, -1, sizeof(dp));
	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Using Recursion: " << endl;
	if (EqualSumPartitionRecursive(arr, n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "-----------------------" << endl;
	cout << "Using Memoization: " << endl;
	if (EqualSumPartitionMemoization(arr, n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "-----------------------" << endl;
	cout << "Using Topdown: " << endl;
	if (EqualSumPartition(arr, n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
