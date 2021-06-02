#include<iostream>
using namespace std;

class Base1
{
    protected:
        int base1;
    public:
        void setbase1(int a)
        {
            base1 = a;
        }
};

class Base2
{
    protected:
        int base2;
    public:
        void setbase2(int a)
        {
            base2 = a;
        }
};

class Derived : public Base1, public Base2
{
    protected:
        int base3;
    public:

        void show()
        {
            base3 = base1+base2;
            cout << "base1 is " << base1 << endl;
            cout << "base2 is " << base2 << endl;
            cout << "base3 is " << base3 << endl;
        }
};

/*
The derived class has the following
protected: base1,base2,base3
public:
setbase1()
setbase2()
show()



*/

int main()
{
    //code goes here
    Derived a;
    a.setbase1(11);
    a.setbase2(12);
    a.show();
    return 0;
}
