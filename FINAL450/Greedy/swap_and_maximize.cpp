// https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1#

// The greedy choice is to have sequence like this : small large small large …

long long int maxSum(int arr[], int n)
{
    vector<long long int> a;
    sort(arr,arr+n);

    for(int i = 0;i<(n/2);i++)
    {
        a.push_back(arr[i]);
        a.push_back(arr[n-i-1]);
    }
    
    if(n%2 != 0)
    {
        a.push_back(arr[(n/2)]);
    }
    
    
    long long int ans = 0;
    for(int i = 0;i<n-1;i++)
    {
        ans += abs(a[i]-a[i+1]);
    }
    ans += abs(a[n-1]-a[0]);
    return ans;
}
