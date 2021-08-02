// https://www.geeksforgeeks.org/maximum-sum-absolute-difference-array/

// The greedy choice is to have sequence like this : small,large,small,large,…


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxDiff(int a[],int n)
{
    vector<int> arr;
    sort(a,a+n);

    int i = 0;
    int j = n-1;
    while(i<j)
    {
        arr.push_back(a[i]);
        arr.push_back(a[j]);
        i++;
        j--;
    }
    int ans = 0;
    for(int i = 0;i<n-1;i++)
    {
        ans += abs(arr[i]-arr[i+1]);
    }
    ans += abs(arr[n-1]-arr[0]);
    return ans;
}





int main()
{
    int a[] = {1,2,4,8};
    int n = sizeof(a) / sizeof(a[0]);
    cout << MaxDiff(a,n) << endl;
    return 0;
}
