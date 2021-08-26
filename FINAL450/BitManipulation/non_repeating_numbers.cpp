// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

// using smart logic of xor


class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size(); 
        // Code here.
        int val = nums[0];
        for(int i = 1;i<n;i++)
        {
            val = val^nums[i];
        }
        int num1 = 0;
        int num2 = 0;
        int rmsb = val & (-val);
        for(int i = 0;i<n;i++)
        {
            if(nums[i]&rmsb)
            {
                num1 = num1^nums[i];
            }
            else
            {
                num2 = num2^nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
