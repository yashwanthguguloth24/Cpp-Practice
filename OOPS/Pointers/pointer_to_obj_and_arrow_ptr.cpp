#include<iostream>
using namespace std;


class Complex
{
    int real,imag;
    public:
        Complex(int a, int b) : real(a),imag(b){
        }
        void getData()
        {
            cout << real << "+" << imag << "*j" << endl;
        }

};


 
int main()
{
    //code goes here
    Complex c1(3,4);
    c1.getData();

    // Using ptrs creating new object
    Complex *ptr = new Complex(10,20);

    // acessing class members using ptr using arrow.
    ptr->getData();

    return 0;
}
