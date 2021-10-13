class Solution{
public:
    int dp[501][501];

    bool isPalindrome(string str,int i,int j)
    {
        while(i < j)
        {
            if(str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    
    int solve(string str,int i,int j)
    {
        int ans = INT_MAX;
        if(i >= j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(isPalindrome(str,i,j))
        {
            return 0;
        }
        
        for(int k = i;k <= j-1;k++)
        {
            int left = 0;
            int right = 0;
            if(dp[i][k] != -1)
            {
                left = dp[i][k];
            }
            else
            {
                dp[i][k] = solve(str,i,k);
                left = dp[i][k];
            }
            
            if(dp[k+1][j] != -1)
            {
                right = dp[k+1][j];
            }
            else
            {
                dp[k+1][j] = solve(str,k+1,j);
                right = dp[k+1][j];
            }
            
            int temp = 1+left+right;
            
            if(temp < ans)
            {
                ans = temp;
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    
    
    int palindromicPartition(string str)
    {
        int n = str.length();
        memset(dp,-1,sizeof(dp));
        return solve(str,0,n-1);
    }
};
