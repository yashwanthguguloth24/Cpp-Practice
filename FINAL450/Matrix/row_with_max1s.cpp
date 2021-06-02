// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

// Based on smart logic that if we start from top right and span down based no of 1s and zeros,so that cols are spanned once through out iteration

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int col = m-1;
	    int max_cnt = 0;
	    int max_row = -1;
	    for(int row = 0;row < n;row++)
	    {
	        int curr_cnt = 0;
	        if(arr[row][col] == 1)
	        {
	            while(arr[row][col] == 1 && col>=0)
	            {
	                col = col-1;
	            }
	            col = col+1;
	            curr_cnt = m-col+1;
	        }
	        if(curr_cnt > max_cnt)
            {
                max_cnt = curr_cnt;
                max_row = row;
            }
	    }
	    return max_row;
	    
	}

};

