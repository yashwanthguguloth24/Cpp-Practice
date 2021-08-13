// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// using reursion


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs_helper(int x,vector<int>&ans,vector<int> &visited,vector<int> adj[])
	{
	    if(visited[x] == true)
	    {
	        return;
	    }
	    visited[x] = true;
	    ans.push_back(x);
	    for(int i = 0;i<adj[x].size();i++)
	    {
	        if(!visited[adj[x][i]])
	        {
	            dfs_helper(adj[x][i],ans,visited,adj);
	        }
	    }
	}
	
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    vector<int> visited(V,false);
	    
	    dfs_helper(0,ans,visited,adj);
	    return ans;
	}
};
