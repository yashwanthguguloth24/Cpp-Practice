// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#

// similar approach to LCS two strings, taking care of conditions if all 3 characters are equal or not


/*


//             all equal - 1+dp[i-1][j-1][k-1]   
//            /                                        
// dp[i][j][k]                                         
//            \                                        
//             else,explore all possibilities and take max val out of them.  




*/

int max6(int a,int b,int c,int d,int e,int f)
{
    int x = max(max(a,b),c);
    int y = max(max(d,e),f);
    return max(x,y);
}


int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1+1,vector< vector<int> >(n2+1,vector<int>(n3+1,0)));
    
    for(int i = 1;i<n1+1;i++)
    {
        for(int j = 1;j<n2+1;j++)
        {
            for(int k = 1;k<n3+1;k++)
            {
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
                {
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k] = max6(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1],dp[i-1][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1]);
                }
            }
        }
    }
    return dp[n1][n2][n3];
    
    
    
}
