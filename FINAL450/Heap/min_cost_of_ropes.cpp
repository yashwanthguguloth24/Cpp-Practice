// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// using min heap, remove top 2 smallest elements add them and insert again until size of min heap is 1. 


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
        long long cost = 0;
        while(mnheap.size() >1)
        {
            long long top1 = mnheap.top();
            mnheap.pop();
            long long top2 = mnheap.top();
            mnheap.pop();
            
            long long res = top1+top2;
            // cout << res << endl;
            cost += res;
            mnheap.push(res);
        }
        return cost;
    }
};
