#include<iostream>
using namespace std;

template <class T1,class T2>
float CompAvg(T1 a,T2 b)
{
    float avg = (a+b)/2.0;
    return avg;
}



int main()
{
    float x = CompAvg(1.22,1e3);
    cout << "AVG IS "  << x << endl;
    return 0;
}
