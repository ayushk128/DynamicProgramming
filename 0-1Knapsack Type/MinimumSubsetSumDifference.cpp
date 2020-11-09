#include<bits/stdc++.h>
using namespace std;
bool *MinimunSubsetSumDifference_helper(int arr[], int sum, int n)  //Just a helper function which is called by MinimumSubsetSumDifference function.
{
	bool *possibleSubsets = (bool *)malloc(sizeof(bool));
	bool t[n+1][sum+1];
	for(int i = 0; i<n+1; i++)
		t[i][0] = true;
	for(int i = 0; i<sum+1; i++)
		t[0][i] = false;
	t[0][0] = true;
	for(int i = 1; i<n+1; i++)
	{
		for(int j = 1; j<sum+1; j++)
		{
			if(arr[i-1] <= j)
				t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}
	
	for(int j = 0; j<=sum/2; j++)
		possibleSubsets[j] = t[n][j];
		
	return possibleSubsets;
}
int MinimumSubsetSumDifference(int arr[], int n)  //Top down approach for finding Minimum subset sum difference.
{
	bool *res = (bool *)malloc(sizeof(bool));
	int sum = 0;
	for(int i = 0; i<n; i++)
		sum+=arr[i];
	res = MinimunSubsetSumDifference_helper(arr, sum, n);
	int mn = INT_MAX;
	for(int i = 0; i<=sum/2; i++)
		if(res[i] == true)
			mn = min(mn, sum-2*i);
	return mn;
}
int main()
{
	int arr[] = {3, 1, 4, 2, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<MinimumSubsetSumDifference(arr, n)<<endl;
}
