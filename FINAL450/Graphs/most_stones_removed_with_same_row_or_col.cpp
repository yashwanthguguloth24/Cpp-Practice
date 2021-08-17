// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// using UNIION FIND Algo with some variation

class Solution {
public:
    int find(int i,vector<int> &parent)
    {
        while(parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    
    void union_sets(int i,int j,vector<int>&parent,vector<int> &sz,vector<vector<int>>& stones)
    {
        int rooti = find(i,parent);
        int rootj = find(j,parent);
        
        if(rooti == rootj)
        {
            return ;
        }
        else
        {
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
            {
                parent[rootj] = rooti;
                sz[rooti]++;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n,0);
        vector<int> sz(n,1);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                union_sets(j,i,parent,sz,stones);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans += sz[i]-1;
        }
        return ans;
    }
};
