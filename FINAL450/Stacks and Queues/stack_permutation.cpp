// https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/

// using stack to push and pop when equal


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool isValidStackPermuatation(int inp[],int op[],int n)
{
    queue<int> input;
    queue<int> output;
    for(int i = 0;i<n;i++)
    {
        input.push(inp[i]);
        output.push(op[i]);
    }
    stack<int> tempstk;
    while(input.size() != 0)
    {
        int ele = input.front();
        input.pop();
        if(ele == output.front())
        {
            output.pop();
            while(tempstk.size() != 0)
            {
                if(tempstk.top() == output.front())
                {
                    output.pop();
                    tempstk.pop();
                }
                else
                {
                    break;
                } 
            }
        }
        else
        {
            tempstk.push(ele);
        }
    }
    return (input.empty() && tempstk.empty());
}


int main()
{
    int inp[] = {1,2,3};
    int op[] = {3,2,1};
    cout << isValidStackPermuatation(inp,op,3) << endl;
    return 0;
}
