// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int>&visited,stack<int> &stk,vector<int> adj[])
	{
	    if(visited[i]) return;
	    visited[i] = true;
	    for(auto j:adj[i])
	    {
	        if(!visited[j])
	        {
	            dfs(j,visited,stk,adj);
	        }
	    }
	    stk.push(i);
	}
	
	void dfsRev(int i,vector<int>&visited,vector<vector<int>>&rev)
	{
	    if(visited[i]) return;
	    visited[i] = true;
	    for(auto j:rev[i])
	    {
	        if(!visited[j])
	        {
	            dfsRev(j,visited,rev);
	        }
	    }
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> visited(V,false);
        stack<int> stk;
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,stk,adj);
            }
        }
        for(int i = 0;i<V;i++)
        {
            visited[i] = false;
        }
        
        
        vector<vector<int>> rev(V);
        for(int i = 0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                rev[j].push_back(i);
            }
        }
        
        int cc = 0;
        while(!stk.empty())
        {
            int tp = stk.top();
            stk.pop();
            if(visited[tp] == false)
            {
                cc++;
                dfsRev(tp,visited,rev);
            }
        }
        return cc;
        
    }
};
