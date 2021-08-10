// https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray

//Variant of kadane algo


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minSubarraySum(int arr[], int n){
    int min_sum = arr[0];
    int curr_sum = arr[0];
    for(int i = 1;i<n;i++)
    {
        if(curr_sum <= 0)
        {
            curr_sum += arr[i];
        }
        else
        {
            curr_sum = arr[i];
        }
        
        min_sum = min(min_sum,curr_sum);
    }
    return min_sum;
    
} 
int main()
{
    int arr[] = {2,6,8,1,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: " << minSubarraySum(arr, n);
    return 0;
}
