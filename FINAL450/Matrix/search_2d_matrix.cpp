// https://leetcode.com/problems/search-a-2d-matrix

// For every row : check if 1st is less than target, then search using bineary search as rows are sorted.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int row = 0; row <matrix.size();row++)
        {
            if(matrix[row][0]>target)
                break;
            int left = 0;
            int right = matrix[0].size()-1;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if(matrix[row][mid] == target)
                {
                    return 1;
                }
                else if(matrix[row][mid] > target)
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
        }
        return 0;
    }
};
