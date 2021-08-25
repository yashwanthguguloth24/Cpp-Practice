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

// ************** USING LEFTMAX AND RIGHT OF A INDEX ******************************
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int max_ind_left = 0;
        vector<int> max_left(n);
        for(int i = 0;i<n;i++)
        {
            // if(arr[max_ind_left] < arr[i])
            // {
            //     max_ind_left = i;
            // }
            max_left[i] = max_ind_left;
            if(arr[max_ind_left] < arr[i])
            {
                max_ind_left = i;
            }
        }
        int max_ind_right = n-1;
        vector<int> max_right(n);
        for(int i = n-1;i>=0;i--)
        {
            max_right[i] = max_ind_right;
            if(arr[max_ind_right] < arr[i])
            {
                max_ind_right = i;
            }
            // max_right[i] = max_ind_right;
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(min(arr[max_right[i]],arr[max_left[i]]) > arr[i])
            {
                ans += min(arr[max_right[i]],arr[max_left[i]])-arr[i];   
            }
        }
        return ans;
        
    }
};
