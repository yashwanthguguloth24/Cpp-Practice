#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;


// multiply with 10^2*decimals places to n and find the answer of n and divide it by 10^decimals


class Solution
{
    public:
        int decimals = 3;
        double eps = 0.01;
        double FindSQrt(int n)
        {
            double st = 1;
            double end = n/2;
            while(st < end)
            {
                double mid = (st+end)/2;
                if(abs(mid*mid-n) < eps)
                {
                    return mid;
                }
                else if(mid*mid > n)
                {
                    end = mid;
                }
                else
                {
                    st = mid;
                }
                
            }

        }

        double SQrtDecimals(long long int n)
        {
            n = n*pow(10,2*decimals);
            long long int st = 0;
            long long int end = n/2;
            long long int mid;
            while(st <= end)
            {
                mid = (st+end)/2;
                cout << mid << endl;
                // if(abs((mid*mid)-n)<=pow(10,decimals))
                // {
                //     cout << mid << endl;
                //     break;
                // }
                if(mid*mid >n)
                {
                    end = mid-1;
                }
                else
                {
                    st = mid+1;
                }
            }
            return (double) mid/pow(10,decimals);
        }
};



int main()
{
    Solution s;
    cout << fixed << setprecision(s.decimals) << s.FindSQrt(77)  << endl;
    cout << s.SQrtDecimals(7) << endl;
    return 0;
}
