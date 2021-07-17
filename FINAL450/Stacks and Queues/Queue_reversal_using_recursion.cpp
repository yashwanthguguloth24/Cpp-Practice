// https://practice.geeksforgeeks.org/problems/queue-reversal/1#

// Used recursion to keep dequeuing and then enqueueing 


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
void reverse(queue<int> &q)
{
    if(q.size() != 0)
    {
        int temp = q.front();
        q.pop();
        reverse(q);
        q.push(temp);
    }
    return;
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}
