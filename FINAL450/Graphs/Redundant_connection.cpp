// https://leetcode.com/problems/redundant-connection/

// Using UNION FIND Algo// Also tried using DFS to find cycle , A issue is there finding the answer that's it


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
    
    bool union_sets(int i,int j,vector<int>&parent)
    {
        int rooti = find(i,parent);
        int rootj = find(j,parent);
        
        if(rooti == rootj)
        {
            return true;
        }
        else
        {
            parent[rootj] = rooti;
            return false;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
        }
        
        vector<int> poss_pair;
        for(auto e:edges)
        {
            bool b = union_sets(e[0],e[1],parent);
            if(b)
            {
                poss_pair = e;
            }
        }
        return poss_pair;
        
    }
};
