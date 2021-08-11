// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// https://leetcode.com/problems/longest-palindromic-substring/

// Using same diagonal filling method and necessary conditions to fill it,keep max_val ,ans string to store answer


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_val = INT_MIN;
        string ans = "";
        vector<vector<int>> dp(n,vector<int>(n,0));
        int i,j;
        for(int gap = 0;gap<n;gap++)
        {
            for(i = 0,j = gap;j<n;j++,i++)
            {
                if(gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if(s[i] == s[j])
                {
                    if((j-i+1 > 2) && dp[i+1][j-1] != 0)
                    {
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                    else if((j-i+1 <= 2))
                    {
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
                if(dp[i][j] > max_val)
                {
                    max_val = dp[i][j];
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
        
    }
};
