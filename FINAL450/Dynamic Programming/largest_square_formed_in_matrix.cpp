// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

// dp[i][j] represents largest square including mat[i][j] as a bottom right corner of the square and exploring the possibilities of prev squares


class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = mat[i][j];
                    ans = max(ans,dp[i][j]);
                }
                else if(mat[i][j] == 0)
                {
                    dp[i][j] = mat[i][j];
                    ans = max(ans,dp[i][j]);
                }
                else
                {
                    int poss = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    dp[i][j] = poss+1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
