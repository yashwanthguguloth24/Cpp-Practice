#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> scores,int k,int teamsize)
{
    int n = scores.size();
    cout << n << endl;
    int i = 0;
    int j = n-1;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    while(i < n && i < k)
    {
        pq1.push(scores[i]);
        i++;
    }
    i--;

    while(j > 0 && j > i && j >= n-k)
    {
        pq2.push(scores[j]);
        j--;
    }
    j++;

    int sz = 0;
    int ans = 0;
    // cout << i << " " << j << endl;
    for(int t = 0;t<teamsize;t++)
    {
        int val1 = INT_MIN;
        int val2 = INT_MIN;
        if(pq1.size() > 0)
        {
            val1 = pq1.top();
        }

        if(pq2.size() > 0)
        {
            val2 = pq2.top();
        }
        // cout << max(val1,val2) << endl;
        if(val1 >= val2)
        {
            ans += val1;
            pq1.pop();
            if(i < n && i+1 < j)
            {
                i++;
                pq1.push(scores[i]);
            }
        }
        else
        {
            ans += val2;
            pq2.pop();
            if(j > 0 && j-1 > i)
            {
                j--;
                pq2.push(scores[j]);
            }
        }
        // cout << val1 << " " << val2 << endl;
        // cout << i << " " << j << endl;
    }


    return ans;

}


int main()
{
    vector<int> scores = {18,5,15,18,11,15,9,7};
    int k = 1;
    int teamsize = 5;
    cout << solve(scores,k,teamsize) << endl;
    return 0;
}
