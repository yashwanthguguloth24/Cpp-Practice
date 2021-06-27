// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#

// consider different possibilities in each directions,smart use of direction vectors of rows,cols.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool isStringPresent(vector<vector<char>> &grid, string &word,int row,int col)
    {
	    int n = grid.size();
	    int m = grid[0].size();
	    int l = word.length();
        int rows_dir[] = {0,-1,-1,-1,0,1,1,1};
        int cols_dir[] = {1,1,0,-1,-1,-1,0,1};
        for(int dirs = 0;dirs<8;dirs++)
        {
            int r = row + rows_dir[dirs];
            int c = col + cols_dir[dirs];
            int i;
            for(i = 1;i<l;i++)
            {
                if(r>=n || r<0 || c<0 || c>=m)
                {
                    break;
                }
                if(word[i] != grid[r][c])
                {
                    break;
                }
                r += rows_dir[dirs];
                c += cols_dir[dirs];
            }
            if(i == l)
            {
                return true;
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> res;
	    int n = grid.size();
	    int m = grid[0].size();
	    int l = word.length();
	    for(int row = 0;row<n;row++)
	    {
	        for(int col = 0;col<m;col++)
	        {
	            if(word[0] == grid[row][col])
	            {
	                if(isStringPresent(grid,word,row,col))
	                {
	                    res.push_back({row,col});
	                }
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends
