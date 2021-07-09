// https://leetcode.com/problems/combination-sum-ii/


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


        if(target == 0)
        {
            ans.push_back(v1);
            return;
        }


        int j = i;
        for(j = i;j<candidates.size();j++)
        {
            if(i != j && candidates[j-1] == candidates[j])
            {
                continue;
            }
            v1.push_back(candidates[j]);
            CombSumBT(candidates,target-candidates[j],j+1,v1);
            v1.pop_back();
        }
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v1;
        sort(candidates.begin(),candidates.end());
        CombSumBT(candidates,target,0,v1);
        return ans;
    }
};
