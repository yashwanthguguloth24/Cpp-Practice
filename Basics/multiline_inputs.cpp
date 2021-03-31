// https://www.codechef.com/COOK127C/problems/WEIGHTBL

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int w1,w2,x1,x2,M;
        cin >> w1 >> w2 >> x1 >> x2 >> M;
        int diff = (w2-w1);
        if (diff >= x1*M && diff <= x2*M)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
