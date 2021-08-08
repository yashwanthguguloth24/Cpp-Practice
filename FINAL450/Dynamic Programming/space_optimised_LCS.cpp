// https://www.geeksforgeeks.org/space-optimized-solution-lcs/

// important observation is that we use every col of row-1 to fill row.So storing row,row-1 is sufficient for computation

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int LCS_Space_Optimised(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(2,vector<int> (n+1,0));

    bool b = 0; 

    for(int i = 0;i<m+1;i++)
    {
        b = i & 1;
        for(int j = 0;j<n+1;j++)
        {
            if(i == 0|| j==0)
            {
                dp[b][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                dp[b][j] = 1+dp[1-b][j-1];
            }
            else
            {
                dp[b][j] = max(dp[1-b][j],dp[b][j-1]);
            }
        }
    }

    return dp[b][n];
}






int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
 
    printf("Length of LCS is %d\n", LCS_Space_Optimised(X,Y));    
    return 0;
}
