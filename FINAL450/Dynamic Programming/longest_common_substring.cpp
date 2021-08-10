// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

// keeping a global variable mx to update answer if character at I and j matches


class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        int mx = 0;
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(S1[i-1] == S2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    mx = max(mx,dp[i][j]); 
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return mx;
        
        
    }
};
