// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/#:~:text=Given%20an%20integer%20n%2C%20calculate,*%2C%20%2F%20and%20pow().&text=A%20Simple%20Solution%20is%20to%20repeatedly%20add%20n%20to%20result.

#include<bits/stdc++.h>
using namespace std;

int square(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n < 0)
    {
        n = -n;
    }
    int x = n >> 1;
    if(n&1)
    {
        // odd
        return ((square(x)<<2) + (x << 2) + 1);
    }
    else
    {
        return (square(x) << 2);
    }
}


int main()
{
    cout << square(-5) << endl;
    return 0;
}
