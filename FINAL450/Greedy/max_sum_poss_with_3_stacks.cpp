// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

// Greedly remove top element of the stack with largest sum.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxSum(int stk1[],int stk2[],int stk3[],int n1,int n2,int n3)
{
    int sum1 = 0;
    int sum2 = 0; 
    int sum3 = 0;
    for(int i = 0;i<n1;i++)
    {
        sum1 += stk1[i];
    }
    for(int i = 0;i<n2;i++)
    {
        sum2 += stk2[i];
    }
    for(int i = 0;i<n3;i++)
    {
        sum3 += stk3[i];
    }

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    while(true)
    {
        if(top1 == n1 || top2 == n2 || top3 == n3)
        {
            return 0;
        }

        if(sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }

        if(sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 = sum1 - stk1[top1++];
        }
        else if(sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 = sum2 - stk2[top2++];
        }
        else if(sum3 >= sum1 && sum3 >= sum2)
        {
            sum3 = sum3 - stk3[top3++];
        }
    }

}




int main()
{
    int stack1[] = { 3, 2, 1, 1, 1 };
    int stack2[] = { 4, 3, 2 };
    int stack3[] = { 1, 1, 4, 1 };
 
    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);

    cout << MaxSum(stack1,stack2,stack3,n1,n2,n3) << endl;
 
    return 0;
}
