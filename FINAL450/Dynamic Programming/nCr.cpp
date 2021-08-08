// https://practice.geeksforgeeks.org/problems/ncr1019/1#

// convert nCr = n-1Cr-1 + n-1Cr,then use DP directly


class Solution{
public:
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        long long m = pow(10,9)+7;
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<=min(i,r);j++)
            {
                if(j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i-1][j-1])%m  + (dp[i-1][j])%m; 
                }
            }
        }
        return (dp[n][r]%m);
    }
};
