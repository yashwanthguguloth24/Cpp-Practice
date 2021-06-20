// https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings


// https://www.youtube.com/watch?v=qN_vwYtvFUM


// Using 3 pointer method to check at every stage.

#include<iostream>
using namespace std;

bool isValidShuffle(string s1,string s2,string s3)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    if((l1+l2) != l3)
    {
        return false;
    }
    else
    {
        int i = 0;
        int j = 0;
        int k = 0;
        while(k<l3)
        {
            if(i < l1 && s1[i] == s3[k])
            {
                i++;
            }
            else if(j<l2 && s2[j] == s3[k])
            {
                j++;
            }
            else
            {
                break;
            }
            k++;
        }
        if(i<l1 or j<l2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}



int main()
{
    string s1 = "xy";
    string s2 = "12";
    string s3 = "x1y2";
    bool flag = isValidShuffle(s1,s2,s3);
    if(flag)
    {
        cout << "Valid shuffle" << endl;
    }
    else
    {
        cout << "Not a Valid shuffle" << endl;
    }
    return 0;
}
