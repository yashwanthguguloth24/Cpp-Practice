// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

// Sort is greedy choice and iterate the array 

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        long long ans = INT_MAX;
        sort(a.begin(),a.end());
        long long i = 0;
        long long j = m-1;
        while(j<n)
        {
            ans = min(ans,a[j]-a[i]);
            i++;
            j++;
        }
        return ans;
    
    }   
};
