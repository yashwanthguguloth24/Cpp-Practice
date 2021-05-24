// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

// sort the array first, then run a for loop to check minimum of all (max-min) difference in m element window.

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    long long ans = 1000000;
    sort(a.begin(),a.end());
    //ans = a[m-1]-a[0];
    
    //base case
    if(m == n)
    {
        ans = a[m-1]-a[0];
        return ans;
    }
    for(long long i = 0;i<n-m+1;i++)
    {
        ans = min(ans,a[i+m-1]-a[i]);
    }
    return ans;
    }   
};
