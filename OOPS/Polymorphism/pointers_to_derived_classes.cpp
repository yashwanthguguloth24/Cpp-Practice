#include<iostream>
using namespace std;

class Base
{
    public:
        int baseVar;
        void display()
        {
            cout << "Displaying base class variable " << baseVar << endl; 
        }
};


class Derived : public Base
{
    public:
        int derivedVar;
        void display()
        {
            cout << "Displaying derived class variable " << derivedVar << endl; 
        }
};



int main()
{
    Base* base_cls_ptr;
    Derived *derived_cls_ptr;

    Base baseObj;
    Derived derivedObj;
    // RUN TIME POLYMORPHISM
    // case1 : base class ptr pointing to derived object
    // it can acess only base member variables and funcs
    base_cls_ptr = &derivedObj;
    base_cls_ptr->baseVar = 10;
    base_cls_ptr->display();
    
    // case2: derived class ptr pointing to derived object
    // it will access derived members functions
    derived_cls_ptr = &derivedObj;
    derived_cls_ptr->baseVar = 99;
    derived_cls_ptr->derivedVar = 20;
    derived_cls_ptr->display();
    base_cls_ptr->display();

    return 0;
}
