#include<iostream>
using namespace std;

// member function templates
template <class T>
class Test
{
    public:
        T data;
        Test(T x)
        {
            data = x;
        }
        void display();
};

template <class T>
void Test<T> :: display()
{
    cout << data << endl;
}

// overloading

void myFunc(int a)
{
    cout << "Normal func is called , value is " << a << endl;
}

template <class T>
void myFunc(T x)
{
    cout << "Templatised func is called , value is " << x << endl;
}

int main()
{
    Test<float> t(1.34);
    t.display();
    // Exact match takes the highest priority
    //myFunc(99);
    myFunc(1.11);
    return 0;
}
