#include<iostream>
#include<cmath>
using namespace std;

class SimpleCalculator
{
    int op1,op2;
    public:
        void getDataSimple()
        {
            cout << "enter 2 nums" << endl;
            cin >> op1;
            cin >> op2;
        }

        void SimpleOperations()
        {
            cout << "Mul :" << op1*op2 << endl;
            cout << "Add :" << op1+op2 << endl;
            cout << "Div :" << op1/op2<< endl;
            cout << "Sub :" << op1-op2<< endl;
        }
};


class ComplexCalculator
{
    int op1,op2;
    public:
        void getDataScientific()
        {
            cout << "enter 2 nums" << endl;
            cin >> op1;
            cin >> op2;
        }

        void ComplexOperations()
        {
            cout << "power :" << pow(op1,op2)<< endl;
            cout << "cos :" << cos(op1)<< endl;
            cout << "sin :" << sin(op1)<< endl;
            cout << "exp :" << exp(op1)<< endl;
        }    

};

class HybridCalculator : public ComplexCalculator,public SimpleCalculator
{

};

int main()
{
    //code goes here
    HybridCalculator h;
    h.getDataSimple();
    h.SimpleOperations();
    h.getDataScientific();
    h.ComplexOperations();
    return 0;
}
