// https://www.geeksforgeeks.org/bridge-in-a-graph/

// https://www.youtube.com/watch?v=Rhxs4k6DyMM&t=779s

// Tricky concept using TARJAN'S ALGO


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cntr = 0;

void dfs(int i,int V,vector<int>&low,vector<int>&disc,vector<int>&parent,vector<bool>&visited,vector<vector<int>> &adj)
{
    static int t = 0;
    visited[i] = true;
    disc[i] = low[i] = ++t;
    for(int j = 0;j<adj[i].size();j++)
    {
        int v = adj[i][j];
        if(visited[v] == false)
        {
            parent[v] = i;
            dfs(v,V,low,disc,parent,visited,adj);
            low[i] = min(low[i],low[v]);

            if(low[v] > disc[i])
            {
                cntr++;
                cout << i << " " << v << endl;
            }
        }
        else if(v != parent[i])
        {
            low[i] = min(low[i],disc[v]);
        }
    }

}

int NumBridges(int V,vector<vector<int>> &adj)
{
    vector<int>low(V,-1);
    vector<int>disc(V,-1);
    vector<int>parent(V,-1);
    vector<bool>visited(V,false);
    for(int i = 0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,V,low,disc,parent,visited,adj);
        }
    }

    return cntr;


}


int main()
{
    int V;
    cin >> V;
    vector<vector<int>> adj(V);
    int e;
    cin >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cout << "*****************" << endl;

    cout << NumBridges(V,adj) << endl;
    cout << "*****************" << endl;
    return 0;
}



