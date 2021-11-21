// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/


class ele
{
    public:
    int row;
    int col;
    int steps;
    int obs;
    ele(int a,int b,int c,int d)
    {
        row = a;
        col = b;
        steps = c;
        obs = d;
    }
};

bool isSafe(int i,int j,int r,int c)
{
    if(i < 0 || i >= r || j < 0 || j >= c)
    {
        return false;
    }
    return true;
}


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<int> row_dir = {0,1,0,-1};
        vector<int> col_dir = {1,0,-1,0};
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,-1));
        queue<ele> q;
        if(grid[0][0] == 1)
        {
            q.push(ele(0,0,0,k-1));
        }
        else
        {
            q.push(ele(0,0,0,k));
        }
        int ans = INT_MAX;
        while(q.size() > 0)
        {
            ele tp = q.front();
            q.pop();
            int i = tp.row;
            int j = tp.col;
            int steps = tp.steps;
            int obs = tp.obs;
            if(obs < 0)
            {
                continue;
            }
            if(i == r-1 && j == c-1)
            {
                ans = min(ans,steps);
            }

            
            if(visited[i][j] >= obs)
            {
                continue;
            }
            
            visited[i][j] = obs;
            for(int k = 0;k<4;k++)
            {
                int ni = i+row_dir[k];
                int nj = j+col_dir[k];
                if(isSafe(ni,nj,r,c))
                {
                    if(grid[ni][nj] == 1)
                    {
                        if(obs > 0)
                        {
                            q.push(ele(ni,nj,steps+1,obs-1));
                        }
                    }
                    else
                    {
                        q.push(ele(ni,nj,steps+1,obs));
                    }
                    
                }
            }
            
            
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        
        return ans;
        
    }
};
