#include<bits/stdc++.h>
using namespace std;


bool isallsame(string s)
{
    char c = s[0];
    for(int i = 1;i<s.length();i++)
    {
        if(s[i] != c)
        {
            return false;
        }
    }
    return true;
}

bool isNumeric(string s)
{
    for(int i = 0;i<s.length();i++)
    {
        if(isdigit(s[i]) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if(s.size() == 4)
    {
        if(isNumeric(s) == true && isallsame(s) == false)
        {
            cout << "Accepted" << endl;
        }
        else
        {
            cout << "Rejected" << endl;
        }
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}
