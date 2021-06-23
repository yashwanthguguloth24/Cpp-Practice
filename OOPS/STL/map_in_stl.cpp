#include<iostream>
#include<map>
#include<string>
using namespace std;
 
int main()
{
    map<string,int> MyMap;
    MyMap["apple"] = 3;
    MyMap["banana"] = 5;
    MyMap.insert({{"orange",10},{"kiwi",99}});

    map<string,int> :: iterator iter;
    for(iter = MyMap.begin();iter != MyMap.end();iter++)
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    return 0;
}
