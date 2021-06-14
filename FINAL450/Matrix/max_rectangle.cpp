// https://practice.geeksforgeeks.org/problems/max-rectangle/1#


// Approach : Used maximum rectangular area in a histogram for cumilatively summed columns with conditions and finding max area


class Solution{
  public:
    int getMaxArea(int arr[], int n)
    {
        stack<int> stk;
        int i = 0;
        int maxArea = -1;
        
        while(i<n)
        {
            while(i<n && (stk.empty()==1 || arr[i] >= arr[stk.top()]))
            {
                stk.push(i);
                i += 1;
            }
            int currArea = 0;
            while(stk.empty() == 0 && (i == n || arr[stk.top()]>arr[i]))
            {
                int top = stk.top();
                stk.pop();
                if(stk.empty() == 1)
                {
                    currArea = arr[top]*i;
                }
                else
                {
                    currArea = arr[top]*(i-stk.top()-1);
                }
                maxArea = max(maxArea,currArea);
            }
            
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int arr[m] = {0};
        int max_area = -1;
        int curr_area = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(i == 0)
                {
                    arr[j] = M[i][j];
                }
                else
                {
                    if(M[i][j] == 0)
                    {
                        arr[j] = 0;
                    }
                    else
                    {
                        arr[j] += M[i][j];
                    }
                }
            }
            curr_area = getMaxArea(arr,m);
            max_area = max(curr_area,max_area);
        }
        return max_area;
    }
};
