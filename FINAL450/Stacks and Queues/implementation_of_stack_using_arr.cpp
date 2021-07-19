// https://www.tutorialspoint.com/javaexamples/data_stack.htm

// Basic stack implementation using array

#include<iostream>
using namespace std;

class MyStack
{
    public:
    int max_size;
    int top;
    int *arr;
    MyStack(int cap)
    {
        max_size = cap;
        top = -1;
        arr = new int[max_size];
    }

    void push(int x)
    {
        if(top == max_size-1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            return ;
        }
        int res = arr[top];
        top--;
        cout << "popped element :" << res << endl;
    }

};




int main()
{
    MyStack stk(5);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.pop();
    stk.pop();
    stk.pop();
    return 0;
}
