// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void topSort(int i,int k,stack<pair<int,int>> &stk,vector<bool>&visited,vector<vector<int>> &adj)
{
    if(visited[i]) return;
    // k++;
    // int a = k;
    // cout << a<<endl;
    visited[i] = true;
    for(int j = 0;j<adj[i].size();j++)
    {
        int u = adj[i][j];
        if(!visited[u])
        {
            topSort(u,k+1,stk,visited,adj);
        }
    }
    stk.push(make_pair(i,k));
}






int main()
{
    int n = 10;
    vector<vector<int>> edges = {{1, 3},{1, 4},{1, 5},{2, 3},{2, 8},{2, 9},{3, 6},{4, 6},{4, 8},{5, 8},{6, 7},{7, 8},{8, 10}};
    vector<vector<int>> adj(n);
    for(auto e:edges)
    {
        adj[e[0]-1].push_back(e[1]-1);
    }
    vector<bool>visited(n,false);
    stack<pair<int,int>> stk;
    int k = 1;
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
        {
            cout << "called" << " "<< i<< endl;
            for(int j = 0;j<n;j++)
            {
                cout << visited[j] << " ";
            }
            cout << endl;
            topSort(i,k,stk,visited,adj);
        }
    }

    while(!stk.empty())
    {
        cout << stk.top().second << " ";
        stk.pop();
    }

    return 0;
}
