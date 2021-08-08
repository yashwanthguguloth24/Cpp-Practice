// https://www.geeksforgeeks.org/count-subsequences-product-less-k/


// using 2D DP array where dp[k][i] represents count of subseq with prod less than k, considering conditions for taking and not taking to reach at the answer



/*
//             donot take -- dp[w][i-1] 
//            /                                        
// dp[w][i]                  +                      
//            \                                        
//             take it , if arr[i]<w --> ans+1 & dp[w/arr[i]][i-1] ==> dp[w][i] += 1+dp[w/arr[i]][i-1]
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int CountOfSubsequences(vector<int> arr,int n,int k)
{
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));

    for(int i = 1;i<=k;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];

            if(arr[j-1] <= i && arr[j-1] > 0)
            {
                dp[i][j] += 1+dp[i/arr[j-1]][j-1];
            }
        }
    }

    for(int i = 0;i<=k;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[k][n];
}





int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << CountOfSubsequences(A,A.size(),k) << endl;
    return 0;
}
