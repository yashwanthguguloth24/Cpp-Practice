// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1

// Directly using hashmaps and using the count to find second max count and finding the key corresponding to count

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> hash;
        for(int i = 0;i<n;i++)
        {
            if(hash.find(arr[i]) != hash.end())
            {
                hash[arr[i]]++;
            }
            else
            {
                hash[arr[i]] = 1;
            }
        }
        int highest_freq = -1;
        for(auto x : hash)
        {
            highest_freq = max(x.second,highest_freq);
        }
        int second_highest_freq = -1;
        for(auto y:hash)
        {
            if(y.second != highest_freq)
            {
                second_highest_freq = max(y.second,second_highest_freq);
            }
        }
        string ans;
        for(auto z:hash)
        {
            if(z.second == second_highest_freq)
            {
                ans = z.first;
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
