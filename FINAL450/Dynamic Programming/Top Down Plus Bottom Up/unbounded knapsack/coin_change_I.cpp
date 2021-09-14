
// https://practice.geeksforgeeks.org/problems/coin-change2448/1#



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
        //   for(int k = 0;k<n+1;k++)
        //   {
        //       cout<<dp[k] << " ";
        //   }
        //   cout << endl;
       }
    //   for(int i = 0;i<n+1;i++)
    //   {
    //       cout<<dp[i] << " ";
    //   }
    //   cout << endl;
        return dp[n];    
    }
};
