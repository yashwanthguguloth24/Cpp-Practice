   int wildCard(string pattern,string str)
    {
        string p = pattern;
        string s = str;
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(i == 0 and j == 0)
                {
                    dp[i][j] = true;
                }
                else if(i == 0)
                {
                    dp[i][j] = false;
                }
                else if(j == 0)
                {
                    dp[i][j] = false;
                    if(p[i-1] == '*')
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else
                {
                    char pat = p[i-1];
                    char curr = s[j-1];
                    if(pat == '*')
                    {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else if(pat == '?' || pat == curr)
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
    
};
