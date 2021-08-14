// https://leetcode.com/problems/rotting-oranges/


// using BFS,intially store all the rotten mangoes in the queue and then continue bfs accordingly


class Solution {
public:
    bool isSafe(int row,int col,vector<vector<bool>> &visited,int N,int M)
    {
        if(row < 0 || col < 0 || row > N-1 || col > M-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        
        queue<pair<pair<int,int>,int>> q;
        
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j] = true;
                }
            }
        }
        
        vector<int> row_pos = {-1,0,1,0};
        vector<int> col_pos = {0,1,0,-1};
        
        int total_time = 0;
        
        while(!q.empty())
        {
            pair<pair<int,int>,int> front_ele = q.front();
            q.pop();
            int r = (front_ele.first).first;
            int c = (front_ele.first).second;
            
            total_time = front_ele.second;
            
            for(int i = 0;i<4;i++)
            {
                if(isSafe(r+row_pos[i],c+col_pos[i],visited,N,M) && grid[r+row_pos[i]][c+col_pos[i]] == 1)
                {
                    q.push(make_pair(make_pair(r+row_pos[i],c+col_pos[i]),total_time+1));
                    grid[r+row_pos[i]][c+col_pos[i]] = 2;
                    visited[r+row_pos[i]][c+col_pos[i]] = true;;
                        
                }
            }
            
        }
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        
        return total_time;
        
        
    }
};
