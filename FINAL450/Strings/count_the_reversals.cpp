//https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#

//using stack to know about balanced brackets and find the unbalanced brackets to compute the reversals.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.length();
    if(n%2 != 0)
    {
        return -1;
    }
    else
    {
        int closing = 0;
        int opening = 0;
        stack<char> stk;
        for(int i = 0;i<n;i++)
        {
            char c = s[i];
            if(c == '{')
            {
                opening++;
                stk.push(c);
            }
            else
            {
                if(stk.empty() == 1)
                {
                    closing++;
                }
                else
                {
                    stk.pop();
                    opening--;
                }
            }
        }
        int a1 = 0;
        if(opening%2 == 0)
        {
            a1 = opening/2;
        }
        else
        {
            a1 = (opening/2)+1;
        }
        int a2 = 0;
        if(closing%2 == 0)
        {
            a2 = closing/2;
        }
        else
        {
            a2 = (closing/2)+1;
        }
        int ans = a1+a2;
        return ans;
    }
}
