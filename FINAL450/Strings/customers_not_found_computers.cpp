// https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/

// Using set to keep track of users and variable to keep tracks of occupancy.

#include<iostream>
#include<set>
using namespace std;

int NumCustomersLeft(string s,int capacity)
{
    int NumCompFilled = 0;
    set <char> Users;
    int NumLeft = 0;
    for(int i = 0;i<s.length();i++)
    {
        if(NumCompFilled < capacity)
        {
            if(Users.count(s[i]) == 0)
            {
                Users.insert(s[i]);
                NumCompFilled++;
            }
            else
            {
                Users.erase(s[i]);
                NumCompFilled--;
            }
        }
        else
        {
            if(Users.count(s[i]) == 0)
            {
                NumLeft++;
            }
            else
            {
                Users.erase(s[i]);
                NumCompFilled--;
            }
        }
    }
    return (NumLeft/2);
}


int main()
{
    // string s = "ABCDDCBEFFEGAG";
    // int num = 2;
    // cout << NumCustomersLeft(s,num) << endl;
    cout << NumCustomersLeft("ABBAJJKZKZ",2) << endl;
    cout << NumCustomersLeft("GACCBDDBAGEE",3) << endl;
    cout << NumCustomersLeft("GACCBGDDBAEE",3) << endl;
    cout << NumCustomersLeft("ABCBCA",1) << endl;
    cout << NumCustomersLeft("ABCBCADEED",1) << endl;
    return 0;
}
