// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#

/*
Done using 2 approaches 1.2D DP 2.1D DP

2D Case:
dp[i][j] represents min cost to fill j weight using 1st i packets
- take and dont take

1D Case:
dp[i] represents min cost to fill ith weight
-find min of all possible divisions of W like k,W-k for k = 1 .... W


*/

int minimumCost(int cost[], int N, int W) 
{ 
          vector<vector<int>> dp(N+1,vector<int> (W+1,0));
        
        for(int i = 0;i<N+1;i++)
        {
            for(int j = 0;j<W+1;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 0;
                }
                else if(i == 0)
                {
                    dp[i][j] = INT_MAX;
                }
                else if(j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(cost[i-1] == -1)
                    {
                        dp[i][j] = max(dp[i-1][j],-1);
                    }
                    else if(j>=i)
                    {
                        if(dp[i][j-i] != INT_MAX)
                        {
                            dp[i][j] = min(cost[i-1]+dp[i][j-i],dp[i-1][j]);
                        }
                        else
                        {
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        if(dp[N][W] == INT_MAX)
        {
            return -1;
        }
}

// ************************ 1D*************************************

int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<int> dp(W+1,0);
	    dp[1] = cost[0];
	    for(int i = 2;i<W+1;i++)
	    {
	        int min_val = INT_MAX;
	        int l = 1;
	        int r = i-1;
	        while(l<=r)
	        {
	            if(dp[l] != -1 && dp[r] != -1)
	            {
	                min_val = min(min_val,dp[r]+dp[l]);
	            }
                l++;
                r--;
	        }
	        
	        if(i<N+1)
	        {
	            if(cost[i-1] != -1)
	            {
	                dp[i] = min(cost[i-1],min_val);
	            }
	            else
	            {
	                if(min_val == INT_MAX)
	                {
	                    dp[i] = -1;
	                }
	                else
	                {
	                    dp[i] = min_val;
	                }
	            }
	        }
	        else
	        {
                if(min_val == INT_MAX)
                {
                    dp[i] = -1;
                }
                else
                {
                    dp[i] = min_val;
                }
	        }
	        
	    }
       return dp[W]; 
	} 
};
