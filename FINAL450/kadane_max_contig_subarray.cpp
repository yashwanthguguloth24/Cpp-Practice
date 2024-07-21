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


// better approach

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long max_sum = -10000001;
        long long cum_sum = 0;
        long long curr_sum = 0;
        for(int i = 0;i<arr.size();i++)
        {
            cum_sum += arr[i];
            curr_sum = arr[i];
            if(curr_sum > cum_sum)
            {
                cum_sum = curr_sum;
            }
            max_sum = max(max_sum,cum_sum);
        }
        return max_sum;
        
    }
};
