// https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

// Using Min heap,create contig sum array then first k sums and then check with top to pop or not accordingly


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int KthLargestSum(int arr[],int n,int k)
{
    // solving using minheap
    // conting subarray
    int sum[n+1];
    sum[0] = 0;
    sum[1] = arr[0];
    for(int i = 2;i<=n;i++)
    {
        sum[i] = sum[i-1]+arr[i-1];
    }

    priority_queue<int, vector<int>, greater<int> > Q; //min heap

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;i<=n;i++)
        {
            int x = sum[j]-sum[i-1];

            if(Q.size() < k)
            {
                Q.push(x);
            }
            else
            {
                if(x>Q.top())
                {
                    Q.pop();
                    Q.push(x);
                }
            }

        }
    }

    return Q.top();

}





int main()
{
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
 
    // calls the function to find out the
    // k-th largest sum
    cout << KthLargestSum(a,n,k);
    return 0;    

}
