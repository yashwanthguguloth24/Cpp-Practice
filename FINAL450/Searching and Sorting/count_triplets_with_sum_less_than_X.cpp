// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1


// one foor loop and 2 pointers 


class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long cnt = 0;
	    sort(arr,arr+n);
	    for(int i = 0;i<=n-3;i++)
	    {
	        int low = i+1;
	        int high = n-1;
	        while(low < high)
	        {
	            int sm = arr[i]+arr[low]+arr[high];
	            if(sm >= sum)
	            {
	                high--;
	            }
	            else
	            {
	                cnt += (high-low);
	                low++;
	            }
	        }
	    }
	    return cnt;
	}
