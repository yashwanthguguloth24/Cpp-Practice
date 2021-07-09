// https://leetcode.com/problems/permutations/

/*
Using backtracking with the following steps 
1.Make decision - swap numbers
2.Recurr - increment i, and recurr
3.Undo - again swap numbers

*/

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
        for(int j = i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permuteBacktrack(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permuteBacktrack(nums,0);
        return ans;
    }
};
