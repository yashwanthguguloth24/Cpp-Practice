#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int r,int c)
{
    if(i < 0 || i >= r || j < 0 || j >= c)
    {
        return false;
    }
    return true;
}


int solve(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int tsi = 0;
    int tsj = 0;
    bool flag = false;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j] != 0)
            {
                tsi = i;
                tsj = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    int num_visits = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j] != 0) num_visits++;
        }
    }
    queue<vector<int>> q;
    q.push({tsi,tsj,grid[tsi][tsj],num_visits-1});
    int min_dist = INT_MAX;
    vector<int> row_dirs = {0,1};
    vector<int> col_dirs = {1,0};
    // cout << tsi << " " << tsj << endl; 
    while(q.size() > 0)
    {
        vector<int> tp = q.front();
        q.pop();
        int r = tp[0];
        int c = tp[1];
        // cout << r << " " << c << " " << tp[3] << endl;
        if(tp[3] == 0)
        {
            // cout << "here" << endl;
            min_dist = min(min_dist,tp[2]);
            continue;
        }
        for(int k = 0;k<2;k++)
        {
            int ni = r+row_dirs[k];
            int nj = c+col_dirs[k];
            if(isSafe(ni,nj,n,m))
            {
                int val = (grid[ni][nj] != 0)?1:0;
                q.push({ni,nj,tp[2]+2+grid[ni][nj],tp[3]-val});
            }

        }
    }
    return min_dist;
}



int main()
{
    vector<vector<int>> grid = {{2,0,0},{0,0,0},{0,0,1}};
    cout << solve(grid) << endl;
    return 0;
}
