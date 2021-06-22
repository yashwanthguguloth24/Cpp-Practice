#include<iostream>
#include<list>
using namespace std;

void Display(list<int> &l)
{
    list<int> :: iterator it;
    for(it = l.begin();it != l.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    for(int i = 0;i<5;i++)
    {
        l1.push_back(i);
    }
    Display(l1);
    l1.remove(3);
    Display(l1);
    l1.sort(greater<int>()); // sort in descending order
    Display(l1);
    // pop_back,pop_front,merge can also be done
    return 0;
}
