// https://leetcode.com/problems/generate-parentheses/

// using backtracking and keep the count of closing and opening braces and adding brackets based on count


class Solution {
public:
    vector<string> ans;
    
    void GP(string s,int open_cnt,int close_cnt, int n)
    {
        if(close_cnt >= n)
        {
            ans.push_back(s);
            return ;
        }
        
        if(open_cnt < n)
        {
            s.push_back('(');
            GP(s,open_cnt+1,close_cnt,n); //recur
            s.pop_back();
        }
        if(close_cnt < open_cnt)
        {
            s.push_back(')');
            GP(s,open_cnt,close_cnt+1,n); //recur
            s.pop_back();
        }
    }
        
    
    vector<string> generateParenthesis(int n) {
        string s;
        GP(s,0,0,n);
        return ans;
        
    }
};
