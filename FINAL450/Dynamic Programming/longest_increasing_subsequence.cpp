// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#

// dp[i] - LIS upto ith element, for every elements check before elements to get dp[i]

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>dp(n,1);
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(a[j]<a[i] && dp[i] < 1+dp[j])
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        
        int max_val = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            max_val = max(max_val,dp[i]);
        }
        
        return max_val;
    }
};
