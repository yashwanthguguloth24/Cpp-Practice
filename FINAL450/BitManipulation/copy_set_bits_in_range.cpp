// https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1

// using (1<<x) and check

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        int ans = x;
        for(int i = l-1;i<=r-1;i++)
        {
            if((((1<<i)&y)!=0) && (((1<<i)&x)==0))
            {
                ans += (1<<i);
            }
            
        }
        return ans;
    }
};
