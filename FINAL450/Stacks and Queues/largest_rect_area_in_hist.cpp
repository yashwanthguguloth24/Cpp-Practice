// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long MaxArea = -1;
        stack<long long > stk;
        for(int i = 0;i<n;i++)
        {
            if(stk.size() == 0 || arr[i] >= arr[stk.top()])
            {
                stk.push(i);
            }
            else if(arr[i] < arr[stk.top()])
            {
                long long currArea = 0;
                while(stk.size() != 0 && arr[i] < arr[stk.top()])
                {
                    int temp = stk.top();
                    stk.pop();
                    if(stk.size() == 0)
                    {
                        currArea = arr[temp]*i;
                    }
                    else
                    {
                        currArea = arr[temp]*(i-stk.top()-1);
                    }
                    MaxArea = max(MaxArea,currArea);
                }
                stk.push(i);
            }
        }
        // if elements are left stack then this will empty it.
        int i = n;
        while(stk.size() != 0)
        {
            long long currArea = 0;
            int temp = stk.top();
            stk.pop();
            if(stk.size() == 0)
            {
                currArea = arr[temp]*i;
            }
            else
            {
                currArea = arr[temp]*(i-stk.top()-1);
            }
            MaxArea = max(MaxArea,currArea);
        }
        return MaxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends


//*************************************************************
// Using next smaller element on right and next smaller on left

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        //smallest element on right
        vector<long long > ser(n);
        stack<long long > s1;
        for(long long i = n-1;i>=0;i--)
        {
            if(s1.size() == 0)
            {
                ser[i] = n;
                s1.push(i);
            }
            else
            {
                while(s1.size() != 0 && arr[i] <= arr[s1.top()])
                {
                    s1.pop();
                }
                if(s1.size() == 0)
                {
                    ser[i] = n;
                }
                else
                {
                    ser[i] = s1.top();
                }
                s1.push(i);
            }
        }
        
        while(s1.size() != 0) s1.pop(); 
        
        // smallest element on left
        vector<long long> sel(n);
        for(long long i = 0;i<n;i++)
        {
            if(s1.size() == 0)
            {
                sel[i] = -1;
                s1.push(i);
            }
            else
            {
                while(s1.size() != 0 && arr[i] <= arr[s1.top()])
                {
                    s1.pop();
                }
                if(s1.size() == 0)
                {
                    sel[i] = -1;
                }
                else
                {
                    sel[i] = s1.top();
                }
                s1.push(i);
            }
        }
        long long ans = 0;
        for(int i = 0;i<n;i++)
        {
            // cout << ser[i] << " " << sel[i] << endl;
            ans = max(ans,(arr[i]*(ser[i]-sel[i]-1)));
        }
        return ans;
    }
};




