// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

// Using diagonal filling method of DP matrix


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestPalindromicSubsequence(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int i,j;
    for(int gap = 0;gap<n;gap++)
    {
        for(i = 0,j = gap;j<n;j++,i++)
        {
            if(gap == 0)
            {
                dp[i][j] = 1;
            }
            else if(s[i] == s[j])
            {
                dp[i][j] = 2+dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];


}



int main()
{
    string s = "GEEKSFORGEEKS";
    cout << LongestPalindromicSubsequence(s) << endl;

    return 0;
}
