// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// Using BFS initially filling colours with 1 and iterating


class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<bool> visited(V,false);
	    vector<int> colors(V,1);
	    
	    int maxColors = 1;
	    for(int v = 0;v<V;v++)
	    {
	        if(visited[v])
	        {
	            continue;
	        }
	        visited[v] = true;
	        queue<int> q;
	        q.push(v);
	        
	        while(!q.empty())
	        {
	            int tp = q.front();
	            q.pop();
	            for(int i = 0;i<adj[tp].size();i++)
	            {
	                int u = adj[tp][i];
	                if(colors[u] == colors[tp])
	                {
	                    colors[u]++;
	                }
	                maxColors = max(maxColors,max(colors[u],colors[tp]));
	                if(maxColors>2)
	                {
	                    return false;
	                }
	                if(visited[u] == false)
	                {
	                    q.push(u);
	                    visited[u] = true;
	                }
	            }
	        }
	        
	        
	    }
	    return true;
	    
	    
	    
	}

};
