// https://leetcode.com/problems/flood-fill/

// using BFS traversal

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
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // bfs traversal
        int N = image.size();
        int M = image[0].size();
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        
        vector<int> row_pos = {-1,0,1,0};
        vector<int> col_pos = {0,1,0,-1};
        
        while(!q.empty())
        {
            pair<int,int> top_ele = q.front();
            q.pop();
            int r = top_ele.first;
            int c = top_ele.second;
            if(visited[r][c] == true)
            {
                continue;
            }
            visited[r][c] = true;
            
            for(int i = 0;i<4;i++)
            {
                if(isSafe(r+row_pos[i],c+col_pos[i],visited,N,M) && image[r][c] == image[r+row_pos[i]][c+col_pos[i]])
                {
                    q.push(make_pair(r+row_pos[i],c+col_pos[i]));
                }
            }
            image[r][c] = newColor;
            
        }
        return image;
        
        
    }
};
