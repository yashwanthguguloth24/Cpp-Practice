// https://leetcode.com/problems/powx-n/

/*
Using recursion to reduce the power by 2 in every iteration
*/

class Solution {
public:
    double CalcPow(double x,int n)
    {
        if(n == 0)
        {
            return 1;
        }
        if(n < 0)
        {
            if(n%2 == 0)
            {
                double y = CalcPow(x,n/2);
                return y*y;
            }
            else
            {
                return (1/x)*CalcPow(x,n+1);
            }
        }
        else
        {
            if(n%2 == 0)
            {
                double y = CalcPow(x,n/2);
                return y*y;
            }
            else
            {
                return x*(CalcPow(x,n-1));
            }
        }
    }
    
    
    double myPow(double x, int n) {
        double ans = CalcPow(x,n);
        return ans;
    }
};
