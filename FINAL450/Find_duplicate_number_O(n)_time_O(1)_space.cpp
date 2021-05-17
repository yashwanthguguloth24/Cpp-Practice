// https://leetcode.com/problems/find-the-duplicate-number/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            nums[nums[i]%n] = nums[nums[i]%n] + n;
        }
        int actual = 0;
        for(int i = 0;i<n;i++)
        {
            actual = (nums[i])%n;
            if((nums[i]-actual)/n > 1)
            {
                return i;
            }
        }
        return -1;
    }
};
