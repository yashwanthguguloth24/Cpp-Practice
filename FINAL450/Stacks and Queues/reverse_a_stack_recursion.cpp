// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

// similar to sort stack using approach

#include<iostream>
#include<stack>
using namespace std;


void PrintStk(stack<int> s)
{
    while(s.size() != 0)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}
void InsertAtBottom(stack<int> &s,int x)
{
    if(s.size() == 0)
    {
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    InsertAtBottom(s,x);
    s.push(t);
}


void reverseStack(stack<int> &s)
{
    if(s.size() != 0)
    {
        int temp = s.top();
        s.pop();
        reverseStack(s);
        InsertAtBottom(s,temp);        
    }
}


int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    PrintStk(stk);
    reverseStack(stk);
    PrintStk(stk);
    return 0;
}
