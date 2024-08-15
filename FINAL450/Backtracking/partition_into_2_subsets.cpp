// https://www.geeksforgeeks.org/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum-set-2/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// greedy


class Solution{
    
    public:
    
    int diff = INT_MAX;
    int sm = 0;
    int tot_sum = 0;
    
    void trav(vector<int> &arr, int cur_sm,int i, int l,int n)
    {
        if(i>n)
        {
            return;
        }
        
        if(n%2 == 0)
        {
            if(l == (n/2))
            {
                int d = abs(cur_sm-(tot_sum-cur_sm));
                if(diff>d)
                {
                    diff = d;
                    sm = cur_sm;
                }
                return;
            }
        }
        else
        {
            if(l == ((n-1)/2))
            {
                int d = abs(cur_sm-(tot_sum-cur_sm));
                if(diff>d)
                {
                    diff = d;
                    sm = cur_sm;
                }
                return;
            }            
        }
        
        if(i<n)
        {
            trav(arr,cur_sm+arr[i],i+1,l+1,n);
            trav(arr,cur_sm,i+1,l,n);
        }
    }
    
    vector<vector<int>> minDifference(vector<int>& arr, int n){
        //Code here
        for(int i = 0;i<n;i++)
        {
            tot_sum += arr[i];
        }
        
        trav(arr,0,0,0,n);
        int res1 = sm;
        int res2 = tot_sum-sm;
        vector<int> s1;
        s1.push_back(min(res1,res2));
        vector<int> s2;
        s2.push_back(max(res1,res2));
        vector<vector<int>> ans;
        ans.push_back(s1);
        ans.push_back(s2);
        return ans;
    }
};
