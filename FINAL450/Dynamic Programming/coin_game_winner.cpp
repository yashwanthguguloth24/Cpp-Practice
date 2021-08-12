// https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/

// Creating subproblem of lower n values, check bool at those problem for a n

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool CanAwin(int n,int x,int y)
{
    vector<bool>dp(n+1,false);
    dp[0] = false;
    dp[1] = true;
    for(int i = 2;i<n+1;i++)
    {
        if(i>=x && dp[i-x] == false)
        {
            dp[i] = true;
        }
        else if(i>=y && dp[i-y] == false)
        {
            dp[i] = true;
        }
        else if(dp[i-1] == false)
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }


    }
    for(int i = 0;i<n+1;i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}




int main()
{
    cout << CanAwin(5,3,4) << endl;
    return 0;
}
