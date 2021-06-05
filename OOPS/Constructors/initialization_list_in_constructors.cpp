#include<iostream>
using namespace std;

/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}

class Test{
    int a;
    int b;
    public:
        Test(int i, int j) : a(i), b(j){constructor-body}
};

*/

class Test
{
    int a;
    int b;
    public:
        Test(int i,int j) : a(i),b(j+a)
        {
            cout << "Constructor is called" << endl;
            cout << "a :" << a << endl;
            cout << "b :" << b << endl;
        }
};


int main()
{
    //code goes here
    Test t(3,4);
    return 0;
}
