// https://practice.geeksforgeeks.org/contest/flipkart-round-1/problems#

// https://discuss.codechef.com/t/need-help-in-a-problem/77896/2



class Solution
{
public:

    int count(int M,int teams[],int val)
    {
        int cnt = 0;
        for(int i = 0;i<M;i++)
        {
            cnt += (teams[i]%val == 0)?((teams[i]/val)-1):(teams[i]/val);
        }
        return cnt;
    }
    
    int micsandjury(int N, int M,int teams[])
    {
        int max_val = INT_MIN;
        for(int i = 0;i<M;i++)
        {
            max_val = max(max_val,teams[i]);
        }
        int l = 1;
        int r = max_val;
        int ans = 0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(count(M,teams,mid) <= N-M)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};
