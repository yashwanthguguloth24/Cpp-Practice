// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// USING DIGIKSTRA ALGO and taking care of number of stops


// class ele
// {
//     public:
//     int val;
//     int stops;
//     int price;
//     ele(int a,int b,int c)
//     {
//         val = a;
//         stops = b;
//         price = c;
//     }
// };


// class myComparator
// {
// public:
//     bool operator()(ele x,ele y)
//     {
//         return (x.price > y.price);
//     }
// };

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
//             if(visited[v] == true)
//             {
//                 continue;
//             }
//             visited[v] = true;
            
            if(v == dst)
            {
                return cost;
            }
            
            if(!stps)
            {
                continue;
            }
            
            for(int i = 0;i<adj[v].size();i++)
            {
                // if(visited[adj[v][i].first] == false)
                // {
                    pq.push({adj[v][i].first,{stps-1,cost+adj[v][i].second}});
                // }
            }
        }
        return -1;
    }
};
