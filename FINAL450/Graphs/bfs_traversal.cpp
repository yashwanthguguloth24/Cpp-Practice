// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// traversal using queue

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    vector<bool> visited(V,false);
	    queue<int> q;
	    q.push(0);
	    visited[0] = true;
	    while(!q.empty())
	    {
	        int front_ele = q.front();
            q.pop();
            if(visited[front_ele])
            {
                continue;
            }
            // if(!visited[front_ele])
            // {
            //     // cout << front_ele << "->";
                visited[front_ele] = true;
                ans.push_back(front_ele);
            // }
            
            for(int i = 0;i<adj[front_ele].size();i++)
            {
                if(!visited[adj[front_ele][i]])
                {
                    q.push(adj[front_ele][i]);
                    // visited[adj[front_ele][i]] = true;
                }
            }            
	    }
	    return ans;
	    
	}
};
