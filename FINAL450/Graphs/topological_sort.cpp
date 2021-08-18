// https://practice.geeksforgeeks.org/problems/topological-sort/1



class Solution
{
	public:
	
	void topSort_rec(int v,vector<bool> &visited,vector<int> adj[],stack<int> &stk)
	{
	    visited[v] = true;
	    for(int i = 0;i<adj[v].size();i++)
	    {
	        if(visited[adj[v][i]] == false)
	        {
	            topSort_rec(adj[v][i],visited,adj,stk);
	        }
	    }
	    stk.push(v);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    stack<int> stk;
	    for(int i = 0;i<V;i++)
	    {
	        if(visited[i] == false)
	        {
	            topSort_rec(i,visited,adj,stk);
	        }
	    }
	    vector<int> ans;
	    while(stk.size() != 0)
	    {
	       // cout << stk.top() << endl;
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    return ans;

	}
};
