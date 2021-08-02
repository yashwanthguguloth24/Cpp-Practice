// https://www.geeksforgeeks.org/maximum-product-subset-array/

// consider negative integer count , do operations based on even or odd


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxProduct(int arr[],int n)
{
    // base case
    if(n == 1) return arr[0];


    int max_neg = INT_MIN;
    int zero_cnt = 0;
    int neg_cnt = 0;
    int prod = 1;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            zero_cnt++;
            continue;
        }

        if(arr[i] < 0)
        {
            neg_cnt++;
            max_neg = max(max_neg,arr[i]);
        }

        prod = prod*arr[i];

    }


    if(zero_cnt == n)
    {
        return 0;
    }

    if(neg_cnt%2 != 0)
    {
        if(neg_cnt == 1 && zero_cnt>0 && zero_cnt+neg_cnt == n)
        {
            return 0;
        }

        prod = prod/max_neg;
    }
    return prod;
}






int main()
{
    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << MaxProduct(a,n);
    return 0;
}
