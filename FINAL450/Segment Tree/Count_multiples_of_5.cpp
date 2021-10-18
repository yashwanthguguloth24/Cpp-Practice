#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void buildST(vector<int> arr,vector<int> &sgt,int st,int end,int np)
{
    if(st == end)
    {
        if(arr[st]%5 == 0)
        {
            sgnt[np] = 1;
        }
        else
        {
            sgt[np] = 0;
        }
        return;
    }
    
    int mid = (st+end)/2;
    buildST(arr,sgt,st,mid-1,2*np+1);
    buildST(arr,sgt,mid+1,end,2*np+2);
    sgt[np] = sgt[2*np+1]+sgt[2*np+2];
}

int countNum(vector<int> arr,vector<int> sgt,int l,int r,int ql,int qr,int np)
{
    if(ql <= l && qr >= r)
    {
        return sgt[np];
    }
    
    if(r < ql || l > qr)
    {
        return 0;
    }
    int mid = (l+r)/2;
    return (countNum(arr,sgt,l,mid,ql,qr,2*np+1)+countNum(arr,sgt,mid+1,r,ql,qr,2*np+2));
}



int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,q;
	    cin >> n >> q;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    vector<int> sgt(4*n,0);
	    buildST(arr,sgt,0,n-1,0);
	    for(int i = 0;i<q;i++)
	    {
	        int ql,qr;
	        cin >> ql >> qr;
	        cout << countNum(arr,sgt,0,n-1,ql,qr,0);
	        
	    }
	    cout << endl;
	}
	return 0;
}
