// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

// using dfs traversal and checking conditions(78/80) cases passed

class Solution {
public:
    bool flag = false;
    bool isSafe(int row,int col,vector<vector<bool>> &visited,int N,int M)
    {
        if(row < 0 || col < 0 || row > N-1 || col > M-1 || visited[row][col] == true)
        {
            return false;
        }
        return true;
    }
    
    
    vector<pair<int,int>> nextStep(int r,int c,int key)
    {
        // row ,col
        map<int,vector<pair<int,int>>> cellpath;
        cellpath.insert({1,{make_pair(r,c-1),make_pair(r,c+1)}});
        cellpath.insert({2,{make_pair(r-1,c),make_pair(r+1,c)}});
        cellpath.insert({3,{make_pair(r,c-1),make_pair(r+1,c)}});
        cellpath.insert({4,{make_pair(r,c+1),make_pair(r+1,c)}});
        cellpath.insert({5,{make_pair(r,c-1),make_pair(r-1,c)}});
        cellpath.insert({6,{make_pair(r-1,c),make_pair(r,c+1)}});
        return cellpath[key];
    }
    
    bool dfs(int r,int c,int N,int M,vector<vector<bool>> &visited,vector<vector<int>>& grid)
    {
        // if(visited[r][c] == true)
        // {
        //     return;
        // }
        // visited[r][c] = true;
        if(r == N-1 && c == M-1)
        {
            return true;
        }
        vector<pair<int,int>> nextsteps = nextStep(r,c,grid[r][c]);
        for(int i = 0;i<2;i++)
        {
            if(isSafe(nextsteps[i].first,nextsteps[i].second,visited,N,M))
            {
                // if(nextsteps[i].first == N-1 && nextsteps[i].second == M-1)
                // {
                vector<pair<int,int>> laststeps = nextStep(nextsteps[i].first,nextsteps[i].second,grid[nextsteps[i].first][nextsteps[i].second]);
                for(int j = 0;j<2;j++)
                {
                    if(r == laststeps[j].first && c == laststeps[j].second)
                    {
                        visited[nextsteps[i].first][nextsteps[i].second] = true;
                        if(dfs(nextsteps[i].first,nextsteps[i].second,N,M,visited,grid))
                        {
                            return true;
                        }
                        
                    }
                }
    

            }
        }
        return false;
        
        
    }
    
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        if(N == 1 && M == 1)
        {
            return true;
        }
        
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        
        return dfs(0,0,N,M,visited,grid);
        
        // return (visited[N-1][M-1]);
        // if(visited[N-1][M-1] == true)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
            
        
    }
};
