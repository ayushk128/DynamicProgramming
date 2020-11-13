#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int MCMRecursive(int arr[], int i, int j)
{
    int temp;
    int min = INT_MAX;
    if(i >= j)
        return 0;
    for(int k = i; k<=j-1; k++)
    {
        temp = MCMRecursive(arr, i, k) + MCMRecursive(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        if(temp < min)
            min = temp;
    }
    return min;
}
int MCMMemoization(int arr[], int i, int j)
{
    int temp;
    int min = INT_MAX;
    int count;
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    for(int k = i; k<=j-1; k++)
    {
        temp = MCMMemoization(arr, i, k) + MCMMemoization(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        if(temp < min)
            min = temp;
    }
    return dp[i][j] = min;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Using Recursion: "<<endl;
    cout<<MCMRecursive(arr, 1, n-1)<<endl;

    cout<<"Using Memoization: "<<endl;
    cout<<MCMMemoization(arr, 1, n-1)<<endl;
}