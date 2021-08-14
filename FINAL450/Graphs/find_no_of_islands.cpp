// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#


// using DFS traversal,similar to connected components

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> row_pos = {-1,-1,0,1,1,1,0,-1};
    vector<int> col_pos = {0,1,1,1,0,-1,-1,-1};
    bool isSafe(int row,int col,vector<vector<bool>> &visited,int N,int M)
    {
        if(row < 0 || col < 0 || row > N-1 || col > M-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    void dfs(int r,int c,vector<vector<bool>> &visited,vector<vector<char>>& grid,int N,int M)
    {
        visited[r][c] = true;
        for(int i = 0;i<8;i++)
        {
            if(isSafe(r+row_pos[i],c+col_pos[i],visited,N,M) && grid[r+row_pos[i]][c+col_pos[i]] == '1')
            {
                dfs(r+row_pos[i],c+col_pos[i],visited,grid,N,M);
            }
        }
    }
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        int num_islands = 0;
        
        // vector<int> row_pos = {-1,-1,0,1,1,1,0,-1};
        // vector<int> col_pos = {0,1,1,1,0,-1,-1,-1};
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(visited[i][j] == false && grid[i][j] == '1')
                {
                    num_islands++;
                    dfs(i,j,visited,grid,N,M);
                }
            }
        }
        return num_islands;
        
        
        
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}
