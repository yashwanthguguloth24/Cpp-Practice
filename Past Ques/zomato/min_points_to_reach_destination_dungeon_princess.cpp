// https://leetcode.com/problems/dungeon-game/
// https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1


class Solution{

	public:
	int minPoints(vector<vector<int>> points, int M, int N) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M,vector<int>(N,0));
        if(N == 1 && M == 1)
        {
            if(points[0][0] >= 0)
            {
                return 1;
            }
            else
            {
                return (1-points[0][0]);
            }
        }
        
        dp[M-1][N-1] = (points[M-1][N-1] > 0)?0:(1-points[M-1][N-1]);
        
        for(int j = N-2;j>=0;j--)
        {
            if(dp[M-1][j+1] == 0)
            {
                dp[M-1][j] = (points[M-1][j] > 0)?(0):(1-points[M-1][j]);
            }
            else
            {
                dp[M-1][j] = max(0,dp[M-1][j+1]-points[M-1][j]);
            }
        }
        
        
        for(int i = M-2;i>=0;i--)
        {
            if(dp[i+1][N-1] == 0)
            {
                dp[i][N-1] = (points[i][N-1] > 0)?0:(1-points[i][N-1]);
            }
            else
            {
                dp[i][N-1] = max(0,dp[i+1][N-1]-points[i][N-1]);
            }
        }
        
        
        for(int i = M-2;i>=0;i--)
        {
            for(int j = N-2;j>=0;j--)
            {
                if(min(dp[i][j+1],dp[i+1][j]) == 0)
                {
                    dp[i][j] = 1-points[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i][j+1],dp[i+1][j])-points[i][j];
                }
                dp[i][j] = max(0,dp[i][j]);
            }
        }
        
        return ((dp[0][0] == 0)?1:dp[0][0]);
        
	} 
};
