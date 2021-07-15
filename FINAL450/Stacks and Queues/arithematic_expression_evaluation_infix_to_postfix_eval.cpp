// Interview and Standard Question on stack

// Infix to Postfix --> Postfix Evaluate.

#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

string InfixToPostfix(string s)
{
    string ans = "";
    stack<char> stk;
    unordered_map<char,int> precedence = {{'*',2},{'/',2},{'+',1},{'-',1}};
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {
            while(stk.size() != 0 && precedence[s[i]] <= precedence[stk.top()])
            {
                char top = stk.top();
                ans += top;
                stk.pop();
            }
            stk.push(s[i]);
        }
        else if(s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(stk.size() != 0 && stk.top() != '(')
            {
                char top = stk.top();
                ans += top;
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            ans += s[i];
        }
    }
    while(stk.size() != 0)
    {
        char top = stk.top();
        ans += top;
        stk.pop();
    }
    return ans;

}

int PostfixEvaluate(string S)
{
    stack<string> stk;
    for(int i = 0;i<S.length();i++)
    {
        if(S[i] == '+')
        {
            int val1 = stoi(stk.top());
            stk.pop();
            int val2 = stoi(stk.top());
            stk.pop();
            int val3 = val1+val2;
            stk.push(to_string(val3));
        }
        else if(S[i] == '-')
        {
            int val1 = stoi(stk.top());
            stk.pop();
            int val2 = stoi(stk.top());
            stk.pop();
            int val3 = val2-val1;
            stk.push(to_string(val3));
        }
        else if(S[i] == '*')
        {
            int val1 = stoi(stk.top());
            stk.pop();
            int val2 = stoi(stk.top());
            stk.pop();
            int val3 = val2*val1;
            stk.push(to_string(val3));
        }
        else if(S[i] == '/')
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
            string to_push;
            to_push.push_back(S[i]);
            stk.push(to_push);
        }
    }
    int ans = stoi(stk.top());
    return ans;        
}


int main()
{
    // string s = "(1+2)*(3+4)"; //3*7 = 21 
    // string s = "(7/7)*(3/3)+9";
    string s = "(7*4)*(3/3)+9";
    // unordered_map<char,int> precedence = {{'*',2},{'/',2},{'+',1},{'-',1}};
    // cout << precedence['*'] << endl;
    // cout << InfixToPostfix(s) << endl;
    string out = InfixToPostfix(s);
    cout << PostfixEvaluate(out) << endl;
    return 0;
}
