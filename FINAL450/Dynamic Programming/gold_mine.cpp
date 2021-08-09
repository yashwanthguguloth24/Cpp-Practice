// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

// iterating from last column (similar to top down approach)


class Solution{
public:
    int max3(int a,int b,int c)
    {
        int temp = max(a,b);
        int res = max(temp,c);
        return res;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> gold(n,vector<int>(m,0));
        for(int col = m-1;col>=0;col--)
        {
            for(int row = 0;row<n;row++)
            {
                // condition ? result_if_true : result_if_false
                int right_top = (row == 0 || col == m-1)?0:gold[row-1][col+1];
                
                int right = (col == m-1)?0:gold[row][col+1];
                
                int right_down = (row == n-1 || col==m-1)?0:gold[row+1][col+1];
                
                gold[row][col] = M[row][col] + max3(right_top,right,right_down);
                
                
            }
        }
        
        int max_val = -1;
        
        for(int i = 0;i<n;i++)
        {
            max_val = max(max_val,gold[i][0]);
        }
        return max_val;
        
        
    }
};
// ***************************************************************************************************************************
// BOTTOM UP APPROACH

class Solution{
public:
    int max3(int a,int b,int c)
    {
        int temp = max(a,b);
        int res = max(temp,c);
        return res;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> gold(n,vector<int>(m,0));
        // for(int col = m-1;col>=0;col--)
        // {
        //     for(int row = 0;row<n;row++)
        //     {
        //         // condition ? result_if_true : result_if_false
        //         int right_top = (row == 0 || col == m-1)?0:gold[row-1][col+1];
                
        //         int right = (col == m-1)?0:gold[row][col+1];
                
        //         int right_down = (row == n-1 || col==m-1)?0:gold[row+1][col+1];
                
        //         gold[row][col] = M[row][col] + max3(right_top,right,right_down);
                
                
        //     }
        // }
        for(int col = 0;col<m;col++)
        {
            for(int row = 0;row < n;row++)
            {
                if(col == 0)
                {
                    gold[row][col] = M[row][col];
                }
                else
                {
                    int right_top = (row > 0)?gold[row-1][col-1]:0;
                    int right = gold[row][col-1];
                    int right_down = (row < n-1)?gold[row+1][col-1]:0;
                    gold[row][col] = M[row][col] + max3(right_top,right,right_down);
                }
            }
        }
        
        int max_val = -1;
        
        for(int i = 0;i<n;i++)
        {
            max_val = max(max_val,gold[i][m-1]);
        }
        return max_val;
        
        
    }
};
