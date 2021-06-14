// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> stk;
        long long i = 0;
        long long maxArea = -1;
        while(i<n)
        {
            while(i<n && (stk.empty()==1 || arr[i] >= arr[stk.top()]))
            {
                stk.push(i);
                i += 1;
            }
            long long currArea = 0;
            while(stk.empty() == 0 && (i == n || arr[stk.top()]>arr[i]))
            {
                long long top = stk.top();
                stk.pop();
                if(stk.empty() == 1)
                {
                    currArea = arr[top]*i;
                }
                else
                {
                    currArea = arr[top]*(i-stk.top()-1);
                }
                maxArea = max(maxArea,currArea);
            }
            
        }
        return maxArea;
        
    }
};
