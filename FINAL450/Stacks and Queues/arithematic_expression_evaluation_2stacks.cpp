// ARITHEMATIC EXPRESSION EVALUATION (STACKS)

// Using 2 stack approach, one for operands and operators and iterate

#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


int Compute(int val1,int val2,char op)
{
    if(op == '+')
    {
        return val1+val2;
    }
    else if(op == '-')
    {
        return val1-val2;
    }
    else if(op == '*')
    {
        return val1*val2;
    }
    else if(op == '/')
    {
        return val1/val2;
    }

}

int EvalExp(string s)
{
    stack<int> operand;
    stack<char> operators;
    unordered_map<char,int> precedence = {{'*',2},{'/',2},{'+',1},{'-',1}};
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            operand.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(operand.top() != '(')
            {
                char op = operand.top();
                operand.pop();
                int val2 = operators.top();
                operators.pop();
                int val1 = operators.top();
                operators.pop();
                int val3 = Compute(val1,val2,op);
                operators.push(val3);

            }
            operand.pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            while(operand.size() != 0 && precedence[s[i]] <= precedence[operand.top()] && operand.top() != '(')
            {
                char op = operand.top();
                operand.pop();
                int val2 = operators.top();
                operators.pop();
                int val1 = operators.top();
                operators.pop();
                int val3 = Compute(val1,val2,op);
                operators.push(val3);
            }
            operand.push(s[i]);
        }
        else
        {
            operators.push(s[i]-'0');
        }
    }
    while(operand.size() != 0)
    {
        char op = operand.top();
        operand.pop();
        int val2 = operators.top();
        operators.pop();
        int val1 = operators.top();
        operators.pop();
        int val3 = Compute(val1,val2,op);
        operators.push(val3);
    }
    int ans = operators.top();
    return ans;
}




int main()
{
    string s = "1+(9*3-6/2)+5";
    cout << EvalExp(s) << endl;
    return 0;
}
