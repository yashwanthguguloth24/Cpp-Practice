// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// choosing min length ropes initially is the greedy choice

class myComparator
{
public:
    bool operator()(long long e1,long long e2)
    {
        return (e1 > e2);
    }
};


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,myComparator> mnheap;
        for(long long i = 0;i<n;i++)
        {
            mnheap.push(arr[i]);
        }
        long long ans = 0;    
        while(mnheap.size() != 1)
        {
            long long top1 = mnheap.top();
            mnheap.pop();
            long long top2 = mnheap.top();
            mnheap.pop();
            ans += top1+top2;
            mnheap.push(top1+top2);
        }
        return ans;
    }
};

