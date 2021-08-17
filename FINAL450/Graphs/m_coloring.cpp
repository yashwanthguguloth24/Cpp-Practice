// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

// using backtracking approach


bool flag = false;

bool isSafe(int v,int clr,int V,vector<int>&colors,bool graph[101][101])
{
    for(int j = 0;j<V;j++)
    {
        if(graph[v][j] == true)
        {
            if(colors[j] == clr)
            {
                return false;
            }
        }
    }
    return true;
}

void dfs_color(int v,int m,int V,vector<int>&colors,vector<bool>&visited,bool graph[101][101])
{
    // base case
    if(v == V)
    {
        for(int i = 0;i<V;i++)
        {
            if(colors[i] == -1)
            {
                return;
            }
        }
        flag = true;
        return;
    }
    
    
    
    
    // if(clr == 0)
    // {
    //     return;
    // }

    
    if(visited[v] == true)
    {
        return;
    }
    visited[v] = true;
    
    for(int c = 1;c<=m;c++)
    {
        if(isSafe(v,c,V,colors,graph))
        {
            colors[v] = c;
            dfs_color(v+1,m,V,colors,visited,graph);
            if(flag == true)
            {
                return;
            }
            colors[v] = -1;
        }
    }
    visited[v] = false;

}













bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<bool> visited(V,false);
    vector<int>colors(V,-1);
    dfs_color(0,m,V,colors,visited,graph);
    bool temp = flag;
    flag = false;
    return temp;
}
