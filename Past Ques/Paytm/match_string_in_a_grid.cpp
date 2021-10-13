#include<bits/stdc++.h>
using namespace std;
bool isSafe(int r,int c,int n,int m)
{
    if(r < 0 || r >= n || c < 0 || c >= m)
    {
        return false;
    }
    return true;
}



void dfs(int i,int r,int c,int n,int m,vector<string> mat,string word,vector<vector<int>> &path)
{
    if(i == word.length())
    {
        // print res
        for(int p = 0;p<path.size();p++)
        {
            
            cout << word[path[p][0]] << "(" << path[p][1] << "," << path[p][2] << ")" << "  ";
        }
        cout << endl;
        return;
    }
    vector<int> row_dirs = {-1,0,1,1,1,0,-1,-1};
    vector<int> col_dirs = {1,1,1,0,-1,-1,-1,0};

    for(int k = 0;k<8;k++)
    {
        int nr = r + row_dirs[k];
        int nc = c + col_dirs[k];
        if(isSafe(nr,nc,n,m))
        {
            if(word[i] == mat[nr][nc])
            {
                path.push_back({i,nr,nc});
                dfs(i+1,nr,nc,n,m,mat,word,path);
                path.pop_back();
            }
        }
    }

}



void solve(vector<string> mat,string word)
{
    int n = mat.size();
    int m = mat[0].length();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            vector<vector<int>> path;
            if(mat[i][j] == word[0])
            {
                path.push_back({0,i,j});
                dfs(1,i,j,n,m,mat,word,path);
                path.pop_back();
            }
        }
    }
}



int main()
{
    vector<string> mat = {"BNEYS","HEDES","SGNDE"};
    string word = "DES";
    solve(mat,word);
    return 0;
}
