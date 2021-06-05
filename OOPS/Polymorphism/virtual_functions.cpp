#include<iostream>
using namespace std;

// HERE RUN TIME POLYMORPHISM IS ACHIEVED 
// keyword virtual is added to base function to resolve the earlier behaviour of selecting default base class functions 
class Base
{
    public:
        int baseVar;
        void virtual display()
        {
            cout << "1 Displaying base class variable " << baseVar << endl; 
        }
};


class Derived : public Base
{
    public:
        int derivedVar;
        void display()
        {
            cout << "2 Displaying base class variable " << baseVar << endl; 
            cout << "2 Displaying derived class variable " << derivedVar << endl; 
        }
};



int main()
{
    Base* base_cls_ptr;
    Derived *derived_cls_ptr;

    Base baseObj;
    Derived derivedObj;
    // RUN TIME POLYMORPHISM is achieved
    // case1 : base class ptr pointing to derived object
    // now it can acess only derived member funcs
    base_cls_ptr = &derivedObj;
    base_cls_ptr->baseVar = 10;
    base_cls_ptr->display();
    

    return 0;
}
