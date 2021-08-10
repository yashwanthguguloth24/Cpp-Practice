// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

// Traversing dp table in diagonal fashion and updating the answer


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MinRemovals(int arr[],int n,int k)
{
    vector<vector<int>> dp(n,vector<int>(n,0));
    int i,j;
    for(int gap = 0;gap<n;gap++)
    {
        for(i = 0,j = gap;j<n;j++,i++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                if(arr[j]-arr[i] > k)
                {
                    dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    for(int m = 0;m<n;m++)
    {
        for(int l = 0;l<n;l++)
        {
            cout << dp[m][l] << " ";
        }
        cout << endl;
    }
    return dp[0][n-1];
}



int main()
{
    int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    sort(a,a+n);
    int k = 4;
    cout << MinRemovals(a,n,k);
    return 0;
}
