// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#


/*

To find the number of trailing zeros of a number
use ---> num =  [n/5]+[n/5^2] + [n/5^3] +..........

*/

class Solution
{
    public:
        int zeroCnt(int n)
        {
            int ans = 0;
            while(n>0)
            {
                ans += (n/5);
                n = n/5;
            }
            return ans;
        }
    
    
        int findNum(int n)
        {
            int l = 0;
            int h = INT_MAX;
            int ans = 0;
            while(l <= h)
            {
                int mid = l + (h-l)/2;
                int x = zeroCnt(mid);
                if(x >= n)
                {
                    ans = mid;
                    h = mid-1;
                }
                else
                {
                    l = mid+1;
                }
                
            }
            return ans;
        }
};
