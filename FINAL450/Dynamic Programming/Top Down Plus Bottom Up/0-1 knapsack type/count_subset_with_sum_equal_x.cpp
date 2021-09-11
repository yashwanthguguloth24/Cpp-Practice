// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/


#include<bits/stdc++.h>
using namespace std;

int rec(vector<int>arr,int i,int k,vector<vector<int>> &dp)
{
    if(k == 0)
    {
        return 1;
    }
    if(i == 0)
    {
        return 0;
    }
    // cout << "here "<< endl;
    if(dp[i][k] != -1)
    {
        return dp[i][k];
    }

    if(arr[i-1] <= k)
    {
        // cout << "pr1" << endl;
        return dp[i][k] = rec(arr,i-1,k-arr[i-1],dp) + rec(arr,i-1,k,dp);
    }
    else
    {
        // cout << "pr2" << endl;
        return dp[i][k] = rec(arr,i-1,k,dp);
    }

    
}


int NumSubsets(vector<int>arr,int x)
{
    vector<vector<int>> dp(arr.size()+1,vector<int>(x+1,-1));
    return rec(arr,arr.size(),x,dp);
}


int main()
{
    vector<int> arr = {1,1,1,1};
    int x = 1;
    cout << NumSubsets(arr,x) << endl;
    return 0;
}
