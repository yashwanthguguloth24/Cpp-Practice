class myComparator
{
public:
    bool operator()(pair<int,vector<int>> x,pair<int,vector<int>> y)
    {
        return (x.second[1] > y.second[1]);
    }
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        cin.tie(NULL);
        // priority_queue<ele, vector<ele>,myComparator> pq;
        map<int,int> mp;
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>,myComparator> pq;
        vector<bool> visited(n,false); 
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        pq.push({src,{k+1,0}});

        
        while(!pq.empty())
        {
            pair<int,vector<int>> top_ele = pq.top();
            pq.pop();
            int v = top_ele.first;
            int stps = top_ele.second[0];
            int cost = top_ele.second[1]; 
            
            if(v == dst)
            {
                return cost;
            }
            if(mp.find(v) != mp.end() && mp[v] > stps)
            {
                continue;
            }
            mp[v] = stps;
            
            if(!stps)
            {
                continue;
            }
            
            for(int i = 0;i<adj[v].size();i++)
            {
                pq.push({adj[v][i].first,{stps-1,cost+adj[v][i].second}});
            }
        }
        return -1;
    }
};
