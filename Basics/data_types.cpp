#include <iostream>cpp
using namespace std;



void dataTypes(int a, float b, double c, long long l,string d){
    
    float p = b/c ; //do b/c
    
    double q = b/a  ; //do b/a
    
    int r = (int)c/a ; // do c/a
    
    long long m = r+l;//do r+l
    
    cout << p << " " << q << " " << r <<" "<< m <<endl;
    
    cout << d << " " << d[3] << endl;//write 3 for index

}

int main()
{
    int a;
    float b;
    double c;
    long long l;
    string d;

    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> l >> d;
        dataTypes(a,b,c,l,d);
    }
    return 0;
    

}