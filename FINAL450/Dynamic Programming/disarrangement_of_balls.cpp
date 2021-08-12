// https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1#


class Solution{
public:

    
    long int disarrange(int N){
        long int m = pow(10,9)+7;
        vector<long int> dp(N+1);
        dp[0] = 1;
        dp[1] = 0;
        
        for(int i = 2;i<N+1;i++)
        {
            dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
            dp[i] += m;
            dp[i] %= m;
        }
        
        return dp[N];
    }
};
