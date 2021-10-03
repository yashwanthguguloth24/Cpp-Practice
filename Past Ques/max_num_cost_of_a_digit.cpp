/*
Given a cost for each of the digits from 0 to 9, what is the largest string you can create using exactly K amount?

*/

// DP
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int money = 5;
    vector<int> cost = {9, 11, 1, 12, 5, 8, 9, 10, 6};
    vector<vector<int>> dp(money+1,vector<int>(10,0));
    for(int j = 1;j<money+1;j++)
    {
        for(int i = 1;i<10;i++)
        {
            if(j >= cost[i-1])
            {
                dp[j][i] = max(i + 10*dp[j-cost[i-1]][i],dp[j][i-1]);
            }
            else
            {
                dp[j][i] = dp[j][i-1];
            }
        }
    }
    cout << dp[money][9] << endl;
    return 0;
}
