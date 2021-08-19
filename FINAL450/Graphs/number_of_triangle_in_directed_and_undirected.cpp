// https://www.geeksforgeeks.org/number-of-triangles-in-directed-and-undirected-graphs/

// for a triangle adj[i][j]=adj[j][k]=adj[k][i]=1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 4

int NumTriangles(int graph[V][V],bool isDirected)
{
    int cnt = 0;
    for(int i = 0;i<V;i++)
    {
        for(int j = 0;j<V;j++)
        {
            for(int k = 0;k<V;k++)
            {
                if(graph[i][j] && graph[j][k] && graph[k][i])
                {
                    cnt++;
                }
            }
        }
    }
    if(isDirected)
    {
        return (cnt/3);
    }
    else
    {
        return (cnt/6);
    }
}



int main()
{
    int graph[][V] = { {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };
 
    // Create adjacency matrix
    // of a directed graph
    int digraph[][V] = { {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                       };
 
    cout << "The Number of triangles in undirected graph : "
         << NumTriangles(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "
         << NumTriangles(digraph, true);
    return 0;
}
