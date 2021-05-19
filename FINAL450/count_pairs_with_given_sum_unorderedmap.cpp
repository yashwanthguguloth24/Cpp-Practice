// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> d;
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            int x = k-arr[i];
            if(x>=0)
            {
                if(d[x] == 0)
                {
                    d[arr[i]]++;
                }
                else
                {
                    cnt += d[x];
                    d[arr[i]]++;
                }
            }
        }
        return cnt;
    }
};
