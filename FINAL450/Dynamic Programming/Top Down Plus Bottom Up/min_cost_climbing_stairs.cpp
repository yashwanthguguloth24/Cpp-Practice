// https://leetcode.com/problems/min-cost-climbing-stairs/

// TOP DOWN --> RECURSION + MEMOIZATION

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int memo[1001];
    int minCost(int i,vector<int>& cost)
    {
        if(i < 0 || i == 0 || i == 1)
        {
            return 0;
        }
        if(memo[i] != -1)
        {
            return memo[i];
        }
        int res = 0;
        if(i>=2)
        {
            res = min(minCost(i-1,cost)+cost[i-1],minCost(i-2,cost)+cost[i-2]);
        }
        return (memo[i]=res);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(memo,-1,sizeof(memo));
        return minCost(n,cost);
    }
};


//////////////////////////////////////////////////////////////////////////
// BOTTOM UP - TABULAR FILLING

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i<=n;i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
