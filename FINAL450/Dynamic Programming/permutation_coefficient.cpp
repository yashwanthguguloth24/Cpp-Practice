// https://www.geeksforgeeks.org/permutation-coefficient/

// conversion of nPk to (n-1) and (k-1) equation and using dp table to compute the recurrence relation

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long long int P(int n,int k)
{
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j <= min(i,k);j++)
        {
            if(j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j]+j*dp[i-1][j-1];
            }
        }

    }

    return dp[n][k];


}



int main()
{
    cout << P(10,2) << endl;
    return 0;
}
