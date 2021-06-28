// https://leetcode.com/problems/longest-common-prefix/

// One approach is to do bruteforce all strs. For Other approach, we need to sort the strings and compare first and last lo get common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int N = strs.size();
        int n = strs[0].size();
        int m = strs[N-1].size();
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<m)
        {
            if(strs[0][i] == strs[N-1][j])
            {
                i++;
                j++;
                ans++;
            }
            else
            {
                break;
            }
        }
        string sub_str = strs[0].substr(0,ans);
        return sub_str;
    }
};
