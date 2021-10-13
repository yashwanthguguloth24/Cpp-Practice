#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n = 420;
    int temp = n;
    int ans = 0;
    int raise = 1;
    while(temp > 0)
    {
        int r = temp%10;
        cout << "****" << endl;
        // cout << r << endl;
        // int u = (pow(10,i));
        // cout << u << endl;
        ans = ans + raise*(9-r);
        cout << ans << endl;
        cout << "***" << endl;
        temp = temp/10;
        raise = raise*10;
    }
    cout << ans << endl;
    return 0;
}
