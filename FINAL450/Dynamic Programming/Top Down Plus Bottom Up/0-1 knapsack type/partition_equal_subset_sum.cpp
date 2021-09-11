// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

// TOP + REC
// same as subset sum problem but here sum = (total_arr_sum)/2;

// Bottom Up Code

int equalPartition(int N, int arr[])
{
    int sm = 0;
    for(int i = 0;i<N;i++)
    {
        sm += arr[i];
    }

    if(sm%2 != 0)
    {
        return 0;
    }
    vector<vector<int>> dp(N+1,vector<int>((sm/2)+1,0));

    for(int i = 0;i<N+1;i++)
    {
        dp[i][0] = 1;
    }

    for(int i = 1;i<N+1;i++)
    {
        for(int j = 1;j<(sm/2)+1;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=arr[i-1])
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] | dp[i][j];
            }
        }
    }
    return dp[N][(sm/2)];


}
