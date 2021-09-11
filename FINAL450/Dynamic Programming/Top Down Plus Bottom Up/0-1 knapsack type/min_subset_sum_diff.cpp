// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1


/*
Let sums be s1 and s2
then s2-s1 = min , Also s1+s2 = sum

==> sum-2*s1 should be minimum
Find all possible subset sums 0< s1 < sum and find minimum of sum-2*s1


Find all possible subset sums 0< s1 < sum -- already solved

Find if subset with given sum is present or not where sum = s1 = {all possible} ==> which is found in last row of dp array of is subsetsum possible question
*/



class Solution{

  public:
  
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sm = 0;
	    for(int i = 0;i<n;i++) sm +=arr[i];
        
        vector<vector<int>> dp(n+1,vector<int>(sm+1,0));	    
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=sm;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                else if(j == 0)
                    dp[i][j] = 1;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=sm;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        int mx_val = 0;
        for(int i = 0;i<=(sm/2);i++)
        {
            if(dp[n][i] == 1)
            {
                mx_val = i;
            }
        }
        // cout << mx_val << endl;
        return (sm-2*mx_val);        
        
        
	} 
};
