// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#

// dp[i] represents max SIS upto ith ele, for conditions use approach similar to LIS(Longest Increasing Subsequence)


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    
	    for(int i = 1;i<n;i++)
	    {
	        int mx_val = INT_MIN;
	        for(int j = 0;j<i;j++)
	        {
	            if(arr[i] > arr[j])
	            {
	                mx_val = max(dp[j],mx_val);
	            }
	            
	        }
	        if(mx_val == INT_MIN)
	        {
	            dp[i] = arr[i];
	        }
	        else
	        {
	            dp[i] = arr[i]+mx_val;
	        }
	    }
	    int ans = INT_MIN;
	    for(int i = 0;i<n;i++)
	    {
	        ans = max(dp[i],ans);
	    }
	    return ans;
	    
	    
	}  
};

