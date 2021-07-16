// https://practice.geeksforgeeks.org/problems/valid-substring0624/1
// https://leetcode.com/problems/longest-valid-parentheses/

/*
Solved using 2 approaches
1.Using stack : storing the indices on the stack to calculate the answer
2.Using two pointers : using open count and close count, and iterating from front and back.
*/

//************APPROACH 1 ****************************
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>index;
        index.push(-1); // if the substring is prefix
        int ans = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                index.push(i);
            }
            else
            {
                index.pop();
                if(index.size() == 0)
                {
                    index.push(i);
                }
                else
                {
                    ans = max(ans,i-index.top());
                }
            }
        }
        return ans;
    }
};

//************APPROACH 2********************************
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int ans = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if(open == close)
            {
                ans = max(ans,open+close);
            }
            else if(close>open)
            {
                close = open = 0;
            }
        }
        
        close = open = 0;
        for(int i = s.length()-1;i>=0;i--)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if(open == close)
            {
                ans = max(ans,open+close);
            }
            else if(close<open)
            {
                close = open = 0;
            }
        }
        return ans;
        
        
        
        
        
    }
};
