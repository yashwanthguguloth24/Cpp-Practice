#include<iostream>
#include<vector>
using namespace std;

template <class T>
void Display(vector<T> &v)
{
    for(int i = 0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}



int main()
{
    vector <int> v1;
    int size = 3;
    for(int i = 0;i<size;i++)
    {
        v1.push_back(i);
    }
    Display(v1);

    // iterator to a vector
    vector<int> :: iterator iter = v1.begin();
    v1.insert(iter+1,11);
    Display(v1);

    // different ways to initialise
    vector <int> v2;
    vector <int> v3(10);
    vector <int> v4(v3);
    vector <int> v5(6,111);
    Display(v5);
    return 0;
}
