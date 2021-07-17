// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

// using recursion with some counter to check number of elements to be reveresed

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
void reverseKelem(queue<int> &q,int k,int a)
{
    if(a>0)
    {
        int temp = q.front();
        q.pop();
        reverseKelem(q,k,a-1);
        q.push(temp);
    }
}



queue<int> modifyQueue(queue<int> q, int k)
{
    reverseKelem(q,k,k);
    int l = q.size()-k;
    while(l>0)
    {
        q.push(q.front());
        q.pop();
        l--;
    }
    return q;
}
