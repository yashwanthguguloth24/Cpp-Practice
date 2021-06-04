#include<iostream>
using namespace std;

/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/


class Base1
{
    int data1;
    public:
        Base1(int a)
        {
            data1 = a;
            cout<<"Base1 class constructor called"<<endl;
        }
        void printDataBase1(void){
            cout<<"The value of data1 is "<<data1<<endl;
        }
      
};

class Base2
{
    int data2;
    public:
        Base2(int a)
        {
            data2 = a;
            cout<<"Base2 class constructor called"<<endl;
        }
        void printDataBase2(void){
            cout << "The value of data2 is " << data2 << endl;
        }      
};

class Derived : public Base2, public Base1
{
    int derived1,derived2;
    public:
    Derived(int a,int b,int c,int d) : Base2(a) , Base1(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }
    void printDataDerived(void)
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};

int main()
{
    //code goes here
    Derived d1(1,2,3,4);
    d1.printDataBase1();
    d1.printDataBase2();
    d1.printDataDerived();
    return 0;
}
