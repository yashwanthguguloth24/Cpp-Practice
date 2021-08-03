// https://www.geeksforgeeks.org/minimum-sum-absolute-difference-pairs-two-arrays/

// sorting both the arrays is the greedy choice


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int MinDiff(int arr1[],int arr2[],int n)
{
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);

    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans += abs(arr1[i]-arr2[i]);
    }
    return ans;

}









int main()
{
    int a[] = {4, 1, 8, 7};
    int b[] = {2, 3, 6, 5};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d\n", MinDiff(a,b,n));
    return 0;
}
