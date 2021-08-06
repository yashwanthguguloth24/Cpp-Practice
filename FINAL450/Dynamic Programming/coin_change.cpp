// https://practice.geeksforgeeks.org/problems/coin-change2448/1#

// update dp table seperately with each of the denomination 

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       long long int dp[n+1] = {0};
       dp[0] = 1;

       
       for(int j = 0;j<m;j++)
       {
           for(int i = 1;i<n+1;i++)
           {
               if(i>=S[j])
               {
                   dp[i] = dp[i]+dp[i-S[j]];
               }
           }
       }

        return dp[n];    
    }
};
