// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

// Reference : https://www.youtube.com/watch?v=4691X1MAmIU

// Expand and shrink the window while moving right

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int i = 0;
        int j = 0;
        int s = 0;
        int mi = INT_MAX;
        while(j<n)
        {
            while(j<n && s<=x)
            {
                s += arr[j];
                j++;
            }
            //j = j-1;
            while(i< n && s>x)
            {
                mi = min(mi,j-i);
                s -= arr[i];
                i++;
            }
        }
        return mi;
        
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}
