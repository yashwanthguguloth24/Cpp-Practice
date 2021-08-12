// https://practice.geeksforgeeks.org/problems/interleaved-strings/1

// check ith char of s1 and jth char of s2 and take decision accordingly

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.length();
        int m = B.length();
        if(n+m != C.length())
        {
            return false;
        }
        
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else if(i == 0)
                {
                    if(B[j-1] == C[i+j-1])
                    {
                        dp[i][j] = dp[i][j-1];
                    }
 
                }
                else if(j == 0)
                {
                    if(A[i-1] == C[i+j-1])
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1])
                {
                    dp[i][j] = dp[i][j-1];
                }
                else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                
                
            }
        }
        return dp[n][m];
    }

};


