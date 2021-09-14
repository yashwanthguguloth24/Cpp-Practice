// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution
{
    public:
    
    int max3(int a,int b,int c)
    {
        int temp = max(a,b);
        int res = max(temp,c);
        return res;
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        for(int i = 0;i<n+1;i++)
        {
            dp[i] = -1;
        }
        
        dp[0] = 0;
        int cuts[3] = {x,y,z};
        for(int j = 0;j<3;j++)
        {
            for(int i = 0;i<n+1;i++)
            {
                if(i>=cuts[j])
                {
                    if(dp[i-cuts[j]] != -1)
                    {
                        dp[i] = max(dp[i],1+dp[i-cuts[j]]);
                    }
                }
            }
        }
        if(dp[n] == -1)
        {
            return 0;
        }
        else
        {
            return dp[n];
        }
        
    }
};
