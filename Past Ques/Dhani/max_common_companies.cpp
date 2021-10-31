#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> arr)
{
    for(int i = 0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



void dfs(int i,int n,int wt,vector<vector<pair<int,int>>> adj,vector<bool> &visited,vector<int> &ccs)
{
    if(visited[i] == true) return;

    ccs.push_back(i);
    visited[i] = true;
    for(int j = 0;j<adj[i].size();j++)
    {
        pair<int,int> u = adj[i][j];
        if(u.second == wt)
        {
            dfs(u.first,n,wt,adj,visited,ccs);
        }
    }

}

bool sortbysec(int a,int b)
{
    return (a>b);
}

int main()
{
    int friends_nodes = 10;
    vector<int> friends_from = {1,7,5,10,6,2};
    vector<int> friends_to = {2,3,6,8,9,3};
    vector<int> friends_weight = {51,51,51,51,51,51};
    int n = friends_nodes;
    vector<vector<pair<int,int>>> adj(n+1);
    set<int> diff_comps;
    for(int i = 0;i<friends_from.size();i++)
    {
        adj[friends_from[i]].push_back({friends_to[i],friends_weight[i]});
        adj[friends_to[i]].push_back({friends_from[i],friends_weight[i]});
        diff_comps.insert(friends_weight[i]);
    }
    
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<adj[i].size();j++)
        {
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" << " ";
        }
        cout << endl;
    }


    int ans = INT_MIN;
    int grp_size = 0;
    for(auto x:diff_comps)
    {
        vector<bool> visited(n+1,false);
        for(int i = 1;i<=n;i++)
        {
            vector<int> ccs;
            dfs(i,n,x,adj,visited,ccs);
            printVec(ccs);
            cout << "@" << x << endl;
            if(ccs.size() > 1)
            {
                sort(ccs.begin(),ccs.end(),sortbysec);
                if(ccs.size() >= grp_size)
                {
                    ans = max(ans,ccs[0]*ccs[1]);
                    grp_size = ccs.size();
                }
                
            }
        }
    }
    cout << ans << endl;
    return 0;
}
