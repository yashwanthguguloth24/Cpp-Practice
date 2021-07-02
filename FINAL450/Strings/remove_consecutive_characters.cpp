// https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1#

// Basic iteration and add while for traversing through the common characters.

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans = "";
        ans += S[0];
        for(int i = 1;i<S.length();i++)
        {
            if(S[i] == S[i-1])
            {
                while(S[i] == S[i-1])
                {
                    i++;
                }
                i--;
            }
            else
            {
                ans += S[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends
