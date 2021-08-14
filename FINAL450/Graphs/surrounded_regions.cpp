// https://leetcode.com/problems/surrounded-regions/

// dfs traversal on borders 

class Solution {
public:
    vector<int> row_pos = {-1,0,1,0};
    vector<int> col_pos = {0,1,0,-1};
    bool isSafe(int row,int col,int N,int M,vector<vector<bool>> &visited)
    {
        if(row < 0 || col < 0 || row > N-1 || col > M-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    
    void dfs(int r,int c,int N,int M,vector<vector<bool>> &visited,vector<vector<char>>& board)
    {
        for(int i = 0;i<4;i++)
        {
            if(isSafe(r+row_pos[i],c+col_pos[i],N,M,visited) && board[r+row_pos[i]][c+col_pos[i]] == 'O')
            {
                 board[r+row_pos[i]][c+col_pos[i]] = '-';
                 visited[r+row_pos[i]][c+col_pos[i]] = true;
                 dfs(r+row_pos[i],c+col_pos[i],N,M,visited,board);
            }
        }
        
        
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        int N = board.size();
        int M = board[0].size();
        
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        
        for(int j = 0;j<M;j++)
        {
            if(board[0][j] == 'O')
            {
                visited[0][j] = true;
                board[0][j] = '-';
                dfs(0,j,N,M,visited,board);
            }
            
            if(board[N-1][j] == 'O')
            {
                visited[N-1][j] = true;
                board[N-1][j] = '-';
                dfs(N-1,j,N,M,visited,board);                
            }
            visited[0][j] = true;
            visited[N-1][j] = true;
        }
        for(int i = 0;i<N;i++)
        {
            if(board[i][0] == 'O')
            {
                visited[i][0] = true;
                board[i][0] = '-';
                dfs(i,0,N,M,visited,board);
            }
            
            if(board[i][M-1] == 'O')
            {
                visited[i][M-1] = true;
                board[i][M-1] = '-';
                dfs(i,M-1,N,M,visited,board);                
            }
            visited[i][0] = true;
            visited[i][M-1] = true;
        }
        
        
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<M;j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '-')
                {
                    board[i][j] = 'O';
                }
            }
        }

        
    }
};
