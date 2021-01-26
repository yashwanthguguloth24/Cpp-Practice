#include <iostream>
using namespace std;


void bitWiseOperation(int a, int b, int c){
    cout << "output:" << endl;
    cout << (a^a) << endl;
    cout << (c^b) << endl;
    cout << (a&b) << endl;
    cout << (c|(a^a)) << endl;
    cout << (~(c^b)) << endl;  
}

int main()
{

    int a,b,c;
    cin >> a >> b >> c;
    bitWiseOperation(a,b,c);

}