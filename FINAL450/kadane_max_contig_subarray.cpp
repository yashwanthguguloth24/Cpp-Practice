// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int max_sum = -10000001; // since it is the minimum for given constraints
        int curr_sum = 0;
        for(int i = 0;i<n;i++)
        {
            curr_sum = curr_sum + arr[i];
            max_sum = max(curr_sum,max_sum);
            if (curr_sum < 0)
            {
                curr_sum = 0;
            }
        }
        return max_sum;
        
    }
};



