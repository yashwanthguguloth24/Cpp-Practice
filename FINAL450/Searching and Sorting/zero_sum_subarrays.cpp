// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1


// use hashmap and curr sum variable


class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        map<ll,ll> vals;
        ll sm = 0;
        ll cnt = 0;
        for(int i = 0;i<n;i++)
        {
            sm += arr[i];
            if(sm == 0)
            {
                cnt++;
            }
            if(vals.find(sm) != vals.end()) cnt += vals[sm];
            
            vals[sm]++;
        }
        return cnt;
    }
};
