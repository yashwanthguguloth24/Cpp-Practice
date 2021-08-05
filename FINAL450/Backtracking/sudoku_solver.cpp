// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1#

//exploring all the possibilities to get answer, stop backtracking If ans is found
 




#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    // bool flag = false;

    void printGrid(int grid[N][N]) 
    {
         for(int i = 0;i<N;i++)
         {
             for(int j = 0;j<N;j++)
             {
                 cout << grid[i][j] << " ";
             }
         }
    }
    
    
    bool isSafe(vector<vector<int>> &vec,int i,int j,int val)
    {

        
        for(int col = 0;col<N;col++)
        {
            if(vec[i][col] == val)
            {
                return false;
            }
        }
        for(int row = 0;row<N;row++)
        {
            if(vec[row][j] == val)
            {
                return false;
            }
        }        
        
        i = (i/3)*3;
        j = (j/3)*3;
        for(int r = 0;r<3;r++)
        {
            for(int c = 0;c<3;c++)
            {
                if(vec[i+r][j+c] == val)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void SolveSudokuRec(vector<vector<int>> &vec,int i,int j,bool &flag)
    {
        if(i == N)
        {
            flag = true;
            return ;

        }
        

        int ni = 0;
        int nj = 0;
        
        if(j == N-1)
        {
            ni = i+1;
            nj = 0;
        }
        else
        {
            ni = i;
            nj = j+1; 
        }
        
        if(vec[i][j] != 0)
        {
            SolveSudokuRec(vec,ni,nj,flag);
        }
        else
        {
            for(int num = 1;num<10;num++)
            {
                if(isSafe(vec,i,j,num))
                {
                    vec[i][j] = num;
                    SolveSudokuRec(vec,ni,nj,flag);
                    if(flag == false)
                    {
                        vec[i][j] = 0;
                    }
    
                }
                
            }

            
        }
        
    }
        
        
        

        
        
        
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        vector<vector<int>> vec(N);
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                vec[i].push_back(grid[i][j]);
            }
        }
        bool flag = false;
        SolveSudokuRec(vec,0,0,flag);
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                grid[i][j] = vec[i][j];
            }
        }
        return flag;
    }
    
    //Function to print grids of the Sudoku.
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
