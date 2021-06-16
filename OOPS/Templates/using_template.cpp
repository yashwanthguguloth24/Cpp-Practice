#include<iostream>
using namespace std;
template <class T>
class Vector
{
    public:
        T* arr;
        int size;
        Vector(int a)
        {
            size = a;
            arr = new T[size];
        }

        T dotProduct(Vector &v1)
        {
            T s = 0;
            for(int i = 0;i<size;i++)
            {
                s += this->arr[i]*v1.arr[i];
            }
            return s;
        }
        
};

int main()
{
    Vector <double> v(3);
    v.arr[0] = 1.1;
    v.arr[1] = 2.2;
    v.arr[2] = 3.3;
    Vector <double> v1(3);
    v1.arr[0] = 0.1;
    v1.arr[1] = 0.2;
    v1.arr[2] = 0.3; 
    cout << v.dotProduct(v1) << endl;  
    return 0;
}
