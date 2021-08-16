// https://leetcode.com/problems/knight-probability-in-chessboard/

// https://www.youtube.com/watch?v=54nJhM2AZv4


// used DFS/BACKTRACKING(gave TLE) and DP approaches
//*************************DFS/BACKTRACKING***************************

class Solution {
public:
    int num_on_board = 0;
    vector<int> row_pos = {-2,-1,1,2,2,1,-1,-2};
    vector<int> col_pos = {1,2,2,1,-1,-2,-2,-1};
    
    bool isSafe(int row,int col,int N)
    {
        if(row < 0 || col < 0 || row > N-1 || col > N-1)
        {
            return false;
        }
        return true;
    }
    
    
   	void dfs(int r,int c,int k,int n,vector<vector<bool>> &visited)
	{
        if(k==0)
        {
            num_on_board++;
            return;
        }

	    for(int i = 0;i<8;i++)
	    {
            if(isSafe(r+row_pos[i],c+col_pos[i],n))
            {
                visited[r][c] = true;
                dfs(r+row_pos[i],c+col_pos[i],k-1,n,visited);
                visited[r][c] = false;
            }
	    }
	} 
    
    
    double knightProbability(int n, int k, int row, int column) {
        // this can be solved using DFS
        if(n == 1)
        {
            if(k == 0)
            {
                return (double)1;
            }
            else
            {
                return (double)0;
            }
        }
        double p;
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        
        dfs(row,column,k,n,visited);
        
        p = (double)(num_on_board)/(pow(8,k));
        return p;
        
        
    }
};

//*************************DP***************************
class Solution {
public:
    void copyVec(vector<vector<double>> &a,vector<vector<double>> &b,int n)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                b[i][j] = a[i][j];
            }
        }
    }
    
    bool isSafe(int row,int col,int N)
    {
        if(row < 0 || col < 0 || row > N-1 || col > N-1)
        {
            return false;
        }
        return true;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double> (n,0));
        vector<vector<double>> temp(n,vector<double> (n,0));
        vector<vector<double>> next(n,vector<double> (n,0));
        vector<int> row_pos = {-2,-1,1,2,2,1,-1,-2};
	    vector<int> col_pos = {1,2,2,1,-1,-2,-2,-1};
        
        curr[row][column] = 1;
        
        for(int m = 0;m<k;m++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(curr[i][j] != 0)
                    {
                        for(int s = 0;s<8;s++)
                        {
                            if(isSafe(i+row_pos[s],j+col_pos[s],n))
                            {
                                next[i+row_pos[s]][j+col_pos[s]] += curr[i][j]/8.0;
                            }
                        }
                    }
                }
            }
            curr = next;
            copyVec(temp,next,n);
        }
        
        double ans = 0.0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                ans += curr[i][j];
            }
        }
        return ans;
        
    }
};
