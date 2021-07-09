// https://leetcode.com/problems/sqrtx/

/*
To get the square root inital guess a and x/a must be as close as possible
Taking intial guess as a = x/2
then updating a every time with (a+x/a)/2.
Until a <= x/a, a is just less than or equal to x/a

*/

class Solution {
public:

    long long int SQrtRec(long long int a,int x)
    {
        if(a*a <= x)
        {
            return a;
        }
        else
        {
            a = (a+x/a)/2;
            return SQrtRec(a,x);
        }
    }
    
    int mySqrt(int x) {
        if(x == 1) return 1;
        long long int a = x/2;
        long long int ans = SQrtRec(a,x);
        return ans;
        // iterative**
        // long long int ans;
        // long long int i = 0;
        // while(i*i<=x)
        // {
        //     i++;
        // }
        // ans = i;
        // return ans-1;
        
    }
};
