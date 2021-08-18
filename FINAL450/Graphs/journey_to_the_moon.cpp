// https://www.hackerrank.com/challenges/journey-to-the-moon/problem






// **************** DISJOINT SET UNION  *************************

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
int journeyToMoon(int n, vector<vector<int>> astronaut) {
        vector<int> parent(n,0);
        vector<int> sz(n,1);
        vector<bool>visited(n,false);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        for(auto ast:astronaut)
        {
            union_sets(ast[0],ast[1],parent,sz);
        }
        map<int,int> vals;
        for(int i = 0;i<n;i++)
        {
            vals[find(i,parent)]++;
        }
        
        vector<int> combs;
        for(int i = 0;i<n;i++)
        {
            if(vals[i] != 0)
            {
                combs.push_back(vals[i]);
            }
        }
        int ans = 0;
        for(int i = 0;i<combs.size()-1;i++)
        {
            for(int j = i+1;j<combs.size();j++)
            {
                ans += combs[i]*combs[j];
            }
        }
        return ans;

}
