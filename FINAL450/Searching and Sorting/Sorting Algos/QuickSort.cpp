class Solution {
public:
    
    int partition(vector<int> &nums,int st,int end)
    {
        int pivot = nums[end];
        int pIndex = st;
        
        for(int i = st;i<=end-1;i++)
        {
            if(nums[i] <= pivot)
            {
                // int temp = nums[i];
                // nums[i] = nums[pIndex];
                // nums[pIndex] = temp;
                swap(nums[i],nums[pIndex]);
                pIndex++;
            }
        }
        swap(nums[end],nums[pIndex]);
        return pIndex;
    }
    
    
    void QuickSort(vector<int> &nums,int st,int end)
    {
        if(st >= end) return;
        
        int p = partition(nums,st,end);
        QuickSort(nums,st,p-1);
        QuickSort(nums,p+1,end);
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        QuickSort(nums,0,n-1);
        return nums;
    }
};
