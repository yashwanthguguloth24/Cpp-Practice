#include<iostream>
using namespace std;

// creating array of objects using pointers
class Shop
{
    int id;
    float price;
    public:
        void setData(int a,float b)
        {
            id = a;
            price = b;
        }

        void getData()
        {
            cout << "id : " << id << endl;
            cout << "price : " << price << endl; 
        }
};



int main()
{
    // creating array of objects using pointers
    int size = 3;
    Shop* ptr = new Shop[size];
    Shop* temp = ptr;
    int a;
    float b;
    for(int i = 1;i<=size;i++)
    {
        cout << "Enter " << i << "th item id and price" << endl;
        cin >> a >> b;
        ptr->setData(a,b);
        ptr++;
    }
    for(int i = 1;i<=size;i++)
    {
        temp->getData();
        temp++;
    }
    return 0;
}
