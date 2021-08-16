// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

// using MODIFIED DFS


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
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
            // for(int j = 0;j<V;j++)
            // {
            //     cout << visited[j] << " ";
            // }
            // cout << endl;
	   	    if(visited[i] == 0)
	   	    {
	   	        dfs(i,adj,visited);
	   	    }
	   	    // if(visited[i] == 2)
	   	    // {
	   	    //     visited[i] = 0;
	   	    // }
	   	}
	   	return flag;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
