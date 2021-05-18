// https://leetcode.com/problems/next-permutation/

// Approach:
// Iterating from end to find a decreasing element,swapping it with the next largest element of the decreasing element from the right increasing sequence.
// Then reverse the vector of right increasing sequence
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i>0 && nums[i]<=nums[i-1])
        {
            i--;
        }
        if(i == 0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            int dec_ind = i-1;
            int dec_ele = nums[dec_ind];
            int to_swap = nums.size()-1;
            for(int i = dec_ind+1;i<nums.size()-1;i++)
            {
                if(nums[i+1]<=dec_ele && nums[i]>dec_ele)
                {
                    to_swap = i;
                    break;
                }
            }
            swap(nums[dec_ind],nums[to_swap]);
            reverse(nums.begin()+dec_ind+1,nums.end());
        }
        
    }
};
