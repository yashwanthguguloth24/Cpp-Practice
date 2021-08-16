// https://leetcode.com/problems/max-area-of-island/

// using BFS at land area or 1's and counting number of steps


class Solution {
public:
    vector<int> row_pos = {-1,0,1,0};
    vector<int> col_pos = {0,1,0,-1};
    
    bool isSafe(int row,int col,vector<vector<bool>> &visited,int N,int M)
    {
        if(row < 0 || col < 0 || row > N-1 || col > M-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    
    
    int bfs_area(int r,int c,vector<vector<bool>>&visited,vector<vector<int>>& grid)
    {
        int N = grid.size();
        int M = grid[0].size();
        int area = 0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{r,c},1});
        while(!q.empty())
        {
            pair<pair<int,int>,int> fe = q.front();
            q.pop();
            int row = fe.first.first;
            int col = fe.first.second;
            int stps = fe.second;
            if(visited[row][col] == true)
            {
                continue;
            }
            area++;
            visited[row][col] = true;
            int d = stps+1;
            for(int i = 0;i<4;i++)
            {
                if(isSafe(row+row_pos[i],col+col_pos[i],visited,N,M) && grid[row+row_pos[i]][col+col_pos[i]] == 1)
                {
                    q.push({{row+row_pos[i],col+col_pos[i]},d});
                    d++;
                }
            }
            
        }
        return area;
    }
    
    
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == false)
                {
                    int area = bfs_area(i,j,visited,grid);
                    max_area = max(area,max_area);
                }
                visited[i][j] = true;
            }
        }
        return max_area;
        
        
    }
};
