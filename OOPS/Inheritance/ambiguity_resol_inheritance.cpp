#include<iostream>
using namespace std;

class Base1
{
    public:
        void greet()
        {
            cout << "This is base1" << endl;
        }
};

class Base2
{
    public:
        void greet()
        {
            cout << "This is base2" << endl;
        }
};


class Derived : public Base1 , public Base2
{
    public:
    // In this way we resolve the ambiguity ..
    void greet()
    {
        //Base1::greet();
        Base2::greet();
    }
};
int main()
{
    //code goes here
    Derived d;
    d.greet();
    return 0;
}
