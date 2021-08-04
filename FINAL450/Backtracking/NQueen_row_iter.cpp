#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printMat(vector<vector<int>> a,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


bool isValid(int row,int col,int n)
{
    if(row < 0 || row > n-1 || col < 0 || col > n-1)
    {
        return 0;
    }
    return 1;
}
bool isSafe(vector<vector<int>> QueenPos,int i,int j,int n)
{
    if(isValid(i,j,n) == 0)
    {
        return 0;
    }
    else
    {
        int r , c;
        //left
        r = i , c = j-1;
        while(r >= 0 and c >= 0)
        {
            if(QueenPos[r][c] == 1)
            return false;
            c--;
        }
        //up
        // r = i-1 , c = j;
        // while(r >= 0 and c >= 0)
        // {
        //     if(QueenPos[r][c] == 1)
        //     return false;
        //     r--;
        // }
        //left diagonal
        r = i - 1 , c = j - 1;
        while(r >= 0 and c >= 0)
        {
            if(QueenPos[r][c] == 1)
            return false;
            r--; c--;
        }
        //right diagonal
        r = i+1 , c = j-1;
        while(r >= 0 and c >= 0 and r < n and c < n)
        {
            if(QueenPos[r][c] == 1)
            return false;
            r++; c--;
        }

    }
    return 1;
}

void NQ(vector<vector<int>> QueenPos,int i,int j,int n,int cnt)
{
    if(cnt == n)
    {
        printMat(QueenPos,n);
        cout << endl;
        return;
    }

    // int row,col;
    for(int row = 0;row<n;row++)
    {
        if(isSafe(QueenPos,row,j,n))
        {
            QueenPos[row][j] = 1;
            NQ(QueenPos,row,j+1,n,cnt+1);
            QueenPos[row][j] = 0;
        }
    }

    
}

void solveNQueens(int n) {
    vector<vector<int>> QueenPos(n,vector<int>(n,0));
    NQ(QueenPos,0,0,n,0);
    // vector<vector<string>> ans;
    // return ans;
}


int main()
{
    solveNQueens(4);
    return 0;
}
