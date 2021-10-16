// https://practice.geeksforgeeks.org/problems/max-value-after-m-range-operation4300/1#

class Solution{


	public:
	int findMax(int n, int m, int a[], int b[], int k[])
	{
	    // Your code goes here
	    vector<int> arr(n,0);
	    for(int i = 0;i<m;i++)
	    {
	        arr[b[i]] += k[i];
	        if(a[i] > 0)
	        {
	            arr[a[i]-1] -= k[i];
	        }
	    }
	    
	    int sm = 0;
	    int ans = -1;
	    for(int i = n-1;i>=0;i--)
	    {
	        sm += arr[i];
	        arr[i] = sm;
	        ans = max(ans,arr[i]);
	    }
	    return ans;
	}

};
