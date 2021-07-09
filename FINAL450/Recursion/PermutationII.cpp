// https://leetcode.com/problems/permutations-ii/

//same as permutation but using set to check duplicate values

class Solution {
public:
    vector<vector<int>> ans;
    
    void Swap(int &a,int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void permuteBacktrack(vector<int>& nums,int i)
    {
        if(i>=nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        set<int> s1;
        s1.insert(nums[i]);
        for(int j = i;j<nums.size();j++)
        {
            if(i != j && s1.find(nums[j]) != s1.end())
            {
                continue;
            }
            s1.insert(nums[j]);
            swap(nums[i],nums[j]);
            permuteBacktrack(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permuteBacktrack(nums,0);
        return ans;
    }
};
