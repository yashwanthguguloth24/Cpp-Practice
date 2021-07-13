// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

// reversing the array and finding greater on left and then reversing the answer

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        reverse(arr.begin(),arr.end());
        vector<long long> ans;
        stack<long long> stk;
        for(long long i = 0;i<arr.size();i++)
        {
            if(stk.size() == 0)
            {
                ans.push_back(-1);
                stk.push(arr[i]);
            }
            else if(arr[i] > stk.top())
            {
                while(stk.size() != 0 && stk.top()<arr[i])
                {
                    stk.pop();
                }
                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top());
                }
                stk.push(arr[i]);
            }
            else
            {
                ans.push_back(stk.top());
                stk.push(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
