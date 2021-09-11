// https://leetcode.com/problems/target-sum/

/*
The problem boils down to finding s1-s2 = k;
and we know s1+s2 = sum

=> we need to find number of subsets with sum s1 = (sum+k)/2 ==> already solved

*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sm = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sm += nums[i];
        }
            
        
        if(target > sm || (target+sm)%2 != 0)
        {
            return 0;
        }
        int s = (sm+abs(target))/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(s+1,0));
        
        
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<s+1;j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                    
                else if(i == 0)
                    dp[i][j] = 0;
                    
                else if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j];
                
                else if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<s+1;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return dp[n][s];
        
    }
};
