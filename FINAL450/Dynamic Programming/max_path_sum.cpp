//https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

// Approach similar to GOLD MINE PROBLEM, updating values in a top down fashion


class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        
        for(int row = N-1;row>=0;row--)
        {
            for(int col = 0;col<N;col++)
            {
                if(row == N-1)
                {
                    dp[row][col] = Matrix[row][col];
                }
                else
                {
                    int bottom = dp[row+1][col];
                    int bottom_left = (col > 0)?dp[row+1][col-1]:0;
                    int bottom_right = (col < N-1)?dp[row+1][col+1]:0;
                    dp[row][col] = max(bottom,max(bottom_right,bottom_left))+Matrix[row][col];
                }
            }
        }
        int ans = -1;
        for(int i = 0;i<N;i++)
        {
            ans = max(ans,dp[0][i]);
        }
        return ans;
    }
};
