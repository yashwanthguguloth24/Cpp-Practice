//https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

// Using priority queue c++ stl for max heap

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> ans;
	    priority_queue<int> maxheap;
	    for(int i=0;i<n;i++)
	    {
	        maxheap.push(arr[i]);
	    }
	    while(k)
	    {
	        ans.push_back(maxheap.top());
	        maxheap.pop();
	        k--;
	    }
	    return ans;
	}

};
