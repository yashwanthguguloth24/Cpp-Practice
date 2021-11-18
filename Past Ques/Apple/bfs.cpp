#include<bits/stdc++.h>
using namespace std;

class ele
{
    public:
    int rows;
    int cols;
    int steps;
    ele(int a,int b,int c)
    {
        rows = a;
        cols = b;
        steps = c;
    }
};

bool isSafe(int r,int c,int n,int m)
{
    if(r < 0 || c < 0 || c >= m || r >= n)
    {
        return false;
    }
    return true;
}


int main()
{
    vector<string> grid = {"..##","#.##","#..."};
    int mx_time = 5;
    int n = grid.size();
    int m = grid[0].length();
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    queue<ele> q;
    q.push(ele(0,0,0));
    bool flag = false;
    vector<int> row_dirs = {-1,0,1,0};
    vector<int> col_dirs = {0,1,0,-1};
    while(q.size() > 0)
    {
        ele tp = q.front();
        q.pop();
        int r = tp.rows;
        int c = tp.cols;
        int steps = tp.steps;
        if(r == n-1 and c == m-1)
        {
            if(steps <= mx_time)
            {
                flag = true;
                cout << "Yes" << endl;
                break;
            }
        }
        if(vis[r][c] == true)
        {
            continue;
        }
        vis[r][c] = true;
        for(int k = 0;k < 4;k++)
        {
            int nr = r+row_dirs[k];
            int nc = c+col_dirs[k];
            if(isSafe(nr,nc,n,m) and vis[nr][nc] == false)
            {
                q.push(ele(nr,nc,steps+1));
            }
        }

    }

    if(flag == false)
    {
        cout << "No" << endl;
    }
    return 0;
}
