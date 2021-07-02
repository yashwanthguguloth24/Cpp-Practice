// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#

// use hasmap to store count and expand , shrink window accordingly to get answer.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    string findSubString(string str)
    {
        set <char> s;
        for(int i =0;i<str.length();i++)
        {
            s.insert(str[i]);
        }
        int N = s.size();
        unordered_map <char,int> umap;
        int i = 0;
        int cnt = 0;
        int start_ind = -1;
        int min_len = INT_MAX;
        for(int j = 0;j<str.length();j++)
        {
            umap[str[j]]++;
            if(umap[str[j]] == 1)
            {
                cnt++;
            }
            
            if(cnt == N)
            {
                while(umap[str[i]] > 1)
                {
                    if(umap[str[i]] > 1)
                    {
                        umap[str[i]]--;
                    }
                    i++;
                }
                
                int window_len = j-i+1;
                if(window_len < min_len)
                {
                    min_len = window_len;
                    start_ind = i;
                }
            }
        }
        string sub_str = str.substr(start_ind,min_len);
        // cout << sub_str << endl;
        return sub_str;
   
           
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends
