// https://www.hackerrank.com/challenges/journey-to-the-moon/problem


// Using both DSU method and DFS




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



// *********** USING DFS ***************

void dfs(int i,int &cntr,vector<vector<int>> &adj,vector<bool> &visited)
{
    // if(visited[i])
    // {
    //     return;
    // }
    cntr++;
    visited[i] = true;
    for(int j = 0;j<adj[i].size();j++)
    {
        if(visited[adj[i][j]]==false)
        {
            dfs(adj[i][j],cntr,adj,visited);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<bool> visited(n,false);
    vector<vector<int>> adj(n);
    for(auto ast:astronaut)
    {
        adj[ast[0]].push_back(ast[1]);
        adj[ast[1]].push_back(ast[0]);
    }
    vector<int> poss;
    for(int i = 0;i<n;i++)
    {
        if(visited[i] == false)
        {
            int cntr = 0;
            dfs(i,cntr,adj,visited);
            poss.push_back(cntr);
        }
    }

    

    int l = poss.size();

    // for(int i = 0;i<l;i++)
    // {
    //     cout<< poss[i] << " ";
    // }
    // cout << endl;
    // int ans = (l*(l-1))/2;
    // cout << ans << endl;
    // for(int i = 0;i<l;i++)
    // {
    //     int val = (poss[i]*(poss[i]-1))/2;
    //     cout << val << " ";
    //     ans = ans - val;
    // }
    // cout << endl;
    // int l = poss.size();
    // int ans = 0;
    long long int ans = (n*(n-1))/2;
    for(int i = 0;i<l;i++)
    {
        // for(int j = i+1;j<l;j++)
        // {
        //     ans = ans + poss[i]*poss[j];
        // }
        long long int val = (poss[i]*(poss[i]-1))/2;
        ans = ans - val;
    }
    // cout << ans << endl;
    return ans;
    

}
