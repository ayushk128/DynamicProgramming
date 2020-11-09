#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only for Count Of SubsetSum Memoization approach
//1. Basic Recursive approach for Count Of SubsetSum problem.
int CountOfSubsetSumWithGivenSumRecursive(int arr[], int sum, int n)
{
	if (sum == 0)
		return true;
	if (n == 0)
		return false;
	else if (arr[n - 1] <= sum)
		return CountOfSubsetSumWithGivenSumRecursive(arr, sum - arr[n - 1], n - 1) + CountOfSubsetSumWithGivenSumRecursive(arr, sum, n - 1);
	else
		return CountOfSubsetSumWithGivenSumRecursive(arr, sum, n - 1);
}
//2. Dynamic Programming approach 1 to find solution of Count Of SubsetSum by Memoization.
int CountOfSubsetSumWithGivenSumMemoization(int arr[], int sum, int n)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (dp[n][sum] != 0)
		return dp[n][sum];
	else if (arr[n - 1] <= sum)
		return dp[n][sum] = CountOfSubsetSumWithGivenSumMemoization(arr, sum - arr[n - 1], n - 1) + CountOfSubsetSumWithGivenSumMemoization(arr, sum, n - 1);
	else
		return dp[n][sum] = CountOfSubsetSumWithGivenSumMemoization(arr, sum, n - 1);
}
//3. Dynamic Programming approach 2 to find solution of Count Of SubsetSum by Top Down approach.
int CountOfSubsetSumWithGivenSumTopDown(int arr[], int sum, int n)
{
	int t[n + 1][sum + 1];
	for (int i = 0; i < n + 1; i++)
		t[i][0] = true;
	for (int i = 0; i < sum + 1; i++)
		t[0][i] = false;
	t[0][0] = true;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	/*	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<sum+1; j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	return t[n][sum];
}
int main()
{
	memset(dp, 0, sizeof(dp)); //Consider it for only Memoization only
	int arr[] = {2, 3, 5, 6, 8};
	int sum = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "With Recursive: " << endl;
	cout << CountOfSubsetSumWithGivenSumRecursive(arr, sum, n) << endl;

	cout << "With Memoization: " << endl;
	cout << CountOfSubsetSumWithGivenSumMemoization(arr, sum, n) << endl;

	cout << "With Top Down: " << endl;
	cout << CountOfSubsetSumWithGivenSumTopDown(arr, sum, n) << endl;
}
