// https://practice.geeksforgeeks.org/problems/game-with-string4100/1#

// Approach : We should use PRIORITY QUEUE(MAX HEAP) for insert counts and getting max count in O(1),key is to decrement count every time and sorting the counts

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // This problem should be solved using Priority Queue
        // Update the counts in PQ for every removal of k
        // creating hash to store counts
        int hash[26] = {0};
        for(int i = 0;i<s.length();i++)
        {
            hash[s[i]-97]++;
        }
        priority_queue<int>PQ;
        for(int i = 0;i<26;i++)
        {
            if(hash[i] != 0)
            {
                // cout << hash[i] << endl;
                PQ.push(hash[i]);
            }
        }
        
        while(k)
        {
            // cout << "exe" << endl;
            int tmp = PQ.top();
            PQ.pop();
            tmp--;
            k--;
            PQ.push(tmp);
        }
        int ans = 0;
        while(PQ.size() != 0)
        {
            int temp = PQ.top();
            // cout << temp << endl;
            ans += (temp*temp);
            PQ.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
