// https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#

// Deriving insights from negative integer count and manipulating it accordingly


class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        if(n == 1)
        {
            if(a[0] >0)
            {
                return a[0]; 
            }
            else if(a[0] < 0 && k > 0)
            {
                return -a[0];
            }
        }
        int neg_cnt = 0;
        sort(a,a+n);
        for(int i = 0;i<n;i++)
        {
            if(a[i] < 0)
            {
                neg_cnt++;
            }
        }
        
        if(neg_cnt >= k)
        {
            for(int i = 0;i<k;i++)
            {
                a[i] = -a[i];
            }
        }
        else
        {
            for(int i = 0;i<n;i++)
            {
                if(a[i] < 0)
                {
                   a[i] = -a[i]; 
                }
            }
            sort(a,a+n);
            if((k-neg_cnt)%2 != 0)
            {
                a[0] = -a[0];
            }
        }
        
        long long int s = 0;
        for(int i = 0;i<n;i++)
        {
            s += a[i];
        }
        return s;
        
        
    }
};
