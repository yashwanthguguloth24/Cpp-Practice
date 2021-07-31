// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#

// using 2 heaps 1.Max heap to store small elements 2.Min heap to store large elements and doing operations accordingly

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > large; //min heap
    // large will contain more elements
    void insertHeap(int &x)
    {
        if(small.size() == 0 && large.size() == 0)
        {
            large.push(x);
        }
        else
        {
            if(small.size() != 0  && x < small.top())
            {
                small.push(x);
            }
            else
            {
                large.push(x);
            }
            balanceHeaps();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int a = small.size();
        int b = large.size();
        if((a-b) > 1)
        {
            int top = small.top();
            small.pop();
            large.push(top);
        }
        else if((b-a) >1)
        {
            int top = large.top();
            large.pop();
            small.push(top);            
        }

    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans;
        if(small.size() == 0)
        {
            ans = large.top();
        }
        else if(small.size() == large.size())
        {
            ans = (small.top() + large.top())/2;
        }
        else if(small.size() > large.size())
        {
            ans = small.top();
        }
        else
        {
            ans = large.top();
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
