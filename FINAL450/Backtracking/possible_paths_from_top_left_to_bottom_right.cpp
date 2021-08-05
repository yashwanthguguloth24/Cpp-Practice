// https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/

// traditional backtracking method , checking possibilites in directions and printing


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define R 2
#define C 2


bool isValid(int mat[R][C],int i,int j,vector<vector<int>> vis)
{
    if(i<0 || j<0 || i>R-1 || j>C-1 || vis[i][j] == 1)
    {
        return false;
    }
    return true;
}

vector<vector<int>> paths;

void PossiblePathsRec(int mat[R][C],int i,int j,vector<vector<int>> vis,vector<int> &v)
{
    if(i == R-1 && j == C-1)
    {
        paths.push_back(v);
        return;
    }
    //right
    vis[i][j] = 1;
    if(isValid(mat,i,j+1,vis))
    {
        v.push_back(mat[i][j+1]);
        PossiblePathsRec(mat,i,j+1,vis,v);
        v.pop_back();
    }

    if(isValid(mat,i+1,j,vis))
    {
        v.push_back(mat[i+1][j]);
        PossiblePathsRec(mat,i+1,j,vis,v);
        v.pop_back();
    }
    vis[i][j] = 0;
}


int main()
{
    int mat[R][C] = { {1, 2}, {3,4} };
    vector<int> v;
    v.push_back(mat[0][0]);
    vector<vector<int>> vis(R,vector<int>(C,0));
    PossiblePathsRec(mat,0,0,vis,v);
    for(int i = 0;i<paths.size();i++)
    {
        for(int j = 0;j<paths[i].size();j++)
        {
            cout << paths[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}
