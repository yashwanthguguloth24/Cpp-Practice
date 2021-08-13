// https://onedrive.live.com/?authkey=%21AJrTq%5FU8BPKIWDk&cid=842AECBB531CCEA4&id=842AECBB531CCEA4%211179&parId=842AECBB531CCEA4%211164&o=OneUp


// created a graph with bfs and dfs traversals

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


template<class T>
class Graph
{
    public:
    map<T,list<pair<T,int>>> adjList;

    void addEdge(T u,T v,int dist,bool bidirec = 1)
    {
        adjList[u].push_back(make_pair(v,dist));

        if(bidirec)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    } 

    void printGraph()
    {
        for(auto x:adjList)
        {
            cout << x.first << ":  ";
            for(auto y:x.second)
            {
                cout << "( "<<y.first<<" , "<<y.second<<" ) ";
            }
            cout << endl;
        }
    }

    void BFS(T u)
    {
        map<T,bool> visited;
        queue<T> q;
        q.push(u);
        while(!q.empty())
        {
            T front_ele = q.front();
            q.pop();
            if(!visited[front_ele])
            {
                cout << front_ele << "->";
                visited[front_ele] = true;
            }

            for(auto a : adjList[front_ele])
            {
                if(!visited[a.first])
                {
                    q.push(a.first);
                }
            }
        }
    }


    void dfs_helper(T src,map<T,bool> &visited)
    {
        visited[src] = true;
        cout << src << " -> ";

        for(auto a:adjList[src])
        {
            if(!visited[a.first])
            {
                dfs_helper(a.first,visited);
            }
        }
    }


    void dfs(T src)
    {
        map<T,bool> visited;
        dfs_helper(src,visited);
    }

    


};




int main()
{
    Graph<char> g;
    g.addEdge('S','D',20);
    g.addEdge('S','B',5);
    g.addEdge('S','A',10);
    g.addEdge('B','C',7);
    g.addEdge('B','D',2);
    g.addEdge('A','C',2);
    g.addEdge('C','F',5);
    g.addEdge('C','E',1);
    g.addEdge('F','D',2);

    g.printGraph();

    g.BFS('S');
    cout << endl;
    g.dfs('S');
    return 0;
}
