// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
// https://www.youtube.com/watch?v=CiiXBvrX-5A


// Smart use of stack , and checking only necessary problem VVVIMP

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> stk;
        for(int i = 0;i<n;i++)
        {
            stk.push(i);
        }
        
        while(stk.size() > 1)
        {
            int t2 = stk.top();
            stk.pop();
            int t1 = stk.top();
            stk.pop();
            if(M[t1][t2] == 0)
            {
                stk.push(t1);
            }
            else
            {
                stk.push(t2);
            }
        }
        int potent = stk.top();
        stk.pop();
        
        bool flag1 = true;
        for(int i = 0;i<n;i++)
        {
            if(potent != i)
            {
                if(M[i][potent] !=  1)
                {
                    flag1 = false;
                    break;
                }
            }
        }
        
        bool flag2 = true;
        for(int i = 0;i<n;i++)
        {
            if(M[potent][i] != 0)
            {
                flag2 = false;
                break;
            }
        }
        
        if(flag1 && flag2)
        {
            return potent;
        }
        else
        {
            return -1;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
