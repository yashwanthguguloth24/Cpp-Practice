// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Similar to Dijkstra, using PRIORITY QUEUE

class pr
{
    public:
    int curr;
    int par;
    int wt;
    pr(int a,int b,int c)
    {
        curr = a;
        par = b;
        wt = c;
    }
};


class Compare
{
    public:
	bool operator()(pr x,pr y)
	{
	    return (x.wt>y.wt);
	}
};

class Solution
{
	public:
	
// 	bool comp(pr x,pr y)
// 	{
// 	    return (x.wt>y.wt);
// 	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        vector<bool>visited(V,false);
        pr temp(0,-1,0);
        priority_queue<pr,vector<pr>,Compare> pq;
        pq.push(temp);
        while(!pq.empty())
        {
            pr tp = pq.top();
            pq.pop();
            if(visited[tp.curr])
            {
                continue;
            }
            visited[tp.curr] = true;
            if(tp.par != -1) 
            {
                ans += tp.wt;
            }
            for(int i = 0;i<adj[tp.curr].size();i++)
            {
                int u = adj[tp.curr][i][0];
                int w = adj[tp.curr][i][1];
                if(!visited[u])
                {
                    pq.push(pr(u,tp.curr,w));
                }
            }
        }
        return ans;
        
        
    }
};
