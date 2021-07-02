// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

// Approach : Similar to Smallest distinct window problem, but use 2 hash maps

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(s.length()<p.length())
        {
            return "-1";
        }
        int hash_patt[256] = {0};
        int hash_str[256] = {0};
        int start_ind = -1;
        int min_len = INT_MAX;
        int i = 0;
        int N = p.length();
        for(int k = 0;k<N;k++)
        {
            hash_patt[p[k]]++;
        }
        int cnt = 0;
        string ans;
        for(int j = 0;j<s.length();j++)
        {
            hash_str[s[j]]++;
            if(hash_str[s[j]] <= hash_patt[s[j]])
            {
                cnt++;
            }
            if(cnt == N)
            {
                while((hash_str[s[i]] > hash_patt[s[i]]) || hash_patt[s[i]] == 0)
                {
                    if(hash_str[s[i]] > hash_patt[s[i]])
                    {
                        hash_str[s[i]]--;
                    }
                    i++;
                }
                int window_len = j-i+1;
                if(min_len > window_len)
                {
                    min_len = window_len;
                    start_ind = i;
                }
            }
        }
        if(min_len == INT_MAX)
        {
            return "-1";
        }
        ans = s.substr(start_ind,min_len);
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
