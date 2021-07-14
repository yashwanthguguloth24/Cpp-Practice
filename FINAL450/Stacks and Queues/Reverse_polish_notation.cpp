// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Postfix evaluation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(int i = 0;i<tokens.size();i++)
        {
            if(tokens[i] == "+")
            {
                int val1 = stoi(stk.top());
                stk.pop();
                int val2 = stoi(stk.top());
                stk.pop();
                int val3 = val1+val2;
                stk.push(to_string(val3));
            }
            else if(tokens[i] == "-")
            {
                int val1 = stoi(stk.top());
                stk.pop();
                int val2 = stoi(stk.top());
                stk.pop();
                int val3 = val2-val1;
                stk.push(to_string(val3));
            }
            else if(tokens[i] == "*")
            {
                int val1 = stoi(stk.top());
                stk.pop();
                int val2 = stoi(stk.top());
                stk.pop();
                int val3 = val2*val1;
                stk.push(to_string(val3));
            }
            else if(tokens[i] == "/")
            {
                int val1 = stoi(stk.top());
                stk.pop();
                int val2 = stoi(stk.top());
                stk.pop();
                int val3 = val2/val1;
                stk.push(to_string(val3));
            }
            else
            {
                stk.push(tokens[i]);
            }
        }
        int ans = stoi(stk.top());
        return ans;
    }
};
