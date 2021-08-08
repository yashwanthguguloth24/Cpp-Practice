// https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1#

// variant of LIS, in the second for loop check if adjacent or not that’s it.


class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N,1);
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(abs(A[j]-A[i]) == 1 && dp[i] < 1+dp[j])
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        
        int max_val = INT_MIN;
        for(int i = 0;i<N;i++)
        {
            max_val = max(max_val,dp[i]);
        }
        
        return max_val;
    }
};
