// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming


// REC + MEMO


class Solution{   
public:
    
    bool isSubsetSum1(int N, int arr[], int sum,vector<vector<int>> &dp)
    {
        if(sum == 0)
        {
            return true;
        }
        if(N == 0)
        {
            return false;
        }
        
        if(dp[N][sum] != -1)
        {
            return dp[N][sum];
        }
        
        if(arr[N-1] <= sum)
        {
            dp[N][sum] = (isSubsetSum1(N-1,arr,sum-arr[N-1],dp) || isSubsetSum1(N-1,arr,sum,dp));
            return dp[N][sum];
        }
        
        if(arr[N-1] > sum)
        {
            dp[N][sum] = (isSubsetSum1(N-1,arr,sum,dp));
            return dp[N][sum];
        }
    }
    
    
    
    bool isSubsetSum(int N, int arr[], int sum){
        vector<vector<int>> dp(N+1,vector<int>(sum+1,-1));
        return isSubsetSum1(N,arr,sum,dp);
    }
};
