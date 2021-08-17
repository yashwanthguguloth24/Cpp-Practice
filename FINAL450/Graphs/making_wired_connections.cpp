// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// The problem simplifies to finding number of CONNECTED Components

class Solution {
public:
    void dfs(int i,vector<bool>&visited,vector<vector<int>>&adj)
    {
        if(visited[i] == true)
        {
            return;
        }
        visited[i] = true;
        for(int j = 0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]] == false)
            {
                dfs(adj[i][j],visited,adj);
            }
        }
    }
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
        {
            return -1;
        }
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(auto con:connections)
        {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        int cc = 0;
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == false)
            {
                dfs(i,visited,adj);
                cc++;
            }
        }
        return cc-1;
    }
};
