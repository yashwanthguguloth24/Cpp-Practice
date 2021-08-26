// https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/

#include<bits/stdc++.h>
using namespace std;

int divide(int a,int b)
{
    int sign = 1;
    if(a < 0 && b < 0)
    {
        sign = 1;
    }
    else if(a < 0 || b < 0)
    {
        sign = -1;
    }
    a = abs(a);
    b = abs(b);

    int q = 0;
    while(a>b)
    {
        a = a-b;
        q++;
    }
    if(sign == 1)
    {
        return q;
    }
    return -q;
}


int main()
{
    cout << divide(10,3) <<endl;
    cout << divide(43,-8) <<endl;
    return 0;
}
