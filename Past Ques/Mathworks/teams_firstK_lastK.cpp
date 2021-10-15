#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int s = 3;
    int k = 4;
    vector<int> arr = {17,12,10,2,7,2,11,20,8};
    int n = arr.size();
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    int i = 0;
    int j = n-1;
    int cntr = 0;
    while(i < n && j > 0 && i <= j)
    {
        if(i == j)
        {
            pq1.push(arr[i]);
            i++;
        }
        else
        {
            pq1.push(arr[i]);
            pq2.push(arr[j]);
            i++;
            j--;           
        }
        cntr++;
        if(cntr == k)
        {
            break;
        }
    }
    int sm = 0;
    while(s)
    {
        int tp1,tp2;
        if(pq1.size() > 0)
        {
            tp1 = pq1.top();
        }
        else
        {
            tp1 = -1;
        }

        if(pq2.size() > 0)
        {
            tp2 = pq2.top();
        }
        else
        {
            tp2 = -1;
        }        
        // cout << tp1 << " " << tp2 << endl;
        if(tp1 >= tp2)
        {
            pq1.pop();
            sm += tp1;
            if(i <= j)
            {
                pq1.push(arr[i]);
                i++;
            }
        }
        else
        {
            pq2.pop();
            sm += tp2;
            if(i <= j)
            {
                pq2.push(arr[j]);
                j--;
            }
        }

        s--;
    }
    cout << sm << endl;
    return 0;
}
