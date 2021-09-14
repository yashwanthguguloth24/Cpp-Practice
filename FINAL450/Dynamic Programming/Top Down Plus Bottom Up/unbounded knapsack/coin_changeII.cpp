// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#

class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
        vector<int> dp(V+1,INT_MAX-1);
        dp[0] = 0;

        for(int j = 0;j<M;j++)
        {
            for(int i = 1;i<V+1;i++)
            {
                if(i >= coins[j])
                {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }

        
        if(dp[V] == INT_MAX-1)
        {
            return -1;
        }
        return dp[V];
	} 
	  
};
