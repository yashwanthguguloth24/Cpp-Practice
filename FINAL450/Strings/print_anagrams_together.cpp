// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#

// Sorting individual strings to get matching strings then use map to separate them into groups

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    
    map<string,vector<string>> mp;
    for(int i = 0;i<string_list.size();i++)
    {
        string temp = string_list[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(string_list[i]);
    }
    int idx = 0;
    vector<vector<string>> ans(mp.size());
    for(auto x : mp)
    {
        auto vec = x.second;
        for(int i = 0;i<vec.size();i++)
        {
            ans[idx].push_back(vec[i]);
        }
        idx++;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
