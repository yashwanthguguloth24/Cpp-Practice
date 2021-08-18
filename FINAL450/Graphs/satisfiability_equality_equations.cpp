// https://leetcode.com/problems/satisfiability-of-equality-equations/

// using UNION FIND Algo with sizes

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
    
    void union_sets(int i,int j,vector<int>&parent,vector<int>&sz)
    {
        int rooti = find(i,parent);
        int rootj = find(j,parent);
        
        if(rooti == rootj)
        {
            return;
        }
        else
        {
            if(sz[rooti]>=sz[rootj])
            {
                parent[rootj] = rooti;
                sz[rooti] += sz[rootj];
            }
            else
            {
                parent[rooti] = rootj;
                sz[rootj] += sz[rooti];
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        vector<int> parent(n,0);
        vector<int> sz(n,1);
        vector<bool>visited(n,false);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        
        for(auto eq:equations)
        {
            if(eq[1] == '=')
            {
                union_sets((eq[0]-97),(eq[3]-97),parent,sz);
                visited[eq[0]-97] = true;
                visited[eq[3]-97] = true;
            }
        }
        
        
        for(auto eq:equations)
        {
            if(eq[1] == '!')
            {
                if(eq[0] == eq[3])
                {
                    return false;
                }
                else if((visited[eq[0]-97] == true && visited[eq[3]-97] == true) && (find(eq[0]-97,parent) == find(eq[3]-97,parent)))
                {
                    return false;
                }
            }            
        }
        return true;
        
        
    }
};
