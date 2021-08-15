// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1#

// Solved Floyd Warshall algo . Put inf if not connected

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int N = matrix.size();
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
	            
	    
	   // int N = matrix.size();
	    for(int k = 0;k<N;k++)
	    {
	        for(int i = 0;i<N;i++)
	        {
	            for(int j = 0;j<N;j++)
	            {
	                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
	                {
	                    continue;
	                }
	                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
	                {
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	            }
	        }
	    }
	    
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(matrix[i][j] == INT_MAX)
                {
                    matrix[i][j] = -1;
                }
            }
        }
	    
	}
};
