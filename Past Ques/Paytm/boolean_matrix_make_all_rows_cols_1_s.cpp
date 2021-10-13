class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        set<int> rows;
        set<int> cols;
        for(int i = 0;i<R;i++)
        {
            for(int j = 0;j<C;j++)
            {
                if(matrix[i][j] == 1)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(auto x:rows)
        {
            for(int j = 0;j<C;j++)
            {
                matrix[x][j] = 1;
            }
        }
        
        for(auto y:cols)
        {
            for(int i = 0;i<R;i++)
            {
                matrix[i][y] = 1;
            }
        }
    }
};
