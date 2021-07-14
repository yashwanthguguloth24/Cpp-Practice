// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
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
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
