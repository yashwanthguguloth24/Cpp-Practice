/*

You are given an array of N integers. Given that you have to pick a non-empty subsequence, 
what is the probability that you pick a subsequence which has the same value of bitwise and, or and xor?

*/





// #include<bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> arr = {1, 3, 7};
    int n = arr.size();
    map<int,int> mp;
    for(int i = 0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    int ans = 0;
    for(auto x:mp)
    {
        if(x.first == 0)
        {
            ans += pow(2,x.second)-1;
        }
        else
        {
            ans += pow(2,x.second-1);
        }
    }
    cout << ans << endl;
    return 0;
}
