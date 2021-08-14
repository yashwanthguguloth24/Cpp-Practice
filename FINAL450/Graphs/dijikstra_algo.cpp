// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#


// use priority Queue correctly(default max heap, for min heap  in comparator do reverse(opposite of sorting)) , remaining part is direct implementation of algorithm


class myComparator
{
public:
    bool operator()(pair<int,int> x,pair<int,int> y)
    {
        return (x.second > y.second);
    }
};


class Solution
{
	public:
	
	static bool comparebyDist(pair<int,int> x,pair<int,int> y)
	{
	    return (x.second < y.second);
	}
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V);
        priority_queue<pair<int,int>, vector<pair<int,int>>,myComparator> pq;
        vector<bool> visited(V,false); 
        pq.push(make_pair(S,0));

        
        while(!pq.empty())
        {
            pair<int,int> top_ele = pq.top();
            pq.pop();
            if(visited[top_ele.first] == true)
            {
                continue;
            }
            visited[top_ele.first] = true;
            ans[top_ele.first] = top_ele.second;
            
            for(int i = 0;i<adj[top_ele.first].size();i++)
            {
                if(visited[adj[top_ele.first][i][0]] == false)
                {
                    pq.push(make_pair(adj[top_ele.first][i][0],adj[top_ele.first][i][1]+top_ele.second));
                }
            }
        }
        return ans;
    }
};
