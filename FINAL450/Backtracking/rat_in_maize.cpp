// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// using backtracking steps in every direction

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isValid(vector<vector<int>> &m,int row,int col,int n)
    {
        if(row < 0 || row > n-1 || col < 0 || col > n-1 || m[row][col] == 0)
        {
            return 0;
        }
        return 1;
    }
    vector<string> ans;
    
    void FindPathBT(vector<vector<int>> &m, string path,int row,int col,int n,vector<vector<int>> vis)
    {
        if(row == n-1 && col == n-1)
        {
            // cout << path << endl;
            // cout << "called" << endl;
            ans.push_back(path);
            return ;
        }
        // cout << "main rec called" << endl;
        vector<char> path_info = {'U','D','L','R'};
        vector<int> row_dir = {-1,1,0,0};
        vector<int> col_dir = {0,0,-1,1};
        // cout << row << " " << col << endl;
        if(vis[row][col] == 1) 
        {
            // cout << "visited called " << endl;
            return ;
        }
        // cout << "is ended" << endl;
        if(isValid(m,row,col,n))
        {
            vis[row][col] = 1;
            for(int i = 0;i<4;i++)
            {
                if(isValid(m,row+row_dir[i],col+col_dir[i],n))
                {
                    // visited[row+row_dir[i]][col+col_dir[i]] = 1;
                    path.push_back(path_info[i]); // make decision
                    // cout << path << endl;
                    // cout << i << endl;
                    FindPathBT(m,path,row+row_dir[i],col+col_dir[i],n,vis); // recur
                    // cout << i << endl;
                    // cout << path << endl;
                    path.pop_back(); // UNDO
                    // visited[row+row_dir[i]][col+col_dir[i]] = 0;
                }
            }

        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string path = "";
        vector<vector<int>> visited(n,vector<int>(n,0));
        FindPathBT(m,path,0,0,n,visited);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
