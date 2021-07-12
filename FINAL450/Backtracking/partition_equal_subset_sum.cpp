// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

// Partially solved using backtracking 




// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int CompArraySum(int arr[],int N)
    {
        int curr_sum = 0;
        for(int i = 0;i<N;i++)
        {
            curr_sum += arr[i];
        }
        return curr_sum;
    }
    int num_parts = 0;
    
    void Partition(int arr[],int i,int s,int N,int half_sum)
    {
        // base case
        if(i == N)
        {
            if(s == 0)
            {
                num_parts++;
            }
            return;
        }
        
        // cout << s << endl;
        
        if(s<=half_sum)
        {
            Partition(arr,i+1,s-arr[i],N,half_sum); //take it
            Partition(arr,i+1,s,N,half_sum); // don't take it
        }
    }
        
    int equalPartition(int N, int arr[])
    {
        int arr_sum = CompArraySum(arr,N);
        if(arr_sum % 2 == 0)
        {
            int half_sum = arr_sum/2;
            Partition(arr,0,half_sum,N,half_sum);
            if(num_parts >= 2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
