// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Kadane's algo  https://www.youtube.com/watch?v=VMtyGnNcdPw


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int max_sum = arr[0];
        int curr_sum = arr[0];
        for(int i = 1;i<n;i++)
        {
            if(curr_sum >= 0)
            {
                curr_sum += arr[i];
            }
            else
            {
                curr_sum = arr[i];
            }
            
            max_sum = max(max_sum,curr_sum);
        }
        return max_sum;
        
    }
};
