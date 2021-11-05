#include<bits/stdc++.h>
using namespace std;

int extra(vector<vector<int>> adj,int a,int b,int c)
{
    int cnt = 0;
    for(int i = 0;i<adj[a].size();i++)
    {
        if(adj[a][i] != b && adj[a][i] != c)
        {
            cnt++;
        }
    }
    return cnt;
}

bool find(vector<vector<int>> adj,int a,int b)
{
    for(int i = 0;i<adj[a].size();i++)
    {
        if(adj[a][i] == b) return true;
    }
    return false;
}

int main()
{
    int friends_nodes = 5;
    int friends_edges = 6;
    vector<int> friends_from = {1,1,2,2,3,4};
    vector<int> friends_to = {2,3,3,4,4,5};
    vector<vector<int>> adj(friends_nodes);
    for(int i = 0;i<friends_edges;i++)
    {
        adj[friends_from[i]-1].push_back(friends_to[i]-1);
        adj[friends_to[i]-1].push_back(friends_from[i]-1);
    }
    int ans = INT_MAX;
    for(int i = 0;i<friends_nodes;i++)
    {
        if(adj[i].size() > 1)
        {
            for(int j = 0;j<adj[i].size();j++)
            {
                for(int k = j+1;k<adj[i].size();k++)
                {
                    if(find(adj,adj[i][j],adj[i][k]))
                    {
                        int temp = extra(adj,i,adj[i][j],adj[i][k])+extra(adj,adj[i][j],i,adj[i][k])+extra(adj,adj[i][k],i,adj[i][j]);
                        ans = min(ans,temp);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
