#include<iostream>
using namespace std;


template <class T1,class T2>
class myClass
{
    T1 var1;
    T2 var2;
    public:
        myClass(T1 a,T2 b)
        {
            var1 = a;
            var2 = b;
        }

        void Display()
        {
            cout << this->var1 << " " << this->var2 << endl;
        }
};


int main()
{
    //code goes here
    myClass <int,char> test(1,'Q');
    test.Display();
    return 0;
}
