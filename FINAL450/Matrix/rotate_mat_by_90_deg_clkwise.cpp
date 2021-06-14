// https://leetcode.com/problems/rotate-image/

// Transpose + mirror about mid point 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i<j)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<(int) n/2;j++)
            {
                int temp1 = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp1;
            }
        }
    }
};
