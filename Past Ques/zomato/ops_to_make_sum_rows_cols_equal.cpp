// https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here
        vector<int> row_sum(n,0);
        vector<int> col_sum(n,0);
        
        int mx_sum = INT_MIN;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                row_sum[i] += matrix[i][j];
                col_sum[j] += matrix[i][j];
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            mx_sum = max(mx_sum,max(row_sum[i],col_sum[i]));
        }
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < n)
        {
            int df = mx_sum-max(row_sum[i],col_sum[j]);
            matrix[i][j] += df;
            row_sum[i] += df;
            col_sum[j] += df;
            ans += df;
            if(row_sum[i] == mx_sum) i++;
            
            if(col_sum[j] == mx_sum) j++;
        }
        return ans;
        
        
    } 
};
