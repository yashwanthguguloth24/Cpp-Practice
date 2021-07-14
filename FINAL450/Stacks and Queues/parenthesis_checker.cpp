// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

// using stack to push and pop braces.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> stk;
        for(int i = 0;i<x.length();i++)
        {
            char ch = x[i];
            if(ch == '(' || ch == '{' || ch == '[')
            {
                stk.push(ch);
            }
            else if(ch == ')')
            {
                if(stk.empty() || stk.top() != '(')
                {
                    return 0;
                }
                stk.pop();
            }
            else if(ch == '}')
            {
                if((stk.size() == 0) || stk.top() != '{')
                {
                    return 0;
                }
                stk.pop();
            }
            else if(ch == ']')
            {
                if((stk.size() == 0) || stk.top() != '[')
                {
                    return 0;
                }
                stk.pop();
            }
        }
        return stk.size() == 0;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
