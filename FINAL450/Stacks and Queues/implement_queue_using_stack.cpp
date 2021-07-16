// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1#

// Using 2 stacks , stack 1 to push and to push use stack2 to store and again push stack1 after popping top ele

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.size() == 0)
    {
        return -1;
    }
    while(s1.size() != 0)
    {
        s2.push(s1.top());
        s1.pop();
    }
    int ans = s2.top();
    s2.pop();
    while(s2.size() != 0)
    {
        s1.push(s2.top());
        s2.pop();
    }
    return ans;
}

