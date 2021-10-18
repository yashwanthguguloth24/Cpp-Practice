// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int> sgt;
    vector<int> arr;
    int N;
    void buildST(vector<int> nums,int st,int end,int np)
    {
        if(st == end) 
        {
            sgt[np] = nums[st];
            return;
        }
        int mid = st + (end-st)/2;;
        buildST(nums,st,mid,2*np+1);
        buildST(nums,mid+1,end,2*np+2);
        sgt[np] = sgt[2*np+1]+sgt[2*np+2];
    }
    
    void updateUtil(int st,int end,int idx,int diff,int np)
    {
        if(idx < st || idx > end) return;
        
        sgt[np] = sgt[np]+diff;
        if(st != end)
        {
            int mid = st + (end-st)/2;
            updateUtil(st,mid,idx,diff,2*np+1);
            updateUtil(mid+1,end,idx,diff,2*np+2);
        }
    }
    
    
    int sumRangeUtil(int L,int R,int st,int end,int np)
    {
        if(L <= st && R >= end)
        {
            return sgt[np];
        }
        
        if(end < L || st > R)
        {
            return 0;
        }
        int mid = st + (end-st)/2;;
        return (sumRangeUtil(L,R,st,mid,2*np+1)+sumRangeUtil(L,R,mid+1,end,2*np+2));
    }
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        N = n;
        this->arr = nums;
        if(n == 0) return;
        sgt.resize(4*n,0);
        buildST(nums,0,n-1,0);
            
    }
    
    void update(int index, int val) {
        if(index < 0 || index > N-1) return;
        int diff = val-arr[index];
        arr[index] = val;
        updateUtil(0,N-1,index,diff,0);
    }
    
    int sumRange(int left, int right) {
        return (sumRangeUtil(left,right,0,N-1,0));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
