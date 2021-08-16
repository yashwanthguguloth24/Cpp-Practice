// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

// using bfs and check for all nodes 

// **************BFS*****************************
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



//*****************MODIFIED DFS*********************
class Solution 
{
    public:
    bool flag = false;
    //Function to detect cycle in an undirected graph.
    void dfsCycle(int v,int parent,vector<bool>&visited,vector<int>adj[])
    {
        visited[v] = true;
        for(auto u:adj[v])
        {
            if(visited[u] == false)
            {
                dfsCycle(u,v,visited,adj);
            }
            else if(u != parent)
            {
                flag = true;
            }
        }
    }
    
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool>visited(V,false);
	    for(int i = 0;i<V;i++)
	    {
	        if(visited[i] == false)
	        {
	           dfsCycle(i,-1,visited,adj); 
	        }
	    }
	    return flag;
	}
};
