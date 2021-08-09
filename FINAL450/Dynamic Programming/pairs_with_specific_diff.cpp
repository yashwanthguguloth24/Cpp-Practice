// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

// sort the array,then dp[i] has 2 choices 1.dont take arr[i] 2.else check if diff of arr[i],arr[i-1] is K,if yes then include it.Max of these 2 gives us the answer.


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N);
        
        vector<int> dp(N);
        dp[0] = 0;
        if(arr[1]-arr[0] < K)
        {
            dp[1] = arr[0]+arr[1];
        }
        else
        {
            dp[1] = 0;
        }
        
        for(int i = 2;i<N;i++)
        {
            int a = dp[i-1];
            int b = -1;
            if(arr[i]-arr[i-1]<K)
            {
                b = arr[i]+arr[i-1]+dp[i-2];
            }
            dp[i] = max(a,b);

        }
        return dp[N-1];
    }
};
