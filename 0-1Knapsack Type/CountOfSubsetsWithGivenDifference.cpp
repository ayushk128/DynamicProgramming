//The problem Targe Sum is same as this Count Of Subset Sum With Given Difference
#include <bits/stdc++.h>
using namespace std;
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

	return t[n][sum];
}
int CountOfSubsetSumWithGivenDifference(int arr[], int diff, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int s = (diff + sum) / 2;
	return CountOfSubsetSumWithGivenSumTopDown(arr, s, n);
}
int main()
{
	int arr[] = {1, 1, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int diff = 1;
	cout << CountOfSubsetSumWithGivenDifference(arr, diff, n) << endl;
}
