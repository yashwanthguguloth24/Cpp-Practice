// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#


// Use upperbound for count of elements less than X and X will vary from INT_MIN to INT_MAX , so apply binary search to find X also .


class Solution{   
public:
    int Upperbound(vector <int> arr,int k,int c)
    {
        int low = 0;
        int high = c-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid] == k)
            {
                low = mid+1;
            }
            else if(arr[mid] > k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
        int start = 0;
        int end = 100000000;
        int ans = 0;
        while(start<=end)
        {
            int mid = (start+end)/2;
            int cnt = 0;
            for(int i = 0;i<r;i++)
            {
                cnt += Upperbound(matrix[i],mid,c);
            }
            if(cnt <= (r*c)/2)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return start;
    }
};

