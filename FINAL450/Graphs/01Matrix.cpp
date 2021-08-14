// https://leetcode.com/problems/01-matrix/

// same as rotting oranges, now intially push all zeros in queue


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
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        
        queue<pair<pair<int,int>,int>> q;
        
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j] = true;
                }
            }
        }
        
        vector<int> row_pos = {-1,0,1,0};
        vector<int> col_pos = {0,1,0,-1};
        
        
        while(!q.empty())
        {
            pair<pair<int,int>,int> front_ele = q.front();
            q.pop();
            int r = (front_ele.first).first;
            int c = (front_ele.first).second;
            int ind = front_ele.second;
            
            for(int i = 0;i<4;i++)
            {
                if(isSafe(r+row_pos[i],c+col_pos[i],visited,N,M) && mat[r+row_pos[i]][c+col_pos[i]] == 1)
                {
                    q.push(make_pair(make_pair(r+row_pos[i],c+col_pos[i]),ind+1));
                    mat[r+row_pos[i]][c+col_pos[i]] = ind+1;
                    visited[r+row_pos[i]][c+col_pos[i]] = true;;
                        
                }
            }
            
        }
        
//         for(int i = 0;i<N;i++)
//         {
//             for(int j = 0;j<M;j++)
//             {
//                 if(grid[i][j] == 1)
//                 {
//                     return -1;
//                 }
//             }
//         }
        
        
        return mat;
    }
};
