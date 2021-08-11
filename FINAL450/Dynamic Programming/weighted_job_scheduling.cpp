// https://www.geeksforgeeks.org/weighted-job-scheduling/

// sort and LIS,used 2 methods of LIS propagating and non propagating 

// In Propagating -- ans is dp[n-1]
// In non Propagating -- ans is max(dp)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Jobs
{
    public:
        int start_time;
        int finish_time;
        int profit;
        Jobs(int a,int b,int c)
        {
            start_time = a;
            finish_time = b;
            profit = c;
        }
};

bool sortbyfirst(Jobs j1,Jobs j2)
{
    return j1.start_time < j2.start_time;
}


int MaxProfit(Jobs arr[],int n)
{
    vector<int> dp(n,-1);
    sort(arr,arr+n,sortbyfirst);
    dp[0] = arr[0].profit;

    
    // ***** NON PROPAGATING LIS *******
    // for(int i = 0;i<n;i++)
    // {
    //     dp[i] = arr[i].profit;
    // }
    // for(int i = 1;i<n;i++)
    // {
    //     for(int j = 0;j<i;j++)
    //     {
    //         if(arr[j].finish_time<arr[i].start_time && dp[i]<arr[i].profit+dp[j])
    //         {
    //             dp[i] += dp[j]; 
    //         }
    //     }
    // }
    // int maxVal = INT_MIN;
    // for(int i = 0;i<n;i++)
    // {
    //     maxVal = max(dp[i],maxVal);
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    // return maxVal;

    // ***** PROPAGATING LIS *******
    for(int i = 1;i<n;i++)
    {
        int excl = dp[i-1];
        int incl = -1;
        for(int j = 0;j<i;j++)
        {
            if(arr[j].finish_time<arr[i].start_time)
            {
                incl = max(incl,dp[j]);
            }
        }
        if(incl == -1)
        {
            incl = arr[i].profit;
        }
        else
        {
            incl += arr[i].profit;
        }
        dp[i] = max(incl,excl);

    }

    for(int i = 0;i<n;i++)
    {
        cout << dp[i] << " ";
    }

    return dp[n-1];
}



int main()
{
    Jobs arr[] = {Jobs(3, 10, 200), Jobs(1, 2, 50), Jobs(6, 19, 100), Jobs(2, 100, 200)};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The max profit " << MaxProfit(arr,n) << endl;
    return 0;
}
