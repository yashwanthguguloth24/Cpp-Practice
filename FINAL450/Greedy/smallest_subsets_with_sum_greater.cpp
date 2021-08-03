// https://www.geeksforgeeks.org/smallest-subset-sum-greater-elements/

// sort and check if sum greater or lesser

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int SmallestSubsets(int arr[],int n)
{
    sort(arr,arr+n);
    int sum_arr[n];
    int s = 0;
    for(int i = 0;i<n;i++)
    {
        s += arr[i];
        sum_arr[i] = s;
    }

    int cnt = 1;
    int j = n-1;
    int ans = 0;
    int last_sum = arr[j];
    while(j>=1 && last_sum<sum_arr[j-1])
    {
        last_sum += arr[j-1];
        j--;
        cnt++;
    }
    return cnt;

}



int main()
{
    // int arr[] = {3, 1, 7, 1};
    int arr[] = {2,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << SmallestSubsets(arr,n) <<endl;
    return 0;
}
