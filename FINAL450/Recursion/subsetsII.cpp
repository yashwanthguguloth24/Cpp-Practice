// https://leetcode.com/problems/subsets-ii/

/*
Backtracking
1.Take decision - add element to subset
2.Recur - backtrack for next index
3.Undo - remove the added element

*/

class Solution {
public:
    vector<vector<int>> res;
    void get(vector<int> &nums , int i, vector<int> v1)
    {
        res.push_back(v1);
        if(i  ==  nums.size())
            return;
        // res.push_back(v1);
        int j;
        for(j = i ; j < nums.size() ; j++)
        {
        //to avoid duplicate element
            if(j != i and nums[j] == nums[j-1])continue;
            v1.push_back(nums[j]);
            get(nums, j+1 ,v1);
            v1.pop_back();
        }
    }
    
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v1;
        sort(nums.begin(),nums.end());
        get(nums,0,v1);
        return res;
    }
};
