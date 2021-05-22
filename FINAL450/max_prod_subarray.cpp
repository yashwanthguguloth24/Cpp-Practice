// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#


// Approach : keep max_prod,min_prod because the values can be negative and update accordingly.

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long max_prod = arr[0];
	    long long min_prod = arr[0];
	    long long prod = arr[0];
	    for(int i = 1;i<n;i++)
	    {
	        if(arr[i]<0)
	        swap(max_prod,min_prod);
	        
	        max_prod = max((long long) arr[i],arr[i]*max_prod);
	        min_prod = min((long long) arr[i],arr[i]*min_prod);
	        if(prod<max_prod)
	        prod = max_prod;
	    }
	    return prod;
	}
};

