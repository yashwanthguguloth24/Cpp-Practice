// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

// Smartly using left and right pointers with respect to rightMax and leftMax.

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int l = 0;
        int r = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while(l<r)
        {
            if(arr[l] < arr[r])
            {
                if(arr[l]>=leftMax)
                leftMax = arr[l];
                else
                {
                    ans += leftMax-arr[l];
                }
                l++;
            }
            else
            {
                if(arr[r]>=rightMax)
                rightMax = arr[r];
                else
                {
                    ans += rightMax-arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};

