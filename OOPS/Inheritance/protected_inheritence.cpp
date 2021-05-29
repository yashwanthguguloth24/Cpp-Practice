#include<iostream>
using namespace std;

class base
{
    protected: // protected is same as private but can be inherited to derived class
        int a = 0;
    private:
        int b = 0;
    public:
        int c = 0;
        void Display()
        {
            cout << a << " " <<  b << "  " << c << endl;
        }
};


class Derived : protected base
{
    public:
        void mydisp()
        {
            Display();
        }
};

/*
                         public Deriv               private deriv            protected deriv
private mem              Not inherited              Not inherited            Not inherited
protected mem            protected                  private                  protected
public mem               public                     private                  protected


*/
int main()
{
    //code goes here
    Derived d;
    d.mydisp();
    // we cannot access d.a , d.b , d.c because we are inherting only protected class
    return 0;
}
