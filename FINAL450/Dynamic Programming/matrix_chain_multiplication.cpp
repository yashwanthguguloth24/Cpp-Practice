// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Done using diagonal filling approach

class Ele
{
    public:
        int row = 0;
        int col = 0;
};


class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int n = N;
        Ele vals[n-1];
        for(int a = 0;a<n-1;a++)
        {
            // ele val(arr[a],arr[a+1]);
            vals[a].row = arr[a];
            vals[a].col = arr[a+1];
        }

        vector<vector<int>> dp(n-1,vector<int>(n-1,0));
        int i,j;

        for(int g = 0;g<n-1;g++)
        {
            for(i=0,j=g;j<n-1;j++,i++)
            {
                if(g == 0)
                {
                    dp[i][j] = 0;
                }
                else if(g == 1)
                {
                    dp[i][j] = vals[i].row*vals[i].col*vals[j].col;
                }
                else
                {
                    // if(j == 1 && i == 0)
                    // {
                    // cout << j << endl;
                    int max_val = INT_MAX;
                    int r1 = i;
                    int c1 = j-g;
                    int r2 = i+1;
                    int c2 = j;
                    int gap = g;
                    while(gap--)
                    {
                        // cout << "(" << r1 << "," << c1 << ")  (" << r2 << "," << c2 << ")" << vals[r1].row*vals[c2].col << endl;
                        int ans = dp[r1][c1]+dp[r2][c2]+(vals[r1].row*vals[c1].col*vals[c2].col);
                        // cout << "(" << r1 << "," << c1 << ")  (" << r2 << "," << c2 << ")" << ans << endl;
                        max_val = min(max_val,ans);
                        r2++;
                        c1++;
                    }
                    dp[i][j] = max_val;                        
                    // }
                }
            }
        }

        // for(int i = 0;i<n-1;i++)
        // {
        //     for(int j = 0;j<n-1;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][n-2];

    }
};
