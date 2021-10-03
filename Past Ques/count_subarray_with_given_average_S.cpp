/*
ou are given an array A of N integers and an integer S. 
Your task is to compute how many ways one can choose a contiguous fragment of A such that arithmetic mean is equal to S.

*/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n = 10;
    int s = 6;
    vector<int> arr = {12, 5, 3, 10, 4, 8, 10, 12, -6, -1};
    vector<int> presum(n,0);
    presum[0] = arr[0];
    for(int i = 1;i<n;i++)
    {
        presum[i] = arr[i]+presum[i-1];
    }
    int ans = 0;
    unordered_map<int,int> store;
    int temp = 0;
    for(int i = 0;i<n;i++)
    {
        temp = presum[i]-(i*s);
        if(store.find(temp) != store.end())
        {
            ans += store[temp];
        }
        store[temp]++;
    }
    cout << ans << endl;

    return 0;
}
