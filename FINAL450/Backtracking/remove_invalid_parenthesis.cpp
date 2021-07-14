// https://leetcode.com/problems/remove-invalid-parentheses/


// ***************TRY1*******************************
// 63/125 TEST CASES PASSED.
// remove given number of braces until rem_braces are 0 and then check if it is a valid string.
class Solution {
public:
    int MinRemovals(string s)
    {
        stack<char> stk;
        for(int i = 0;i<s.length();i++)
        {
            char c = s[i];
            if(c == '(')
            {
                stk.push('(');
            }
            else if(c == ')')
            {
                if(stk.size() == 0)
                {
                    stk.push(')');
                }
                else if(stk.top() == '(')
                {
                    stk.pop();
                }
                else if(stk.top() == ')')
                {
                    stk.push(')');
                }
            }
            else
            {
                continue;
            }
        }
        return stk.size();
    }
    
    set<string> hash;
    vector<string> ans;
    void removeIPT(string s,int rem)
    {
        // base case
        if(rem == 0)
        {
            int num = MinRemovals(s);
            if(num == 0)
            {
                if(hash.find(s) == hash.end())
                {
                    ans.push_back(s);
                    hash.insert(s);
                }
            }
            return ;
        }
        
        for(int i = 0;i<s.length();i++)
        {
            string f = s.substr(0,i);
            string l = s.substr(i+1);
            removeIPT(f+l,rem-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int minRem = MinRemovals(s);
        removeIPT(s,minRem);
        return ans;
    }
};

// ***************TRY2*******************************
// 72/125 TEST CASES PASSED.
// remove given number of braces of open and close and then check if it is a valid string 
class Solution {
public:
    vector<int> MinRemovals(string s)
    {
        stack<char> stk;
        for(int i = 0;i<s.length();i++)
        {
            char c = s[i];
            if(c == '(')
            {
                stk.push('(');
            }
            else if(c == ')')
            {
                if(stk.size() == 0)
                {
                    stk.push(')');
                }
                else if(stk.top() == '(')
                {
                    stk.pop();
                }
                else if(stk.top() == ')')
                {
                    stk.push(')');
                }
            }
            else
            {
                continue;
            }
        }
        int sz = stk.size();
        int open_cnt = 0;
        int close_cnt = 0;
        while(stk.size() != 0)
        {
            char c = stk.top();
            if(c == '(')
            {
                open_cnt++;
                stk.pop();
            }
            else if(c == ')')
            {
                close_cnt++;
                stk.pop();
            }
        }
        vector<int> vals;
        vals.push_back(sz);
        vals.push_back(open_cnt);
        vals.push_back(close_cnt);
        return vals;
    }
    
    set<string> hash;
    vector<string> ans;
    void removeIPT(string s,int open_cnt,int close_cnt)
    {
        // base case
        if(open_cnt == 0 && close_cnt == 0)
        {
            vector<int> num = MinRemovals(s);
            if(num[0] == 0)
            {
                if(hash.find(s) == hash.end())
                {
                    ans.push_back(s);
                    hash.insert(s);
                }
            }
            return ;
        }
        
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == ')')
            {
                if(ch == '(')
                {
                    if(open_cnt > 0)
                    {
                        string f = s.substr(0,i);
                        string l = s.substr(i+1);
                        removeIPT(f+l,open_cnt-1,close_cnt);
                    }
                }
                else if(ch == ')')
                {
                    if(close_cnt > 0)
                    {
                        string f = s.substr(0,i);
                        string l = s.substr(i+1);
                        removeIPT(f+l,open_cnt,close_cnt-1);
                    }                    
                }
            }
            else
            {
                continue;
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<int> minRem = MinRemovals(s);
        removeIPT(s,minRem[1],minRem[2]);
        return ans;
    }
};

// ***************TRY3*******************************
// 117/125 TEST CASES PASSED.
// keep close count and open count to check valid string and removing the braces and finally pushing min removal valid string to answer.
class Solution {
public:
    int min_rem = 100;
    set<string> ans;
    void removeIPBT(string s,int i, int open_cnt,int close_cnt,string exp,int rem_cnt)
    {
        // base case
        if(i == s.length())
        {
            if(close_cnt == open_cnt)
            {
                if(rem_cnt <= min_rem)
                {
                    if(rem_cnt < min_rem)
                    {
                        ans.clear();
                        min_rem = rem_cnt;
                    }
                    ans.insert(exp);
                }
            }
        }
        else
        {
            
            char ch = s[i];
            if(ch != '(' && ch != ')')
            {
                exp.push_back(ch);
                removeIPBT(s,i+1,open_cnt,close_cnt,exp,rem_cnt);
                exp.pop_back();
            }
            else
            {
                removeIPBT(s,i+1,open_cnt,close_cnt,exp,rem_cnt+1);
                exp.push_back(ch);
                if(s[i] == '(')
                {
                    // exp.push_back(ch);
                    removeIPBT(s,i+1,open_cnt+1,close_cnt,exp,rem_cnt);
                    // exp.pop_back();
                }
                else if(close_cnt < open_cnt)
                {
                    // exp.push_back(ch);
                    removeIPBT(s,i+1,open_cnt,close_cnt+1,exp,rem_cnt);
                    // exp.pop_back();
                }
                exp.pop_back();
            }
        }

        
        
        
        
        
        
    }
    vector<string> removeInvalidParentheses(string s) {
        string exp;
        removeIPBT(s,0,0,0,exp,0);
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};


// ***************TRY4- CORRECT*******************************
// 125/125 TEST CASES PASSED.
// keep close count and open count to check valid string and keeping track of number of open and close brackets that are needed to be removed.

class Solution {
public:
    vector<int> MinRemovals(string s)
    {
        stack<char> stk;
        for(int i = 0;i<s.length();i++)
        {
            char c = s[i];
            if(c == '(')
            {
                stk.push('(');
            }
            else if(c == ')')
            {
                if(stk.size() == 0)
                {
                    stk.push(')');
                }
                else if(stk.top() == '(')
                {
                    stk.pop();
                }
                else if(stk.top() == ')')
                {
                    stk.push(')');
                }
            }
            else
            {
                continue;
            }
        }
        int sz = stk.size();
        int open_cnt = 0;
        int close_cnt = 0;
        while(stk.size() != 0)
        {
            char c = stk.top();
            if(c == '(')
            {
                open_cnt++;
                stk.pop();
            }
            else if(c == ')')
            {
                close_cnt++;
                stk.pop();
            }
        }
        vector<int> vals;
        vals.push_back(sz);
        vals.push_back(open_cnt);
        vals.push_back(close_cnt);
        return vals;
    }
    
    set<string> hash;
    vector<string> ans;
    void removeIPT(string s,int i,int open_rem,int close_rem,int open_cnt,int close_cnt,string expres)
    {
        // base case
        if(i == s.length())
        {
            if(open_rem == 0 && close_rem == 0)
            {
                // vector<int> num = MinRemovals(s);
                // if(num[0] == 0)
                // {
                if(hash.find(expres) == hash.end())
                {
                    ans.push_back(expres);
                    hash.insert(expres);
                }
                // }
                return ;
            }
        }
        else
        {
            char ch = s[i];
            if(ch == '(' && open_rem > 0)
            {
                removeIPT(s,i+1,open_rem-1,close_rem,open_cnt,close_cnt,expres);
            }
            else if(ch == ')' && close_rem > 0)
            {
                removeIPT(s,i+1,open_rem,close_rem-1,open_cnt,close_cnt,expres);
            }
            expres.push_back(ch);
            if(ch != '(' && ch != ')')
            {
                removeIPT(s,i+1,open_rem,close_rem,open_cnt,close_cnt,expres);
            }
            else if(ch == '(')
            {
                // take it
                removeIPT(s,i+1,open_rem,close_rem,open_cnt+1,close_cnt,expres);
            }
            else if(close_cnt < open_cnt)
            {
                // take close brace
                removeIPT(s,i+1,open_rem,close_rem,open_cnt,close_cnt+1,expres);
            }
            expres.pop_back();
        }
        
       
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<int> minRem = MinRemovals(s);
        string exprs = "";
        removeIPT(s,0,minRem[1],minRem[2],0,0,exprs);
        return ans;
    }
};













