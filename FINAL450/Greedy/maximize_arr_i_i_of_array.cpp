// https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1#

// sorting is the greedy choice

class Solution{
    public:
    int Maximize(int a[],int n)
    {
        int M = 1000000007;
        sort(a,a+n);
        long long ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans = (ans+((long long)a[i]*i)%M)%M;
        }
        return (int)ans;
    }
};
