// https://practice.geeksforgeeks.org/problems/word-break1352/1


// DP(if string = "abcd" , search "a" if present then search "bcd" recursively. Use DP array for memoisation)


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings


unordered_map<string,int> dp;

int DidWordBroke(string s,vector<string> &B)
{
    int n = s.length();
    if(n == 0)
    {
        return 1;
    }
    if(dp[s] != 0)
    {
        return dp[s];
    }
    for(int i = 1;i<=n;i++)
    {
        int flag = 0;
        string sub_s = s.substr(0,i);
        for(int j = 0;j<B.size();j++)
        {
            if(sub_s.compare(B[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1 && DidWordBroke(s.substr(i,n),B) == 1)
        {
            return dp[s] = 1;
        }
    }
    return dp[s] = -1;
}



int wordBreak(string A, vector<string> &B) {
    //code here
    int ans = DidWordBroke(A,B);
    if(ans == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
