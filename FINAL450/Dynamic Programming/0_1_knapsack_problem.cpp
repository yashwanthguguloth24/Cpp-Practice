// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// using 2d DP array where dp[i][w] is "the max value of first i items with weight w", so considering its choices we get the answer

//          take item - val[i] + dp[i-1][w-w[i]]    }
//         /                                        }
// dp[i][w]                                         }-- max of these two
//         \                                        }
//          donot take item - dp[i-1][w]            }


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n+1,vector<int> (W+1,0));
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<W+1;j++)
            {
                if(j>=wt[i-1])
                {
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};
