#include<iostream>
using namespace std;

template <class T1 = int , class T2 = float , class T3 = char>
class MyClass
{
    public:
        T1 a;
        T2 b;
        T3 c;
        MyClass(T1 x,T2 y,T3 z)
        {
            a = x;
            b = y;
            c = z;
        }

        void display()
        {
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
        }

};



int main()
{
    // default specification
    MyClass <> t(1,1.1,'a');
    t.display();
    cout << endl;
    
    MyClass <float,double,int> t1(1.1,1.34,1);
    t1.display();
    return 0;
}
