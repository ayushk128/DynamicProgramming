// Minimum number of deletions to make string x equal to string y
#include<bits/stdc++.h>
using namespace std;
int LCS(string x, string y, int m, int n)
{
    int t[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
        }

    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(x[i-1] == y[j-1])
                t[i][j] = t[i-1][j-1] + 1;
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]); 
        }
        
    }
    
    return t[m][n];
}
int * MinmInsertionDeletion(string x, string y, int m, int n)
{
    int *arr = (int *)malloc(sizeof(int));
    int del = m - LCS(x, y, m, n);
    int ins = n - LCS(x, y, m, n);
    arr[0] = del;
    arr[1] = ins;
    return arr;
}
int main()
{
    string x = "Anurag";
    string y = "Ayush";
    int *arr = MinmInsertionDeletion(x, y, x.length(), y.length());
    cout<<"Deletion: "<<arr[0]<<endl;
    cout<<"Insertion: "<<arr[1]<<endl;
}