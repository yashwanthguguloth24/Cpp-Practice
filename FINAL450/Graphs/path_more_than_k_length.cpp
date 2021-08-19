// https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/

// using backtracking approach

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool flag = false;

// backtracking
void dfs(int i,int k,int cnt,vector<vector<int>>adj[],vector<bool>&visited)
{
    if(visited[i]) return;
    if(cnt > k)
    {
        flag = true;
        cout << "sum is " << cnt << endl;
        return;
    }

    visited[i] = true;
    for(int j = 0;j<adj[i].size();j++)
    {
        int u = adj[i][j][0];
        int w = adj[i][j][1];
        if(visited[u] == false)
        {
            dfs(u,k,cnt+w,adj,visited);
            if(flag)
            {
                return;
            }
        }
    }
    visited[i] = false;

}



int main()
{
    int N;
    cin >> N;
    int E;
    cin >> E;
    vector<vector<int>> adj[N];
    vector<bool>visited(N,false);
    while(E--)
    {
        int a,b,c;
        cin >>a;
        cin >>b;
        cin >>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int src,k;
    cin >> src;
    cin >> k;
    dfs(src,k,0,adj,visited);
    cout << flag << endl;
    return 0;
}
