// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

// fix two rows or cols (c1,c2) and vary them and then use kadane algo for the sum of every elements of a row from col c1 to c2. 
// let S1,S2,..Sn Be sums of all rows from 0  to n. Use kadane for kadane(S1,..Sn) and update max value

/*
for col1 = 0 to n
  for col2 = col1 to n
    generateSums;
    kadane(generatedSums)

*/

class Solution {
  public:
    int kadane(int arr[],int C)
    {
        int max_sum = arr[0];
        int curr_sum = arr[0];
        for(int i = 1;i<C;i++)
        {
            if(curr_sum>0)
            {
                curr_sum += arr[i];
            }
            else
            {
                curr_sum = arr[i];
            }
            max_sum = max(max_sum,curr_sum);
        }
        return max_sum;
    }
  
  
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<vector<int>> presum(R,vector<int> (C,0));
        int ans = INT_MIN;
        for(int j = 0;j<C;j++)
        {
            int col_sum = 0;
            for(int i = 0;i<R;i++)
            {
                col_sum += M[i][j];
                presum[i][j] = col_sum;
            }
        }
        
        int kadesum[C];
        for(int row1 = 0;row1<R;row1++)
        {
            for(int row2 = row1;row2<R;row2++)
            {

                for(int j = 0;j<C;j++)
                {
                    if(row1 == row2)
                    {
                        kadesum[j] = M[row1][j];
                    }
                    else if(row1 == 0)
                    {
                        kadesum[j] = presum[row2][j];
                    }
                    else
                    {
                        kadesum[j] = presum[row2][j]-presum[row1-1][j];
                    }
                }
                
                int tempAns = kadane(kadesum,C);
                ans = max(ans,tempAns);

            }
        }
        return ans;
        
    }
};
