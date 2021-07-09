// https://leetcode.com/problems/combination-sum/

// Using backtracking.


class Solution {
public:
    vector<vector<int>> ans;
    void CombSumBT(vector<int>& candidates, int target,int i,vector<int> v1)
    {
        // base case
        if(target < 0)
        {
            return ;
        }
        if(i >= candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(v1);
            }
            return ;
        }
        v1.push_back(candidates[i]);
        CombSumBT(candidates,target-candidates[i],i,v1);
        v1.pop_back();
        CombSumBT(candidates,target,i+1,v1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v1 ;
        CombSumBT(candidates,target,0,v1);
        return ans;
    }
};
