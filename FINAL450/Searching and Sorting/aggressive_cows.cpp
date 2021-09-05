// https://www.spoj.com/problems/AGGRCOW/


#include<bits/stdc++.h>
using namespace std;

bool isPossToAcc(vector<int> arr,int C,int x)
{
    C--;
    int prev = arr[0];
    for(int i = 1;i<arr.size();i++)
    {
        if(C <= 0)
        {
            break;
        }
        else if(arr[i]-prev >= x)
        {
            C--;
            prev = arr[i];
        }
        else
        {
            continue;
        }
    }
    if(C > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int MinDistBwCows(vector<int> arr,int C,int N)
{
    int ans = -1;
    int lo = 0;
    int hi = arr[N-1];
    while(lo <= hi)
    {
        int mid = lo+ (hi-lo)/2;
        bool check = isPossToAcc(arr,C,mid);
        if(check == true)
        {
            ans = mid;
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N,C;
        cin >> N >> C;
        vector<int> pos(N);
        for(int i = 0;i<N;i++)
        {
            cin >> pos[i];
        }
        sort(pos.begin(),pos.end());
        cout << MinDistBwCows(pos,C,N) << endl;

    }
    return 0;
}


