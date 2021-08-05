// https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

//using backtracking checking all 4 directions and update final answer of each possibility

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 10


int long_path = INT_MIN;
bool isValid(int mat[R][C],int i,int j,vector<vector<int>> vis)
{
    if(i<0 || j<0 || i>R-1 || j>C-1 || mat[i][j] == 0 || vis[i][j] == 1)
    {
        return false;
    }
    return true;
}



void LongRouteRec(int mat[R][C],int i,int j,int x2,int y2,int steps,vector<vector<int>> vis)
{
    if(i == x2 && j == y2)
    {
        long_path = max(long_path,steps);
        return;
    }
    int r_dir[] = {-1,0,1,0};
    int c_dir[] = {0,1,0,-1};
    vis[i][j] = 1;
    for(int k = 0;k<4;k++)
    {
        int ni = i+r_dir[k];
        int nj = j+c_dir[k];
        if(isValid(mat,ni,nj,vis))
        {
            LongRouteRec(mat,ni,nj,x2,y2,steps+1,vis);
        }
    }
    vis[i][j] = 0;
    
}


int LongRoute(int mat[R][C],int x1,int y1,int x2,int y2)
{
    vector<vector<int>> vis(R,vector<int>(C,0));
    LongRouteRec(mat,x1,y1,x2,y2,0,vis);
    if(long_path == INT_MIN)
    {
        return -1;
    }
    else
    {
        return long_path;
    }
}






int main()
{
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    cout << LongRoute(mat,0,0,1,7) << endl;
    return 0;
}
