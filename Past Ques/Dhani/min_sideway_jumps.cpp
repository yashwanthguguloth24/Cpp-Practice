// https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int mx = INT_MAX;
        vector<vector<int>> dp(3,vector<int>(n,mx));
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = 1;
        for(int i = 1;i<n;i++)
        {
            // cout << i << endl;
            for(int j = 0;j<3;j++)
            {
                if(obstacles[i] != j+1)
                {
                    dp[j][i] = dp[j][i-1];
                }
            }
            // cout << "came" << endl;
            //if(obstacles[i] == 0) continue;
            
            if(obstacles[i] != 1)
            {
                int val1 = mx;
                int val2 = mx;
                if(obstacles[i] != 2) val1 = dp[1][i];
                if(obstacles[i] != 3) val2 = dp[2][i];
                if(min(val1,val2) != mx)
                {
                    dp[0][i] = min(dp[0][i],1+min(val1,val2));
                }
            }
            // cout << "here1" << endl;
            if(obstacles[i] != 2)
            {
                int val1 = mx;
                int val2 = mx;
                if(obstacles[i] != 1) val1 = dp[0][i];
                if(obstacles[i] != 3) val2 = dp[2][i];
                if(min(val1,val2) != mx)
                {
                    dp[1][i] = min(dp[1][i],1+min(val1,val2));
                }
            }
            // cout << "here2" << endl;
            if(obstacles[i] != 3)
            {
                int val1 = mx;
                int val2 = mx;
                if(obstacles[i] != 1) val1 = dp[0][i];
                if(obstacles[i] != 2) val2 = dp[1][i];
                if(min(val1,val2) != mx)
                {
                    dp[2][i] = min(dp[2][i],1+min(val1,val2));
                }
            } 
            // cout << "here3" << endl;
        }
        // cout << "here" << endl;
        int ans = min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]));
        return ans;
    }
};
