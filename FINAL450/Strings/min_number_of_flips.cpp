// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

// Based on the simple logic that 2 alternate strings are only possible and comparing both strings with given.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    string s1 = "";
    for(int i = 0;i<n;i++)
    {
        if(i%2 == 0)
        {
            s1 += "0";
        }
        else
        {
            s1 += "1";
        }
    }
    string s2 = "";
    for(int i = 0;i<n;i++)
    {
        if(i%2 == 0)
        {
            s2 += "1";
        }
        else
        {
            s2 += "0";
        }
    }
    // compare
    int s1_mismatch= 0;
    int s2_mismatch = 0;
    for(int i = 0;i<n;i++)
    {
        if(s1[i] != S[i])
        {
            s1_mismatch++;
        }
        if(s2[i] != S[i])
        {
            s2_mismatch++;
        }
    }
    int ans = min(s1_mismatch,s2_mismatch);
    return ans;
}
