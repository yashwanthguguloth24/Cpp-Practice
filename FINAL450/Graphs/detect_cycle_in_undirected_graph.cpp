// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

// using bfs and check for all nodes 


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool isCycleBFS(int x,int V,vector<bool> &visited,vector<int>adj[])
    {
	   	bool ans = false;
	   	queue<int>q;
	   //	vector<bool> visited(V,false);
	   	q.push(x);
	   	while(!q.empty())
	   	{
	   	    int front_ele = q.front();
	   	    q.pop();
	   	    if(visited[front_ele] == true)
	   	    {
	   	        ans = true;
	   	        break;
	   	    }
	   	    visited[front_ele] = true;
	   	    
	   	    for(int i = 0;i<adj[front_ele].size();i++)
	   	    {
	   	        if(visited[adj[front_ele][i]] == false)
	   	        {
	   	            q.push(adj[front_ele][i]);
	   	        }
	   	    }
	   	}
	   	return ans;
    }
    
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> visited(V,false);
	    for(int i = 0;i<V;i++)
	    {
	        if(visited[i] == false && isCycleBFS(i,V,visited,adj))
	        {
	            return true;
	        }
	    }
	    return false;

	}
};
