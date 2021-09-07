// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

// take prod and divide and check for zero cases


class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    pair<bool,int> checkZero(vector<long long int>& nums, int n)
    {
        bool flag = false;
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
                flag = true;
            }
        }
        pair<bool,int> temp(flag,cnt);
        return temp;
        
    }
    
    
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans(n,0);
        pair<bool,int> a = checkZero(nums,n);
        if(a.first)
        {
            if(a.second > 1) return ans;
            
            long long prod_nonzero = 1;
            for(int i = 0;i<n;i++)
            {
                if(nums[i] != 0)
                {
                    prod_nonzero = prod_nonzero*nums[i];
                }
            }    
            
            for(int i = 0;i<n;i++)
            {
                if(nums[i] == 0)
                    ans[i] = prod_nonzero;
                else
                    ans[i] = 0;
            }
        }
        else
        {
            long long int prod = 1;
            for(int i = 0;i<n;i++)
            {
                prod = prod*nums[i];
            }
            for(int i = 0;i<n;i++)
            {
                ans[i] = prod/nums[i];
            }            
            
        }
        return ans;
    }
};
