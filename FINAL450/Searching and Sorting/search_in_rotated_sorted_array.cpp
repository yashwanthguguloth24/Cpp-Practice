// https://leetcode.com/problems/search-in-rotated-sorted-array/


// apply binary search for left of pivot and right of pivot seperately


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r1 = n-2;
        for(int i = 0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                r1 = i;
                break;
            }
        }
        int mid;
        int l1 = 0;
        int l2 = r1+1;
        int r2 = n-1;
        
        while(l1<=r1)
        {
            mid = (l1+r1)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                r1 = mid-1;
            }
            else
            {
                l1 = mid+1;
            }
        }
        while(l2<=r2)
        {
            mid = (l2+r2)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                r2 = mid-1;
            }
            else
            {
                l2 = mid+1;
            }
        }
        return -1;
    }
};
