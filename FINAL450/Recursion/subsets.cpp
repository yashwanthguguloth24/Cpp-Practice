// https://leetcode.com/problems/subsets/

/*
Using recursion to take or not take.
*/

class Solution {
public:
    vector<vector<int>> ans;
    void subsetsRec(vector<int>& nums,int i,vector<int>v1)
    {
        if(i>=nums.size())
        {
            ans.push_back(v1);
            return ;
        }
        vector<int> v2 = v1;// to take
        vector<int> v3 = v1;// to not take
        v2.push_back(nums[i]);
        subsetsRec(nums,i+1,v2); //recur
        subsetsRec(nums,i+1,v3); // recur
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v1;
        subsetsRec(nums,0,v1);
        return ans;
    }
};
