// https://leetcode.com/problems/n-queens/submissions/

// using backtracking to check every column



class Solution {
public:
    
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
            r = i-1 , c = j;
            while(r >= 0 and c >= 0)
            {
                if(QueenPos[r][c] == 1)
                return false;
                r--;
            }
            //left diagonal
            r = i - 1 , c = j - 1;
            while(r >= 0 and c >= 0)
            {
                if(QueenPos[r][c] == 1)
                return false;
                r--; c--;
            }
            //right diagonal
            r = i - 1 , c = j + 1;
            while(r >= 0 and c >= 0 and r < n and c < n)
            {
                if(QueenPos[r][c] == 1)
                return false;
                r--; c++;
            }

        }
        return 1;
    }
    
    vector<string> Convert(vector<vector<int>> QueenPos,int n)
    {
        vector<string> v1;
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j = 0;j<n;j++)
            {
                if(QueenPos[i][j] == 0)
                {
                    temp += ".";
                }
                else
                {
                    temp += "Q";
                }
            }
            v1.push_back(temp);
        }
        return v1;
    }
    
    
    vector<vector<string>> ans;
    void NQ(vector<vector<int>> QueenPos,int i,int j,int n,int cnt)
    {
        if(cnt == n)
        {
            vector<string> v = Convert(QueenPos,n);
            ans.push_back(v);
            return;
        }

        // int row,col;
        for(int col = 0;col<n;col++)
        {
            if(isSafe(QueenPos,i,col,n))
            {
                QueenPos[i][col] = 1;
                NQ(QueenPos,i+1,col,n,cnt+1);
                QueenPos[i][col] = 0;
            }
        }

        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> QueenPos(n,vector<int>(n,0));
        NQ(QueenPos,0,0,n,0);
        return ans;
    }
};
