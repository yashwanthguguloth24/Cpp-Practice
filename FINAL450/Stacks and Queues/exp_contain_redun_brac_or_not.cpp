// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

// Directly using stacks to put braces and checking while removing.

#include<iostream>
#include<stack>
using namespace std;

bool checkRedundancy(string s)
{
    stack<char>stk;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == ')')
        {
            char top = stk.top();
            stk.pop();
            bool flag = true;
            while(stk.size() != 0 && top != '(')
            {
                if(top == '+' || top == '-' || top == '*' || top == '/')
                {
                    flag = false;
                }
                top = stk.top();
                stk.pop();
            }
            
            if(flag == true)
            {
                return true;
            }
        }
        else 
        {
            stk.push(s[i]);
        }
    }
    return false;
}



int main()
{
    string str;
    // str = "((a+b))";
    str = "(a+(b)/c)";

    // str = "(a+b*(c-d))";
    // cout << checkRedundancy(str) << endl;
    if(checkRedundancy(str))
    {
        cout << "It has reduntant braces" << endl;
    }
    else
    {
        cout << "It doesnt have reduntant braces" << endl;
    }
    return 0;
}
