// https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxSumWO3Consec(int arr[],int n)
{
    vector<int> dp(n);

    if(n>=1)
    {
        dp[0] = arr[0];
    }

    if(n>=2)
    {
        dp[1] = arr[0]+arr[1];
    }

    if(n>2)
    {
        dp[2] = max(dp[1],max(arr[2]+arr[0],arr[1]+arr[2]));
    }

    for(int i = 3;i<n;i++)
    {
        dp[i] = max(dp[i-1],max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]));
    }
    return dp[n-1];
}




int main()
{
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxSumWO3Consec(arr, n);
    return 0;
}
