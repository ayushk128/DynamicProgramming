#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //Used only for SubsetSum Memoization approach
//1. Basic Recursive approach for SubsetSum problem.
bool SubsetSumRecursive(int arr[], int sum, int n)
{
	if(sum == 0)
		return true;
	if(n == 0)
		return false;
	else if(arr[n-1] <= sum)
		return SubsetSumRecursive(arr, sum - arr[n-1], n-1) || SubsetSumRecursive(arr, sum, n-1);
	else
		return SubsetSumRecursive(arr, sum, n-1);
}
//2. Dynamic Programming approach 1 to find solution of SubsetSum by Memoization.
int SubsetSumMemoization(int arr[], int sum, int n)
{	
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum] != -1)
		return dp[n][sum];
	else if(arr[n-1] <= sum)
		return dp[n][sum] = SubsetSumMemoization(arr, sum-arr[n-1], n-1) || SubsetSumMemoization(arr, sum, n-1);
	else
		return dp[n][sum] = SubsetSumMemoization(arr, sum, n-1);
}
//3. Dynamic Programming approach 2 to find solution of SubsetSum by Top Down approach.
bool SubsetSumTopDown(int arr[], int sum, int n)
{
	bool t[n+1][sum+1];
	for(int i = 0; i<n+1; i++)
		t[i][0] = true;
	for(int i = 0; i<sum+1; i++)
		t[0][i] = false;
	t[0][0] = true;
	for(int i = 1; i<n+1; i++){
		for(int j = 1; j<sum+1; j++){
			if(arr[i- 1] <= j)
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			else
				t[i][j] = t[i-1][j];
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
	memset(dp, -1, sizeof(dp)); //Consider it for only Memoization only
	int arr[] = {10, 3, 4, 6};
	int sum = 10;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"With Recursive: "<<endl;
	if(SubsetSumTopDown(arr, sum, n))
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;
		
	cout<<"With Memoization: "<<endl;
	if(SubsetSumMemoization(arr, sum, n))
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;
		
	cout<<"With Top Down: "<<endl;	
	if(SubsetSumTopDown(arr, sum, n))
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;
}
