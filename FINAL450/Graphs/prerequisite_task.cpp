// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

// problem boils down to checking if cycle is present or not


class Solution {
public:
    bool flag = false;
	//Function to detect cycle in a directed graph.
	/*
	visited = 0 --> not visited
	        = 1 --> visited and in the current recursion stack
	        = 2 --> visited and not in current recursion stack
	*/
	
	
	void dfs(int v,vector<int>adj[],vector<int>&visited)
	{
	    visited[v] = 1;
	    for(int i = 0;i<adj[v].size();i++)
	    {   int u = adj[v][i];
	        if(visited[u] == 0)
	        {
	            dfs(u,adj,visited);
	        }
	        else if(visited[u] == 1)
	        {
	            flag = true;
	        }
	    }
	    visited[v] = 2;

	}
	
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int>visited(V,0);
	   	for(int i = 0;i<V;i++)
	   	{
	   	    if(visited[i] == 0)
	   	    {
	   	        dfs(i,adj,visited);
	   	    }

	   	}
	   	return flag;
	}
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(int i = 0;i<prerequisites.size();i++)
	    {
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    if(isCyclic(N,adj))
	    {
	        return false;
	    }
	    else
	    {
	        return true;
	    }
	}
};
