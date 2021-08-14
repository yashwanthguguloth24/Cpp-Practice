// https://leetcode.com/problems/shortest-path-in-binary-matrix/

// bfs traversal by appending only 0's


class Solution {
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
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = N;
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        if(grid[0][0] == 1)
        {
            return -1;
        }
        
        
        queue<pair<pair<int,int>,int>> q;
        q.push(make_pair(make_pair(0,0),1));
        visited[0][0] = true;
        
        while(!q.empty())
        {
            pair<pair<int,int>,int> top_ele = q.front();
            q.pop();
            if((top_ele.first).first == N-1 && (top_ele.first).second == N-1)
            {
                return top_ele.second;
            }
            
            int r = (top_ele.first).first;
            int c = (top_ele.first).second;
            
            for(int i = 0;i<8;i++)
            {
                if(isSafe(r+row_pos[i],c+col_pos[i],visited,N,N) && grid[r+row_pos[i]][c+col_pos[i]] == 0)
                {
                    q.push(make_pair(make_pair(r+row_pos[i],c+col_pos[i]),top_ele.second+1));
                    visited[r+row_pos[i]][c+col_pos[i]] = true;
                }
            }
        }
        return -1;
    }
};
