#include<bits/stdc++.h>
using namespace std;

class Item
{
    public:
    string name;
    int price;
    int level;
    Item(string s,int a,int b)
    {
        name = s;
        price = a;
        level = b;
    }
};


bool sortbylevel(Item a,Item b)
{
    if(a.level != b.level)
    {
        return (a.level < b.level);
    }
    else
    {
        return (a.price < b.price);
    }
}

int main()
{
    int m = 2561;
    int l = 3;
    vector<Item> arr = {Item("a",2500,1),Item("b",300,1),Item("d",455000,2),Item("e",3434,2),Item("f",0,2)};
    sort(arr.begin(),arr.end(),sortbylevel);
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i].price < m && arr[i].level < l)
        {
            cout << arr[i].name << " " << arr[i].price << " " << arr[i].level << endl;
        }
        
    }
    return 0;
}
