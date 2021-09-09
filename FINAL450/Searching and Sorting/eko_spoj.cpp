// https://www.spoj.com/problems/EKO/

// using binary search for heights

#include<bits/stdc++.h>
using namespace std;
#define int long long

int compDiff(vector<int>arr,int h)
{
    int ans = 0;
    for(int i = 0;i<arr.size();i++)
    {
        ans += (arr[i]>h)?(arr[i]-h):0;
    }
    return ans;
}

int32_t main()
{
    int N,M;
    cin >> N >> M;
    vector<int> arr(N);
    int max_ele = INT_MIN;
    for(int i = 0;i<N;i++)
    {
        cin >> arr[i];
        max_ele = max(max_ele,arr[i]);
    }
    int l = 0;
    int r = max_ele;
    int ans = 0;
    while(l<=r)
    {
        // cout << l << " " << r << endl;
        int mid = l + (r-l)/2;
        int rem = compDiff(arr,mid);
        if(rem >= M)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << ans << endl;


    return 0;
}
