// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

// 2 foor loops and 2 pointers (NOTE: consider the cases for duplicates)


class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        // set<vector<int>> st;
        if(n < 4) return ans;
        
        for(int i = 0;i<=n-4;i++)
        {
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j = i+1;j<=n-3;j++)
            {
                if(j>i+1 && arr[j] == arr[j-1])continue;
                int p = j+1;
                int q = n-1;
                while(q>p)
                {
                    int sm = arr[i]+arr[j]+arr[q]+arr[p];
                    if(sm == k)
                    {

                        ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                        p++;
                        q--;
                        while(q>p && arr[p] == arr[p-1])
                        {
                            p++;
                        }
                        while(q<n-1 && q>p && arr[q] == arr[q+1])
                        {
                            q--;
                        }                        

                    }
                    else if(sm > k)
                    {
                        q--;
                    }
                    else
                    {
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};
