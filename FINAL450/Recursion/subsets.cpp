// https://leetcode.com/problems/subsets/

/*
Using backtracking with the following steps
1.Make decision - for ith index take element in v2,donot take element v3
2.Recurr - recur using v2 and v3
3.Undo - property is not destroyed to undo
*/

class Solution {
public:
    vector<vector<int>> ans;
    void subsetsBacktrack(vector<int>& nums,int i,vector<int>v1)
    {
        if(i>=nums.size())
        {
            ans.push_back(v1);
            return ;
        }
        vector<int> v2 = v1;// to take
        vector<int> v3 = v1;// to not take
        v2.push_back(nums[i]); //make decision
        subsetsBacktrack(nums,i+1,v2); //recur
        subsetsBacktrack(nums,i+1,v3); // recur
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v1;
        subsetsBacktrack(nums,0,v1);
        return ans;
    }
};
