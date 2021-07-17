// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

// Store negative elements in queue and slide window to check whether to remove any neg element or not , else push to answer

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    vector<long long> ans;
    queue<long long int> q;
    //start window
    for(long long int i = 0;i<K;i++)
    {
        if(A[i] < 0)
        {
            q.push(A[i]);
        }
    }
    if(q.size() != 0)
    {
        ans.push_back(q.front());
    }
    else
    {
        ans.push_back(0);
    }
    long long int j = 0;
    for(long long int i = K;i<N;i++)
    {
        // remove if edge element is present queue as your updating window
        if(q.size() != 0 && A[j] == q.front())
        {
            q.pop();
        }
        j++;
        
        if(A[i] < 0)
        {
            q.push(A[i]);
        }
        
        if(q.size() != 0)
        {
            ans.push_back(q.front());
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
                                                 
                                                 

