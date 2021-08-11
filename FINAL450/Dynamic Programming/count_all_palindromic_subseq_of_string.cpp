// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
// https://www.youtube.com/watch?v=YHSjvswCXC8


// pepcoding video derivation on possibilities , check for character equality conditions 


class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n = str.length();
        long long int m = pow(10,9)+7;
        vector<vector<long long int>> dp(n,vector<long long int>(n,0));
        int i,j;
        for(int gap = 0;gap<n;gap++)
        {
            for(i = 0,j = gap;j<n;j++,i++)
            {
                if(gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if(str[i] == str[j])
                {
                    dp[i][j] = (1+(dp[i+1][j])+(dp[i][j-1]));
                }
                else
                {
                    dp[i][j] = ((dp[i+1][j])+(dp[i][j-1])-(dp[i+1][j-1]));
                }
                dp[i][j] +=m;
                dp[i][j] %=m;
            }
        }
        return (dp[0][n-1]);
    }
     
};
