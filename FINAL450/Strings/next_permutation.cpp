// https://practice.geeksforgeeks.org/problems/next-permutation5226/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = N-1;
        while(i>0 && arr[i]<=arr[i-1])
        {
            i--;
        }
        if(i == 0)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        {
            int dec_ind = i-1;
            int dec_ele = arr[dec_ind];
            int to_swap = N-1;
            for(int k = dec_ind+1;k<N-1;k++)
            {
                if(arr[k]>dec_ele && arr[k+1]<= dec_ele)
                {
                    to_swap = k;
                    break;
                }
            }
            swap(arr[dec_ind],arr[to_swap]);
            reverse(arr.begin()+dec_ind+1,arr.end());
            
        }
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
