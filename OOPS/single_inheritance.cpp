#include<iostream>
using namespace std;
 
class Base
{
    int data1; // private member
    public:
        int data2;
        void setData();
        int getData1();
        int getData2();
};

void Base :: setData()
{
    data1 = 5;
    data2 = 4;
}

int Base :: getData1()
{
    return data1;
}

int Base :: getData2()
{
    return data2;
}

// derived class inherits from base class
// public implies that it inherits public data from base class to public data of derived class
class Derived : public Base
{
    public:
        int data3;
        void display();
        void setData3();
};

void Derived :: display()
{
    cout << "data1 is " << getData1() << endl;
    cout << "data2 is " << data2 << endl;
    cout << "data3 is " << data3 << endl; 
}


void Derived :: setData3()
{
    data3 = data2 * getData1();
}

int main()
{
    Derived drvd;
    drvd.setData();
    drvd.setData3();
    drvd.display();
    return 0;
}

